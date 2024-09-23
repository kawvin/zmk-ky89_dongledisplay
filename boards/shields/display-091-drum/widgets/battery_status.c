/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/kernel.h>
#include <zephyr/bluetooth/services/bas.h>

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/display.h>
#include <zmk/display/widgets/battery_status.h>
#include <zmk/usb.h>
#include <zmk/ble.h>
#include <zmk/events/usb_conn_state_changed.h>
#include <zmk/event_manager.h>
#include <zmk/events/battery_state_changed.h>
#include <zmk/battery.h>

#include "battery_status.h"


// #if IS_ENABLED(CONFIG_ZMK_IS_DONGLE_MODE)
//     #define SOURCE_OFFSET 1
// #else
//     #define SOURCE_OFFSET 0
// #endif

static sys_slist_t widgets = SYS_SLIST_STATIC_INIT(&widgets);

LV_IMG_DECLARE(battery00_icon);
LV_IMG_DECLARE(battery10_icon);
LV_IMG_DECLARE(battery20_icon);
LV_IMG_DECLARE(battery30_icon);
LV_IMG_DECLARE(battery40_icon);
LV_IMG_DECLARE(battery50_icon);
LV_IMG_DECLARE(battery60_icon);
LV_IMG_DECLARE(battery70_icon);
LV_IMG_DECLARE(battery80_icon);
LV_IMG_DECLARE(battery90_icon);
LV_IMG_DECLARE(batterycharge_icon);
LV_IMG_DECLARE(disconnect_icon);

const lv_img_dsc_t *batterys_level[] = {
    &battery00_icon,
    &battery10_icon,
    &battery20_icon,
    &battery30_icon,
    &battery40_icon,
    &battery50_icon,
    &battery60_icon,
    &battery70_icon,
    &battery80_icon,
    &battery90_icon,
    &batterycharge_icon,
    &disconnect_icon,
};

struct battery_state {
    uint8_t source;
    uint8_t level;
    bool usb_present;
};

// static lv_color_t battery_image_buffer[ZMK_SPLIT_BLE_PERIPHERAL_COUNT + SOURCE_OFFSET][14 * 9];
static lv_color_t battery_image_buffer[ZMK_SPLIT_BLE_PERIPHERAL_COUNT + 1][14 * 9];

static void set_battery_symbol(lv_obj_t *widget, struct battery_state state) {
    lv_obj_t *symbol = lv_obj_get_child(widget, state.source );
    // lv_obj_t *symbol = lv_obj_get_child(widget, state.source * 2);
    // lv_obj_t *label = lv_obj_get_child(widget, state.source * 2 + 1);
    uint8_t level = state.level;
    // lv_obj_clear_flag(symbol, LV_OBJ_FLAG_HIDDEN);
    // lv_obj_clear_flag(label, LV_OBJ_FLAG_HIDDEN);
    // lv_label_set_text_fmt(label, "%4u%%", state.level);
    // lv_label_set_text(label,  state.source * 2);
    if (!state.usb_present) {
        if (level > 95) {
            lv_img_set_src(symbol, batterys_level[9]);
        } else if (level > 85) {
            lv_img_set_src(symbol, batterys_level[8]);
        } else if (level > 75) {
            lv_img_set_src(symbol, batterys_level[7]);
        } else if (level > 65) {
            lv_img_set_src(symbol, batterys_level[6]);
        } else if (level > 55) {
            lv_img_set_src(symbol, batterys_level[5]);
        } else if (level > 45) {
            lv_img_set_src(symbol, batterys_level[4]);
        } else if (level > 35) {
            lv_img_set_src(symbol, batterys_level[3]);
        } else if (level > 25) {
            lv_img_set_src(symbol, batterys_level[2]);
        } else if (level > 15) {
            lv_img_set_src(symbol, batterys_level[1]);
        } else {
            lv_img_set_src(symbol, batterys_level[0]);
        }
    } else {
        lv_img_set_src(symbol, batterys_level[10]);
    }
}

