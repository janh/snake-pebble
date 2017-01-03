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


typedef struct {
  uint8_t hour;
  uint8_t minute;
  uint8_t limit;
  AppTimer *timer;
  SnakeLayerAnimationComplete callback;
} SnakeLayerData;


void snake_layer_set_time(SnakeLayer* snake_layer, uint8_t hour, uint8_t minute) {
  SnakeLayerData *data = (SnakeLayerData *)layer_get_data(snake_layer);
  if (hour <= 23 && minute <= 59) {
    data->hour = hour;
    data->minute = minute;
    layer_mark_dirty(snake_layer);
  }
}

static void snake_layer_timer_cancel(SnakeLayer* snake_layer) {
  SnakeLayerData *data = (SnakeLayerData *)layer_get_data(snake_layer);

  if (data->timer) {
    app_timer_cancel(data->timer);
    data->timer = NULL;
  }
}

static uint8_t snake_layer_get_limit(SnakeLayer* snake_layer, uint8_t max_length) {
  SnakeLayerData *data = (SnakeLayerData *)layer_get_data(snake_layer);

  uint8_t limit = data->limit;

  if (limit > 0) {
    if (max_length <= 11) {
      if (max_length > 8) {
        limit = limit + (max_length - 8);
      }
      limit /= 2;
    }
    if (limit < 2) {
      limit = 2;
    }
  }

  return limit;
}

static void snake_layer_update_proc(Layer *layer, GContext *ctx) {
  SnakeLayer *snake_layer = (SnakeLayer *)layer;
  SnakeLayerData *data = (SnakeLayerData *)layer_get_data(snake_layer);

  bool complete = true;

  NumberDesc number;

  number = *NUMBER_DESCS[data->hour / 10];
  complete &= graphics_draw_number(ctx, SIZE_TIME_DIGIT_POSITION_1, number,
                                   snake_layer_get_limit(snake_layer, number.max_length));

  number = *NUMBER_DESCS[data->hour % 10];
  complete &= graphics_draw_number(ctx, SIZE_TIME_DIGIT_POSITION_2, number,
                                   snake_layer_get_limit(snake_layer, number.max_length));

  graphics_draw_snake_element(ctx, SIZE_TIME_COLON_POSITION_1, SNAKE_FOOD, false, ROTATION_0);
  graphics_draw_snake_element(ctx, SIZE_TIME_COLON_POSITION_2, SNAKE_FOOD, false, ROTATION_0);

  number = *NUMBER_DESCS[data->minute / 10];
  complete &= graphics_draw_number(ctx, SIZE_TIME_DIGIT_POSITION_3, number,
                                   snake_layer_get_limit(snake_layer, number.max_length));

  number = *NUMBER_DESCS[data->minute % 10];
  complete &= graphics_draw_number(ctx, SIZE_TIME_DIGIT_POSITION_4, number,
                                   snake_layer_get_limit(snake_layer, number.max_length));

  if (complete) {
    data->limit = 0;
    if (data->timer != NULL) {
      snake_layer_timer_cancel(snake_layer);
      if (data->callback != NULL) {
        data->callback();
      }
    }
  }
}

SnakeLayer* snake_layer_create(GRect frame) {
  SnakeLayer *snake_layer = layer_create_with_data(frame, sizeof(SnakeLayerData));
  layer_set_update_proc(snake_layer, snake_layer_update_proc);
  layer_mark_dirty(snake_layer);
  return snake_layer;
}

void snake_layer_destroy(SnakeLayer* snake_layer) {
  if (snake_layer) {
    layer_destroy(snake_layer);
  }
}

static void snake_layer_callback(void *context);

static void snake_layer_timer_register(SnakeLayer* snake_layer) {
  SnakeLayerData *data = (SnakeLayerData *)layer_get_data(snake_layer);

  data->timer = app_timer_register(33, snake_layer_callback, snake_layer);
}

static void snake_layer_callback(void *context) {
  SnakeLayer *snake_layer = (SnakeLayer *)context;
  SnakeLayerData *data = (SnakeLayerData *)layer_get_data(snake_layer);

  data->limit++;
  layer_mark_dirty(snake_layer);

  snake_layer_timer_register(snake_layer);
}

void snake_layer_animate(SnakeLayer* snake_layer, SnakeLayerAnimationComplete callback) {
  SnakeLayerData *data = (SnakeLayerData *)layer_get_data(snake_layer);

  data->callback = callback;
  data->limit = 2;
  layer_mark_dirty(snake_layer);

  snake_layer_timer_cancel(snake_layer);
  snake_layer_timer_register(snake_layer);
}
