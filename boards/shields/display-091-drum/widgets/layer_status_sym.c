/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */
 
 #include <lvgl.h>


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_LAYER0
#define LV_ATTRIBUTE_IMG_LAYER0
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_LAYER0 uint8_t Layer0_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x7f, 0xf8, 
  0x80, 0x04, 
  0x9f, 0xe4, 
  0xa0, 0x14, 
  0xa0, 0x14, 
  0xa0, 0x14, 
  0x9f, 0xe4, 
  0x80, 0x04, 
  0x7f, 0xf8, 
};

const lv_img_dsc_t Layer0_icon = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 14,
  .header.h = 9,
  .data_size = 26,
  .data = Layer0_map,
};

#ifndef LV_ATTRIBUTE_IMG_LAYER1
#define LV_ATTRIBUTE_IMG_LAYER1
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_LAYER1 uint8_t Layer1_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x7f, 0xf8, 
  0x80, 0x04, 
  0xa0, 0x44, 
  0xa0, 0x64, 
  0xbf, 0xf4, 
  0xa0, 0x04, 
  0xa0, 0x04, 
  0x80, 0x04, 
  0x7f, 0xf8, 
};

const lv_img_dsc_t Layer1_icon = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 14,
  .header.h = 9,
  .data_size = 26,
  .data = Layer1_map,
};

#ifndef LV_ATTRIBUTE_IMG_LAYER2
#define LV_ATTRIBUTE_IMG_LAYER2
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_LAYER2 uint8_t Layer2_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x7f, 0xf8, 
  0x80, 0x04, 
  0xbc, 0x64, 
  0xa2, 0x14, 
  0xa1, 0x14, 
  0xa0, 0x94, 
  0xa0, 0x64, 
  0x80, 0x04, 
  0x7f, 0xf8, 
};

const lv_img_dsc_t Layer2_icon = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 14,
  .header.h = 9,
  .data_size = 26,
  .data = Layer2_map,
};

#ifndef LV_ATTRIBUTE_IMG_LAYER3
#define LV_ATTRIBUTE_IMG_LAYER3
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_LAYER3 uint8_t Layer3_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x7f, 0xf8, 
  0x80, 0x04, 
  0x98, 0x64, 
  0xa0, 0x14, 
  0xa1, 0x14, 
  0xa2, 0x94, 
  0x9c, 0x64, 
  0x80, 0x04, 
  0x7f, 0xf8, 
};

const lv_img_dsc_t Layer3_icon = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 14,
  .header.h = 9,
  .data_size = 26,
  .data = Layer3_map,
};

#ifndef LV_ATTRIBUTE_IMG_LAYER4
#define LV_ATTRIBUTE_IMG_LAYER4
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_LAYER4 uint8_t Layer4_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x7f, 0xf8, 
  0x80, 0x04, 
  0x83, 0xe4, 
  0x82, 0x04, 
  0x82, 0x04, 
  0xbf, 0xf4, 
  0x82, 0x04, 
  0x80, 0x04, 
  0x7f, 0xf8, 
};

const lv_img_dsc_t Layer4_icon = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 14,
  .header.h = 9,
  .data_size = 26,
  .data = Layer4_map,
};

#ifndef LV_ATTRIBUTE_IMG_LAYER5
#define LV_ATTRIBUTE_IMG_LAYER5
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_LAYER5 uint8_t Layer5_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x7f, 0xf8, 
  0x80, 0x04, 
  0x98, 0xf4, 
  0xa0, 0x94, 
  0xa0, 0x94, 
  0xa1, 0x14, 
  0x9e, 0x14, 
  0x80, 0x04, 
  0x7f, 0xf8, 
};

const lv_img_dsc_t Layer5_icon = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 14,
  .header.h = 9,
  .data_size = 26,
  .data = Layer5_map,
};

#ifndef LV_ATTRIBUTE_IMG_LAYER6
#define LV_ATTRIBUTE_IMG_LAYER6
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_LAYER6 uint8_t Layer6_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x7f, 0xf8, 
  0x80, 0x04, 
  0x9f, 0xe4, 
  0xa1, 0x14, 
  0xa1, 0x14, 
  0xa1, 0x14, 
  0x9e, 0x04, 
  0x80, 0x04, 
  0x7f, 0xf8, 
};

