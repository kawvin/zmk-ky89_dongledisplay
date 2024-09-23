/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */
 
 #include <lvgl.h>


// #ifndef LV_ATTRIBUTE_MEM_ALIGN
// #define LV_ATTRIBUTE_MEM_ALIGN
// #endif

// #ifndef LV_ATTRIBUTE_IMG_DISCONNECT
// #define LV_ATTRIBUTE_IMG_DISCONNECT
// #endif

// const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_DISCONNECT uint8_t disconnect_map[] = {
//   0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
//   0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

//   0x00, 0x00, 
//   0x08, 0x80, 
//   0x3b, 0xe0, 
//   0x78, 0xf0, 
//   0xf8, 0xfc, 
//   0x78, 0xf0, 
//   0x3b, 0xe0, 
//   0x08, 0x80, 
//   0x00, 0x00, 
// };

// const lv_img_dsc_t disconnect_icon = {
//   .header.cf = LV_IMG_CF_INDEXED_1BIT,
//   .header.always_zero = 0,
//   .header.reserved = 0,
//   .header.w = 14,
//   .header.h = 9,
//   .data_size = 26,
//   .data = disconnect_map,
// };