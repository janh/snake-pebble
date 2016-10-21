/*
 * Copyright (c) 2016 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once


#include <pebble.h>
#include <inttypes.h>
#include <stdbool.h>


typedef enum {
  EL_NONE = 0,
  EL_UP,
  EL_RIGHT,
  EL_DOWN,
  EL_LEFT,
  EL_HEAD,
} NumberElement;

typedef struct NumberPointer {
  int8_t x;
  int8_t y;
} NumberPointer;

typedef struct NumberDesc {
  uint8_t max_length;
  NumberPointer start[3];
  NumberElement el[7][4];
} NumberDesc;



extern const NumberDesc NUMBER_0_DESC;
extern const NumberDesc NUMBER_1_DESC;
extern const NumberDesc NUMBER_2_DESC;
extern const NumberDesc NUMBER_3_DESC;
extern const NumberDesc NUMBER_4_DESC;
extern const NumberDesc NUMBER_5_DESC;
extern const NumberDesc NUMBER_6_DESC;
extern const NumberDesc NUMBER_7_DESC;
extern const NumberDesc NUMBER_8_DESC;
extern const NumberDesc NUMBER_9_DESC;


bool graphics_draw_number(GContext *ctx, GPoint pos, NumberDesc number, uint8_t limit);