const lv_img_dsc_t Layer6_icon = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 14,
  .header.h = 9,
  .data_size = 26,
  .data = Layer6_map,
};

#ifndef LV_ATTRIBUTE_IMG_LAYER7
#define LV_ATTRIBUTE_IMG_LAYER7
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_LAYER7 uint8_t Layer7_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x7f, 0xf8, 
  0x80, 0x04, 
  0x80, 0x34, 
  0x80, 0x14, 
  0xbf, 0x14, 
  0x80, 0x94, 
  0x80, 0x74, 
  0x80, 0x04, 
  0x7f, 0xf8, 
};

const lv_img_dsc_t Layer7_icon = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 14,
  .header.h = 9,
  .data_size = 26,
  .data = Layer7_map,
};

#ifndef LV_ATTRIBUTE_IMG_LAYER8
#define LV_ATTRIBUTE_IMG_LAYER8
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_LAYER8 uint8_t Layer8_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x7f, 0xf8, 
  0x80, 0x04, 
  0x9e, 0xe4, 
  0xa1, 0x14, 
  0xa1, 0x14, 
  0xa1, 0x14, 
  0x9e, 0xe4, 
  0x80, 0x04, 
  0x7f, 0xf8, 
};

const lv_img_dsc_t Layer8_icon = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 14,
  .header.h = 9,
  .data_size = 26,
  .data = Layer8_map,
};

#ifndef LV_ATTRIBUTE_IMG_LAYER9
#define LV_ATTRIBUTE_IMG_LAYER9
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_LAYER9 uint8_t Layer9_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x7f, 0xf8, 
  0x80, 0x04, 
  0x91, 0xe4, 
  0xa2, 0x14, 
  0xa2, 0x14, 
  0xa2, 0x14, 
  0x9f, 0xe4, 
  0x80, 0x04, 
  0x7f, 0xf8, 
};

const lv_img_dsc_t Layer9_icon = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 14,
  .header.h = 9,
  .data_size = 26,
  .data = Layer9_map,
};

#ifndef LV_ATTRIBUTE_IMG_LAYERS_0
#define LV_ATTRIBUTE_IMG_LAYERS_0
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_LAYERS_0 uint8_t Layers_0_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x3f, 0xf0, 
  0x7f, 0xf8, 
  0xc0, 0x0c, 
  0xc0, 0x0c, 
  0xc0, 0x0c, 
  0xc0, 0x0c, 
  0xc0, 0x0c, 
  0x7f, 0xf8, 
  0x3f, 0xf0, 
};

const lv_img_dsc_t Layers_0_icon = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 14,
  .header.h = 9,
  .data_size = 26,
  .data = Layers_0_map,
};

#ifndef LV_ATTRIBUTE_IMG_LAYERS_1
#define LV_ATTRIBUTE_IMG_LAYERS_1
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_LAYERS_1 uint8_t Layers_1_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x00, 0x00, 
  0xc0, 0x00, 
  0xc0, 0x10, 
  0xc0, 0x18, 
  0xff, 0xfc, 
  0xff, 0xfc, 
  0xc0, 0x00, 
  0xc0, 0x00, 
  0xc0, 0x00, 
};

const lv_img_dsc_t Layers_1_icon = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 14,
  .header.h = 9,
  .data_size = 26,
  .data = Layers_1_map,
};

#ifndef LV_ATTRIBUTE_IMG_LAYERS_2
#define LV_ATTRIBUTE_IMG_LAYERS_2
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_LAYERS_2 uint8_t Layers_2_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0xf0, 0x70, 
  0xf0, 0x70, 
  0xcc, 0x0c, 
  0xcc, 0x0c, 
  0xc3, 0x0c, 
  0xc3, 0x0c, 
  0xc0, 0xcc, 
  0xc0, 0xf0, 
  0xc0, 0x30, 
};

const lv_img_dsc_t Layers_2_icon = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 14,
  .header.h = 9,
  .data_size = 26,
  .data = Layers_2_map,
};

#ifndef LV_ATTRIBUTE_IMG_LAYERS_3
#define LV_ATTRIBUTE_IMG_LAYERS_3
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_LAYERS_3 uint8_t Layers_3_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x70, 0x30, 
  0xf0, 0x30, 
  0xc0, 0x0c, 
  0xc0, 0x0c, 
  0xc3, 0x0c, 
  0xc3, 0x0c, 
  0xcc, 0xcc, 
  0xfc, 0xf0, 
  0x70, 0x30, 
};

