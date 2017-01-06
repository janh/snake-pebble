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
  int32_t steps;
  int16_t heart_rate;
  int16_t anim_state;
} HealthLayerData;


void health_layer_set_data(HealthLayer* health_layer, int32_t steps, int16_t heart_rate) {
  HealthLayerData *data = (HealthLayerData *)layer_get_data(health_layer);
  data->steps = steps;
  data->heart_rate = heart_rate;
  layer_mark_dirty(health_layer);
}

static void health_layer_get_steps_characters(ExtendedCharacter *buffer, size_t *length, int32_t steps) {
  *length = 0;
  buffer[(*length)++] = (ExtendedCharacter) {&CHARACTER_FOOT, DIACRITIC_NONE};
  if (steps < 0) {
    buffer[(*length)++] = (ExtendedCharacter) {&CHARACTER_HYPHEN, DIACRITIC_NONE};
  } else {
    if (steps >= 10000) {
      *length += graphics_get_character_array_from_integer(&buffer[*length], 3, false, steps / 1000);
      if (steps < 100000) {
        buffer[(*length)++] = (ExtendedCharacter) {&CHARACTER_DOT_NARROW, DIACRITIC_NONE};
        buffer[(*length)++] = (ExtendedCharacter) {CHARACTER_NUMBERS[(steps / 100) % 10], DIACRITIC_NONE};
      }
      buffer[(*length)++] = (ExtendedCharacter) {&CHARACTER_K, DIACRITIC_NONE};
    } else {
      *length += graphics_get_character_array_from_integer(&buffer[*length], 4, false, steps);
    }
  }
}

static void health_layer_get_heart_rate_characters(ExtendedCharacter *buffer, size_t *length, int16_t heart_rate) {
  *length = 0;
  if (heart_rate < 0) {
    buffer[(*length)++] = (ExtendedCharacter) {&CHARACTER_HYPHEN, DIACRITIC_NONE};
  } else {
    *length += graphics_get_character_array_from_integer(&buffer[*length], 3, false, heart_rate);
  }
  buffer[(*length)++] = (ExtendedCharacter) {&CHARACTER_HEART, DIACRITIC_NONE};
}

static void health_layer_update_proc(Layer *layer, GContext *ctx) {
  HealthLayer *health_layer = (HealthLayer *)layer;
  HealthLayerData *data = (HealthLayerData *)layer_get_data(health_layer);

  GRect rect = layer_get_bounds(layer);
  int16_t right = rect.size.w / SIZE_SCALE_FACTOR;

  size_t length;
  ExtendedCharacter characters[6];

  health_layer_get_steps_characters(characters, &length, data->steps);
  graphics_draw_character_array(ctx, GPoint(0, 0), characters, length, 0, data->anim_state);

  health_layer_get_heart_rate_characters(characters, &length, data->heart_rate);
  graphics_draw_character_array_right(ctx, GPoint(right, 0), characters, length, 0, data->anim_state);
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

void health_layer_set_anim_state(HealthLayer* health_layer, int16_t anim_state) {
  HealthLayerData *data = (HealthLayerData *)layer_get_data(health_layer);
  data->anim_state = anim_state;
  layer_mark_dirty(health_layer);
}
