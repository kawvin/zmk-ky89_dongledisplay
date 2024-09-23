/*
 * Copyright (c) 2022 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/kernel.h>

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/display.h>
#include <zmk/display/widgets/peripheral_status.h>
#include <zmk/event_manager.h>
#include <zmk/split/bluetooth/peripheral.h>
#include <zmk/events/split_peripheral_status_changed.h>


LV_IMG_DECLARE(disconnect_icon);

static sys_slist_t widgets = SYS_SLIST_STATIC_INIT(&widgets);

static lv_color_t connect_image_buffer[ZMK_SPLIT_BLE_PERIPHERAL_COUNT + 1][14 * 9];


struct peripheral_status_state {
    bool connected;
    uint8_t source;
};

static struct peripheral_status_state get_state(const zmk_event_t *_eh) {
    return (struct peripheral_status_state){.connected = zmk_split_bt_peripheral_is_connected()};
}

// static void set_status_symbol(lv_obj_t *label, struct peripheral_status_state state) {
//     const char *text =
//         state.connected ? (LV_SYMBOL_WIFI " " LV_SYMBOL_OK) : (LV_SYMBOL_WIFI " " LV_SYMBOL_CLOSE);

//     LOG_DBG("connected? %s", state.connected ? "true" : "false");
//     lv_label_set_text(label, text);
// }

static void set_status_symbol(lv_obj_t *label, struct peripheral_status_state state) {
    lv_obj_t *symbol = lv_obj_get_child(widget, state.source );
    // lv_obj_clear_flag(symbol, LV_OBJ_FLAG_HIDDEN);
    state.connected ? (lv_obj_clear_flag(symbol, LV_OBJ_FLAG_HIDDEN)) : (lv_obj_add_flag(symbol, LV_OBJ_FLAG_HIDDEN));
}


// static struct peripheral_status_state get_state(const zmk_event_t *_eh) {
//     return (struct peripheral_status_state){.connected = zmk_split_bt_peripheral_is_connected()};
// }


        
static struct peripheral_status_state get_state(const zmk_event_t *_eh) {
    const struct zmk_peripheral_battery_state_changed *ev = as_zmk_peripheral_battery_state_changed(_eh);
    return (struct peripheral_status_state){
        .source = ev->source + 1,
        .connected = zmk_split_bt_peripheral_is_connected(),
    };
}
static void output_status_update_cb(struct peripheral_status_state state) {
    struct zmk_widget_peripheral_status *widget;
    SYS_SLIST_FOR_EACH_CONTAINER(&widgets, widget, node) { set_status_symbol(widget->obj, state); }
}

ZMK_DISPLAY_WIDGET_LISTENER(widget_peripheral_status, struct peripheral_status_state,
                            output_status_update_cb, get_state)
ZMK_SUBSCRIPTION(widget_peripheral_status, zmk_split_peripheral_status_changed);

int zmk_widget_peripheral_status_init(struct zmk_widget_peripheral_status *widget,
                                      lv_obj_t *parent) {
    widget->obj = lv_label_create(parent);
    lv_obj_set_size(widget->obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);

    // for (int i =0; i< ZMK_SPLIT_BLE_PERIPHERAL_COUNT + SOURCE_OFFSET; i++) {  
    for (int i =1; i< ZMK_SPLIT_BLE_PERIPHERAL_COUNT + 1; i++) {  
        lv_obj_t *image_canvas = lv_canvas_create(widget->obj);
        // lv_obj_t *battery_label = lv_label_create(widget->obj);

        lv_canvas_set_buffer(image_canvas, connect_image_buffer[i], 14, 9, LV_IMG_CF_TRUE_COLOR);
        lv_obj_align(image_canvas, LV_ALIGN_TOP_LEFT, i*14+2, 0);
        lv_img_set_src(image_canvas, &disconnect_icon);
        lv_obj_add_flag(image_canvas, LV_OBJ_FLAG_HIDDEN);
    }
    sys_slist_append(&widgets, &widget->node);

    widget_peripheral_status_init();
    return 0;
}

lv_obj_t *zmk_widget_peripheral_status_obj(struct zmk_widget_peripheral_status *widget) {
    return widget->obj;
}