const lv_img_dsc_t Layers_3_icon = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 14,
  .header.h = 9,
  .data_size = 26,
  .data = Layers_3_map,
};

#ifndef LV_ATTRIBUTE_IMG_LAYERS_4
#define LV_ATTRIBUTE_IMG_LAYERS_4
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_LAYERS_4 uint8_t Layers_4_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x07, 0xf0, 
  0x07, 0xf0, 
  0x06, 0x00, 
  0x06, 0x00, 
  0x06, 0x00, 
  0xff, 0xfc, 
  0xff, 0xfc, 
  0x06, 0x00, 
  0x06, 0x00, 
};

const lv_img_dsc_t Layers_4_icon = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 14,
  .header.h = 9,
  .data_size = 26,
  .data = Layers_4_map,
};

#ifndef LV_ATTRIBUTE_IMG_LAYERS_5
#define LV_ATTRIBUTE_IMG_LAYERS_5
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_LAYERS_5 uint8_t Layers_5_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x71, 0xfc, 
  0xf1, 0xfc, 
  0xc1, 0x8c, 
  0xc1, 0x8c, 
  0xc1, 0x8c, 
  0xc1, 0x8c, 
  0xc1, 0x8c, 
  0xff, 0x8c, 
  0x7f, 0x00, 
};

const lv_img_dsc_t Layers_5_icon = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 14,
  .header.h = 9,
  .data_size = 26,
  .data = Layers_5_map,
};

#ifndef LV_ATTRIBUTE_IMG_LAYERS_6
#define LV_ATTRIBUTE_IMG_LAYERS_6
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_LAYERS_6 uint8_t Layers_6_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x7f, 0xf8, 
  0xff, 0xfc, 
  0xc3, 0x0c, 
  0xc3, 0x0c, 
  0xc3, 0x0c, 
  0xc3, 0x0c, 
  0xc3, 0x0c, 
  0xff, 0x0c, 
  0x7e, 0x00, 
};

const lv_img_dsc_t Layers_6_icon = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 14,
  .header.h = 9,
  .data_size = 26,
  .data = Layers_6_map,
};

#ifndef LV_ATTRIBUTE_IMG_LAYERS_7
#define LV_ATTRIBUTE_IMG_LAYERS_7
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_LAYERS_7 uint8_t Layers_7_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x00, 0x3c, 
  0x00, 0x3c, 
  0x00, 0x0c, 
  0x00, 0x0c, 
  0xff, 0x0c, 
  0xff, 0x0c, 
  0x00, 0xcc, 
  0x00, 0xfc, 
  0x00, 0x3c, 
};

const lv_img_dsc_t Layers_7_icon = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 14,
  .header.h = 9,
  .data_size = 26,
  .data = Layers_7_map,
};

#ifndef LV_ATTRIBUTE_IMG_LAYERS_8
#define LV_ATTRIBUTE_IMG_LAYERS_8
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_LAYERS_8 uint8_t Layers_8_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x7f, 0xf8, 
  0xff, 0xfc, 
  0xc3, 0x0c, 
  0xc3, 0x0c, 
  0xc3, 0x0c, 
  0xc3, 0x0c, 
  0xc3, 0x0c, 
  0xff, 0xfc, 
  0x7f, 0xf8, 
};

const lv_img_dsc_t Layers_8_icon = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 14,
  .header.h = 9,
  .data_size = 26,
  .data = Layers_8_map,
};

#ifndef LV_ATTRIBUTE_IMG_LAYERS_9
#define LV_ATTRIBUTE_IMG_LAYERS_9
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_LAYERS_9 uint8_t Layers_9_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x71, 0xf8, 
  0xf3, 0xfc, 
  0xc3, 0x0c, 
  0xc3, 0x0c, 
  0xc3, 0x0c, 
  0xc3, 0x0c, 
  0xc3, 0x0c, 
  0xff, 0xfc, 
  0x7f, 0xf8, 
};

const lv_img_dsc_t Layers_9_icon = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 14,
  .header.h = 9,
  .data_size = 26,
  .data = Layers_9_map,
};

