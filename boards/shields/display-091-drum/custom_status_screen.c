/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include "custom_status_screen.h"
#include "widgets/battery_status.h"
// #include "widgets/peripheral_status.h"
#include "widgets/modifiers.h"
#include "widgets/bongo_drum.h"
#include "widgets/layer_status.h"
#include "widgets/output_status.h"
#include <zmk/display/widgets/battery_status.h>

// #include "widgets/peripheral_status.h"

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

static struct zmk_widget_output_status output_status_widget;
static struct zmk_widget_layer_status layer_status_widget;
static struct zmk_widget_battery_status battery_status_widget;
static struct zmk_widget_peripheral_battery_status peripheral_battery_status_widget;
// static struct zmk_widget_peripheral_status peripheral_status_widget;
static struct zmk_widget_modifiers modifiers_widget;
static struct zmk_widget_bongo_drum bongo_drum_widget;

lv_style_t global_style;

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen;

    screen = lv_obj_create(NULL);
    // 屏幕旋转90度
    // LV_DISP_ROT_NONE, LV_DISP_ROT_90, LV_DISP_ROT_180, or LV_DISP_ROT_270
    //lv_disp_set_rotation(NULL, LV_DISP_ROT_90);

    lv_style_init(&global_style);
    lv_style_set_text_font(&global_style, &lv_font_unscii_8);
    lv_style_set_text_letter_space(&global_style, 1);
    lv_style_set_text_line_space(&global_style, 1);
    lv_obj_add_style(screen, &global_style, LV_PART_MAIN);
    
 
    // 修饰符
    zmk_widget_modifiers_init(&modifiers_widget, screen);
    lv_obj_align(zmk_widget_modifiers_obj(&modifiers_widget), LV_ALIGN_BOTTOM_LEFT, 0, 0);
    // lv_obj_align(zmk_widget_modifiers_obj(&modifiers_widget), LV_ALIGN_TOP_LEFT, 0, 0);

    // 层
    zmk_widget_layer_status_init(&layer_status_widget, screen);
    lv_obj_align(zmk_widget_layer_status_obj(&layer_status_widget), LV_ALIGN_TOP_LEFT, 33,1);
    // lv_obj_align_to(zmk_widget_layer_status_obj(&layer_status_widget), zmk_widget_bongo_drum_obj(&bongo_drum_widget), LV_ALIGN_BOTTOM_LEFT, 0, 5);

    // 敲鼓动画
    zmk_widget_bongo_drum_init(&bongo_drum_widget, screen);
    lv_obj_align(zmk_widget_bongo_drum_obj(&bongo_drum_widget), LV_ALIGN_TOP_LEFT, 80, 0);

    // 电池电量
    // zmk_widget_battery_status_init(&battery_status_widget, screen);
    // lv_obj_align(zmk_widget_battery_status_obj(&battery_status_widget), LV_ALIGN_TOP_LEFT, 2, 2);

// #if IS_ENABLED(CONFIG_ZMK_WIDGET_BATTERY_STATUS_SHOW_PERIPHERAL)
    zmk_widget_peripheral_battery_status_init(&peripheral_battery_status_widget, screen);
    lv_obj_align(zmk_widget_peripheral_battery_status_obj(&peripheral_battery_status_widget), LV_ALIGN_TOP_LEFT, 0, 0);
    // zmk_widget_peripheral_status_init(&peripheral_status_widget, screen);
    // lv_obj_align(zmk_widget_peripheral_status_obj(&peripheral_status_widget), LV_ALIGN_TOP_LEFT, 0, 0);
// #endif

    // 输入输出状态
    zmk_widget_output_status_init(&output_status_widget, screen);
    lv_obj_align(zmk_widget_output_status_obj(&output_status_widget), LV_ALIGN_TOP_LEFT, 110, 0);

    return screen;
}