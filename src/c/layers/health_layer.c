/*
 * Copyright (c) 2016 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "health_layer.h"
#include "../graphics/character.h"
#include "../lib/sizes.h"


typedef struct {
  uint32_t steps;
  uint8_t heart_rate;
} HealthLayerData;


void health_layer_set_data(HealthLayer* health_layer, uint32_t steps, uint8_t heart_rate) {
  HealthLayerData *data = (HealthLayerData *)layer_get_data(health_layer);
  data->steps = steps;
  data->heart_rate = heart_rate;
  layer_mark_dirty(health_layer);
}

static void health_layer_get_steps_characters(Character *buffer, size_t *length, uint32_t steps) {
  *length = 0;
  buffer[(*length)++] = CHARACTER_FOOT;
  if (steps >= 10000) {
    if (steps >= 100000) {
      buffer[(*length)++] = *CHARACTER_NUMBERS[(steps / 100000) % 10];
    }
    buffer[(*length)++] = *CHARACTER_NUMBERS[(steps / 10000) % 10];
    buffer[(*length)++] = *CHARACTER_NUMBERS[(steps / 1000) % 10];
    if (steps < 100000) {
      buffer[(*length)++] = CHARACTER_DOT_NARROW;
      buffer[(*length)++] = *CHARACTER_NUMBERS[(steps / 100) % 10];
    }
    buffer[(*length)++] = CHARACTER_K;
  } else {
    if (steps >= 1000) {
      buffer[(*length)++] = *CHARACTER_NUMBERS[steps / 1000];
    }
    if (steps >= 100) {
      buffer[(*length)++] = *CHARACTER_NUMBERS[(steps / 100) % 10];
    }
    if (steps >= 10) {
      buffer[(*length)++] = *CHARACTER_NUMBERS[(steps / 10) % 10];
    }
    buffer[(*length)++] = *CHARACTER_NUMBERS[steps % 10];
  }
}

static void health_layer_get_heart_rate_characters(Character *buffer, size_t *length, uint32_t heart_rate) {
  *length = 0;
  if (heart_rate >= 100) {
    buffer[(*length)++] = *CHARACTER_NUMBERS[(heart_rate / 100) % 10];
  }
  if (heart_rate >= 10) {
    buffer[(*length)++] = *CHARACTER_NUMBERS[(heart_rate / 10) % 10];
  }
  buffer[(*length)++] = *CHARACTER_NUMBERS[heart_rate % 10];
  buffer[(*length)++] = CHARACTER_HEART;
}

static void health_layer_update_proc(Layer *layer, GContext *ctx) {
  HealthLayer *health_layer = (HealthLayer *)layer;
  HealthLayerData *data = (HealthLayerData *)layer_get_data(health_layer);

  GRect rect = layer_get_bounds(layer);
  int16_t right = rect.size.w / SIZE_SCALE_FACTOR;

  size_t length;
  Character characters[6];

  health_layer_get_steps_characters(characters, &length, data->steps);
  graphics_draw_character_array(ctx, GPoint(0, 0), characters, length);

  health_layer_get_heart_rate_characters(characters, &length, data->heart_rate);
  graphics_draw_character_array_right(ctx, GPoint(right, 0), characters, length);
}

HealthLayer* health_layer_create(GRect frame) {
  HealthLayer *health_layer = layer_create_with_data(frame, sizeof(HealthLayerData));
  layer_set_update_proc(health_layer, health_layer_update_proc);
  layer_mark_dirty(health_layer);
  return health_layer;
}

void health_layer_destroy(HealthLayer* health_layer) {
  if (health_layer) {
    layer_destroy(health_layer);
  }
}
