/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/display.h>
#include <zmk/display/widgets/layer_status.h>
#include <zmk/events/layer_state_changed.h>
#include <zmk/event_manager.h>
#include <zmk/endpoints.h>
#include <zmk/keymap.h>

static sys_slist_t widgets = SYS_SLIST_STATIC_INIT(&widgets);

struct layer_status_state {
    uint8_t index;
    const char *label;
};

// LV_IMG_DECLARE(Layer0_icon);
// LV_IMG_DECLARE(Layer1_icon);
// LV_IMG_DECLARE(Layer2_icon);
// LV_IMG_DECLARE(Layer3_icon);
// LV_IMG_DECLARE(Layer4_icon);
// LV_IMG_DECLARE(Layer5_icon);
// LV_IMG_DECLARE(Layer6_icon);
// LV_IMG_DECLARE(Layer7_icon);
// LV_IMG_DECLARE(Layer8_icon);
// LV_IMG_DECLARE(Layer9_icon);
LV_IMG_DECLARE(Layers_0_icon);
LV_IMG_DECLARE(Layers_1_icon);
LV_IMG_DECLARE(Layers_2_icon);
LV_IMG_DECLARE(Layers_3_icon);
LV_IMG_DECLARE(Layers_4_icon);
LV_IMG_DECLARE(Layers_5_icon);
LV_IMG_DECLARE(Layers_6_icon);
LV_IMG_DECLARE(Layers_7_icon);
LV_IMG_DECLARE(Layers_8_icon);
LV_IMG_DECLARE(Layers_9_icon);

const lv_img_dsc_t *layers_num[] = {
    // &Layer0_icon,
    // &Layer1_icon,
    // &Layer2_icon,
    // &Layer3_icon,
    // &Layer4_icon,
    // &Layer5_icon,
    // &Layer6_icon,
    // &Layer7_icon,
    // &Layer8_icon,
    // &Layer9_icon,
    &Layers_0_icon,
    &Layers_1_icon,
    &Layers_2_icon,
    &Layers_3_icon,
    &Layers_4_icon,
    &Layers_5_icon,
    &Layers_6_icon,
    &Layers_7_icon,
    &Layers_8_icon,
    &Layers_9_icon,
};

enum layers_symbol {
    layers_symbol_layer_num,
    layers_symbol_layer_label
};

// static void set_layer_symbol(lv_obj_t *widget, struct layer_status_state state) {
//     lv_obj_t *layer_num = lv_obj_get_child(widget, layers_symbol_layer_num);
//     lv_img_set_src(layer_num, layers_num[state.index]);
// }

static void set_layer_symbol(lv_obj_t *label, struct layer_status_state state) {

    // 设置标签的旋转角度
    // lv_obj_set_style_transform_angle(label, LV_PART_MAIN, LV_STATE_DEFAULT, 900);
    
    // 设置标签的中心点，旋转将围绕这个点进行
    // lv_obj_set_style_local_transform_origin(label, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_TRANSFORM_ORIGIN_CENTER);
 
    // 设置标签的位置
    // lv_obj_set_pos(label, 60, 6); // 根据需要调整位置

    if (state.label == NULL) {
        char text[7] = {};

        sprintf(text, "%i", state.index);

        lv_label_set_text(label, text);
    } else {
        char text[13] = {};

        snprintf(text, sizeof(text), "%s", state.label);

        lv_label_set_text(label, text);
    }
    // lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    // lv_obj_center(label);
    // lv_obj_set_style_transform_angle(label, 50, 0);f
    
 
}

static void layer_status_update_cb(struct layer_status_state state) {
    struct zmk_widget_layer_status *widget;
    SYS_SLIST_FOR_EACH_CONTAINER(&widgets, widget, node) { set_layer_symbol(widget->obj, state); }
}

static struct layer_status_state layer_status_get_state(const zmk_event_t *eh) {
    uint8_t index = zmk_keymap_highest_layer_active();
    return (struct layer_status_state) {
        .index = index,
        .label = zmk_keymap_layer_name(index)
    };
}

ZMK_DISPLAY_WIDGET_LISTENER(widget_layer_status, struct layer_status_state, layer_status_update_cb,
                            layer_status_get_state)

ZMK_SUBSCRIPTION(widget_layer_status, zmk_layer_state_changed);

int zmk_widget_layer_status_init(struct zmk_widget_layer_status *widget, lv_obj_t *parent) {
    widget->obj = lv_label_create(parent);
    // lv_obj_set_size(widget->obj, 32, 16);
    // lv_obj_align(widget->obj, LV_ALIGN_TOP_LEFT, 0, 0);
    sys_slist_append(&widgets, &widget->node);

    widget_layer_status_init();
    return 0;
}

// int zmk_widget_layer_status_init(struct zmk_widget_layer_status *widget, lv_obj_t *parent) {
//     widget->obj = lv_label_create(parent);
//     sys_slist_append(&widgets, &widget->node);

//     widget_layer_status_init();
//     return 0;
// }

// int zmk_widget_layer_status_init(struct zmk_widget_layer_status *widget, lv_obj_t *parent) {
    
//     widget->obj = lv_obj_create(parent);
//     lv_obj_set_size(widget->obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);

    // lv_obj_t *layer_num = lv_img_create(widget->obj);
    // lv_obj_align(layer_num, LV_ALIGN_TOP_LEFT, 0, 0);
    // lv_img_set_src(layer_num, layers_num[0]);

//     lv_obj_t *layer_label = lv_label_create(parent);
//     lv_obj_align(layer_label, LV_ALIGN_TOP_LEFT, 0, 0);
    
//     sys_slist_append(&widgets, &widget->node);

//     widget_layer_status_init();
//     return 0;
// }

lv_obj_t *zmk_widget_layer_status_obj(struct zmk_widget_layer_status *widget) {
    return widget->obj;
}