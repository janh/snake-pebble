/*
 * Copyright (c) 2016 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "snake_layer.h"
#include "../graphics/number.h"
#include "../graphics/snake.h"
#include "../lib/sizes.h"


static void layer_update_proc(Layer *layer, GContext *ctx) {
  graphics_draw_number(ctx, SIZE_TIME_DIGIT_POSITION_1, NUMBER_1_DESC);
  graphics_draw_number(ctx, SIZE_TIME_DIGIT_POSITION_2, NUMBER_8_DESC);

  graphics_draw_snake_element(ctx, SIZE_TIME_COLON_POSITION_1, SNAKE_FOOD, false, ROTATION_0);
  graphics_draw_snake_element(ctx, SIZE_TIME_COLON_POSITION_2, SNAKE_FOOD, false, ROTATION_0);

  graphics_draw_number(ctx, SIZE_TIME_DIGIT_POSITION_3, NUMBER_4_DESC);
  graphics_draw_number(ctx, SIZE_TIME_DIGIT_POSITION_4, NUMBER_2_DESC);
}

SnakeLayer* snake_layer_create(GRect frame) {
  SnakeLayer *snake_layer = layer_create(frame);
  layer_set_update_proc(snake_layer, layer_update_proc);
  layer_mark_dirty(snake_layer);
  return snake_layer;
}

void snake_layer_destroy(SnakeLayer* snake_layer) {
  if (snake_layer) {
    layer_destroy(snake_layer);
  }
}
