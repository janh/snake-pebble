/*
 * Copyright (c) 2016 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "snake.h"
#include "../lib/sizes.h"


SnakeElement SNAKE_LINE = {{{ZERO, ZERO, ZERO, ZERO},
                            {ONE , ONE , ZERO, ONE },
                            {ONE , ZERO, ONE , ONE },
                            {ZERO, ZERO, ZERO, ZERO}}};

SnakeElement SNAKE_HEAD = {{{ONE , ZERO, ZERO, ZERO},
                            {ZERO, ONE , ONE , ZERO},
                            {ONE , ONE , ONE , ZERO},
                            {ZERO, ZERO, ZERO, ZERO}}};

SnakeElement SNAKE_TAIL = {{{ZERO, ZERO, ZERO, ZERO},
                            {ZERO, ZERO, ONE , ONE },
                            {ONE , ONE , ONE , ONE },
                            {ZERO, ZERO, ZERO, ZERO}}};

SnakeElement SNAKE_EDGE = {{{ZERO, ZERO, ZERO, ZERO},
                            {ZERO, ZERO, ONE , ONE },
                            {ZERO, ONE , ZERO, ONE },
                            {ZERO, ONE , ONE , ZERO}}};

SnakeElement SNAKE_FOOD = {{{ZERO, ONE , ZERO, ZERO},
                            {ONE , ZERO, ONE , ZERO},
                            {ZERO, ONE , ZERO, ZERO},
                            {ZERO, ZERO, ZERO, ZERO}}};


static GPoint mirror_coordinates(GPoint coords, bool mirror) {
  if (mirror) {
    coords.x = 3 - coords.x;
  }
  return coords;
}

static GPoint rotate_coordinates(GPoint coords, SnakeRotation rotation) {
  int16_t tmp;
  switch (rotation) {
  case ROTATION_0:
    break;
  case ROTATION_90:
    tmp = coords.x;
    coords.x = coords.y;
    coords.y = 3 - tmp;
    break;
  case ROTATION_180:
    coords.x = 3 - coords.x;
    coords.y = 3 - coords.y;
    break;
  case ROTATION_270:
    tmp = coords.x;
    coords.x = 3 - coords.y;
    coords.y = tmp;
    break;
  }
  return coords;
}

void graphics_draw_snake_element(GContext *ctx, GPoint pos, SnakeElement data, bool mirror, SnakeRotation rotation) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (data.a[j][i] == ONE) {
        GPoint coords = GPoint(i, j);
        coords = mirror_coordinates(coords, mirror);
        coords = rotate_coordinates(coords, rotation);
        GRect rect = GRect(SIZE_SCALE_FACTOR * (pos.x + coords.x), SIZE_SCALE_FACTOR * (pos.y + coords.y),
                           SIZE_SCALE_FACTOR, SIZE_SCALE_FACTOR);
        graphics_fill_rect(ctx, rect, 0, GCornerNone);
      }
    }
  }
}
