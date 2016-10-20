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


typedef enum {
  ZERO = 0,
  ONE
} SnakePixel;

typedef struct SnakeElement { SnakePixel a[4][4]; } SnakeElement;


SnakeElement SNAKE_LINE;
SnakeElement SNAKE_HEAD;
SnakeElement SNAKE_TAIL;
SnakeElement SNAKE_EDGE;
SnakeElement SNAKE_FOOD;


typedef enum {
  ROTATION_0 = 0,
  ROTATION_90,
  ROTATION_180,
  ROTATION_270,
} SnakeRotation;


void graphics_draw_snake_element(GContext *ctx, GPoint pos, SnakeElement data, bool mirror, SnakeRotation rotation);
