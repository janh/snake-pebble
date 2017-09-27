/*
 * Copyright (c) 2016 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include "common.h"

#include <pebble.h>
#include <inttypes.h>


typedef struct SnakeElement {
  Pixel a[4][4];
  Pixel b[8][8];
} SnakeElement;


extern const SnakeElement SNAKE_LINE;
extern const SnakeElement SNAKE_HEAD;
extern const SnakeElement SNAKE_TAIL;
extern const SnakeElement SNAKE_EDGE;
extern const SnakeElement SNAKE_FOOD;


typedef enum {
  ROTATION_0 = 0,
  ROTATION_90,
  ROTATION_180,
  ROTATION_270,
} SnakeRotation;


void graphics_draw_snake_element(GContext *ctx, GPoint pos, SnakeElement data, bool mirror, SnakeRotation rotation);
