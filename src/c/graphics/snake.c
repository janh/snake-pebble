/*
 * Copyright (c) 2016 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "snake.h"
#include "../lib/settings.h"
#include "../lib/sizes.h"


const SnakeElement SNAKE_LINE = {{{ZERO, ZERO, ZERO, ZERO},
                                  {ONE , ONE , ZERO, ONE },
                                  {ONE , ZERO, ONE , ONE },
                                  {ZERO, ZERO, ZERO, ZERO}},
                                 {{ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO},
                                  {ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO},
                                  {ONE , ONE , ONE , ONE , ZERO, ZERO, ONE , ONE },
                                  {ONE , ONE , ONE , ZERO, ZERO, ONE , ONE , ONE },
                                  {ONE , ONE , ZERO, ZERO, ONE , ONE , ONE , ONE },
                                  {ONE , ZERO, ZERO, ONE , ONE , ONE , ONE , ONE },
                                  {ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO},
                                  {ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO}}};

const SnakeElement SNAKE_HEAD = {{{ONE , ZERO, ZERO, ZERO},
                                  {ZERO, ONE , ONE , ZERO},
                                  {ONE , ONE , ONE , ZERO},
                                  {ZERO, ZERO, ZERO, ZERO}},
                                 {{ONE , ONE , ZERO, ZERO, ZERO, ZERO, ZERO, ZERO},
                                  {ONE , ONE , ZERO, ZERO, ZERO, ZERO, ZERO, ZERO},
                                  {ZERO, ZERO, ONE , ONE , ONE , ONE , ZERO, ZERO},
                                  {ZERO, ZERO, ONE , ONE , ONE , ONE , ZERO, ZERO},
                                  {ONE , ONE , ONE , ONE , ONE , ONE , ZERO, ZERO},
                                  {ONE , ONE , ONE , ONE , ONE , ONE , ZERO, ZERO},
                                  {ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO},
                                  {ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO}}};

const SnakeElement SNAKE_TAIL = {{{ZERO, ZERO, ZERO, ZERO},
                                  {ZERO, ZERO, ONE , ONE },
                                  {ONE , ONE , ONE , ONE },
                                  {ZERO, ZERO, ZERO, ZERO}},
                                 {{ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO},
                                  {ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO},
                                  {ZERO, ZERO, ZERO, ZERO, ONE , ONE , ONE , ONE },
                                  {ZERO, ZERO, ZERO, ZERO, ONE , ONE , ONE , ONE },
                                  {ONE , ONE , ONE , ONE , ONE , ONE , ONE , ONE },
                                  {ONE , ONE , ONE , ONE , ONE , ONE , ONE , ONE },
                                  {ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO},
                                  {ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO}}};

const SnakeElement SNAKE_EDGE = {{{ZERO, ZERO, ZERO, ZERO},
                                  {ZERO, ZERO, ONE , ONE },
                                  {ZERO, ONE , ZERO, ONE },
                                  {ZERO, ONE , ONE , ZERO}},
                                 {{ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO},
                                  {ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO},
                                  {ZERO, ZERO, ZERO, ZERO, ONE , ONE , ONE , ONE },
                                  {ZERO, ZERO, ZERO, ZERO, ONE , ONE , ONE , ONE },
                                  {ZERO, ZERO, ONE , ZERO, ZERO, ONE , ONE , ONE },
                                  {ZERO, ZERO, ONE , ONE , ZERO, ZERO, ONE , ONE },
                                  {ZERO, ZERO, ONE , ONE , ONE , ZERO, ZERO, ZERO},
                                  {ZERO, ZERO, ONE , ONE , ONE , ONE , ZERO, ZERO}}};

const SnakeElement SNAKE_FOOD = {{{ZERO, ONE , ZERO, ZERO},
                                  {ONE , ZERO, ONE , ZERO},
                                  {ZERO, ONE , ZERO, ZERO},
                                  {ZERO, ZERO, ZERO, ZERO}},
                                 {{ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO},
                                  {ZERO, ZERO, ZERO, ONE , ONE , ZERO, ZERO, ZERO},
                                  {ZERO, ZERO, ONE , ONE , ONE , ONE , ZERO, ZERO},
                                  {ZERO, ONE , ONE , ZERO, ZERO, ONE , ONE , ZERO},
                                  {ZERO, ONE , ONE , ZERO, ZERO, ONE , ONE , ZERO},
                                  {ZERO, ZERO, ONE , ONE , ONE , ONE , ZERO, ZERO},
                                  {ZERO, ZERO, ZERO, ONE , ONE , ZERO, ZERO, ZERO},
                                  {ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO}}};


static GPoint mirror_coordinates(GPoint coords, bool mirror, int16_t size) {
  if (mirror) {
    coords.x = size-1 - coords.x;
  }
  return coords;
}

static GPoint rotate_coordinates(GPoint coords, SnakeRotation rotation, int16_t size) {
  int16_t tmp;
  switch (rotation) {
  case ROTATION_0:
    break;
  case ROTATION_90:
    tmp = coords.x;
    coords.x = coords.y;
    coords.y = size-1 - tmp;
    break;
  case ROTATION_180:
    coords.x = size-1 - coords.x;
    coords.y = size-1 - coords.y;
    break;
  case ROTATION_270:
    tmp = coords.x;
    coords.x = size-1 - coords.y;
    coords.y = tmp;
    break;
  }
  return coords;
}

void graphics_draw_snake_element(GContext *ctx, GPoint pos, SnakeElement data, bool mirror, SnakeRotation rotation) {
  if (settings_get_graphics_high_resolution() && SIZE_SCALE_FACTOR == 2) {

    graphics_context_set_stroke_color(ctx, settings_get_color_snake());

    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (data.b[j][i] == ONE) {
          GPoint coords = GPoint(i, j);
          coords = mirror_coordinates(coords, mirror, 8);
          coords = rotate_coordinates(coords, rotation, 8);
          GPoint point = GPoint(SIZE_SCALE_FACTOR * pos.x + coords.x, SIZE_SCALE_FACTOR * pos.y + coords.y);
          graphics_draw_pixel(ctx, point);
        }
      }
    }

  } else {

    graphics_context_set_fill_color(ctx, settings_get_color_snake());

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (data.a[j][i] == ONE) {
          GPoint coords = GPoint(i, j);
          coords = mirror_coordinates(coords, mirror, 4);
          coords = rotate_coordinates(coords, rotation, 4);
          GRect rect = GRect(SIZE_SCALE_FACTOR * (pos.x + coords.x), SIZE_SCALE_FACTOR * (pos.y + coords.y),
                             SIZE_SCALE_FACTOR, SIZE_SCALE_FACTOR);
          graphics_fill_rect(ctx, rect, 0, GCornerNone);
        }
      }
    }

  }
}