void battery_status_update_cb(struct battery_state state) {
    struct zmk_widget_peripheral_battery_status *widget;
    SYS_SLIST_FOR_EACH_CONTAINER(&widgets, widget, node) { set_battery_symbol(widget->obj, state); }
}


static struct battery_state peripheral_battery_status_get_state(const zmk_event_t *eh) {
    const struct zmk_peripheral_battery_state_changed *ev = as_zmk_peripheral_battery_state_changed(eh);
    return (struct battery_state){
        // .source = ev->source + SOURCE_OFFSET,
        .source = ev->source + 1,
        .level = ev->state_of_charge,
#if IS_ENABLED(CONFIG_USB_DEVICE_STACK)
        .usb_present = zmk_usb_is_powered(),
#endif /* IS_ENABLED(CONFIG_USB_DEVICE_STACK) */
    };
}

static struct battery_state central_battery_status_get_state(const zmk_event_t *eh) {
    const struct zmk_battery_state_changed *ev = as_zmk_battery_state_changed(eh);
    return (struct battery_state) {
        .source = 0,
        .level = (ev != NULL) ? ev->state_of_charge : zmk_battery_state_of_charge(),
#if IS_ENABLED(CONFIG_USB_DEVICE_STACK)
        .usb_present = zmk_usb_is_powered(),
#endif /* IS_ENABLED(CONFIG_USB_DEVICE_STACK) */
    };
}

static struct battery_state battery_status_get_state(const zmk_event_t *eh) { 
    if (as_zmk_peripheral_battery_state_changed(eh) != NULL) {
        return peripheral_battery_status_get_state(eh);
    } else {
        return central_battery_status_get_state(eh);
    }
}

ZMK_DISPLAY_WIDGET_LISTENER(widget_peripheral_battery_status, struct battery_state, 
                            battery_status_update_cb, battery_status_get_state)
ZMK_SUBSCRIPTION(widget_peripheral_battery_status, zmk_peripheral_battery_state_changed);

// 主手电量监控
ZMK_SUBSCRIPTION(widget_peripheral_battery_status, zmk_battery_state_changed);
ZMK_SUBSCRIPTION(widget_peripheral_battery_status, zmk_usb_conn_state_changed);


int zmk_widget_peripheral_battery_status_init(struct zmk_widget_peripheral_battery_status *widget, lv_obj_t *parent) {
    widget->obj = lv_obj_create(parent);

    lv_obj_set_size(widget->obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);

    // for (int i =0; i< ZMK_SPLIT_BLE_PERIPHERAL_COUNT + SOURCE_OFFSET; i++) {  
    for (int i =0; i< ZMK_SPLIT_BLE_PERIPHERAL_COUNT + 1; i++) {  
        lv_obj_t *image_canvas = lv_canvas_create(widget->obj);
        // lv_obj_t *battery_label = lv_label_create(widget->obj);

        lv_canvas_set_buffer(image_canvas, battery_image_buffer[i], 14, 9, LV_IMG_CF_TRUE_COLOR);
        lv_obj_align(image_canvas, LV_ALIGN_TOP_LEFT, i*14+2, 0);
        // lv_obj_align(battery_label, LV_ALIGN_TOP_LEFT, i*14+3, 10);
        
        
        // lv_obj_add_flag(image_canvas, LV_OBJ_FLAG_HIDDEN);
        // lv_obj_add_flag(battery_label, LV_OBJ_FLAG_HIDDEN);

        lv_img_set_src(image_canvas, batterys_level[11]);
    }

    sys_slist_append(&widgets, &widget->node);

    widget_peripheral_battery_status_init();
    return 0;
}

lv_obj_t *zmk_widget_peripheral_battery_status_obj(struct zmk_widget_peripheral_battery_status *widget) {
    return widget->obj;
}
