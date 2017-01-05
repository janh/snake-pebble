/*
 * Copyright (c) 2016-2017 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "date_layer.h"
#include "../graphics/character.h"
#include "../lib/settings.h"
#include "../lib/sizes.h"


typedef struct {
  uint16_t year;
  uint8_t month;
  uint8_t day;
  uint8_t weekday;
  int16_t anim_state;
} DateLayerData;


void date_layer_set_date(DateLayer* date_layer, uint16_t year, uint8_t month, uint8_t day, uint8_t weekday) {
  DateLayerData *data = (DateLayerData *)layer_get_data(date_layer);
  if (year <= 9999 && month <= 12 && day <= 31) {
    data->year = year;
    data->month = month;
    data->day = day;
    data->weekday = weekday;
    layer_mark_dirty(date_layer);
  }
}

static void date_layer_get_characters(DateLayer *date_layer, Character *buffer, size_t *length) {
  DateLayerData *data = (DateLayerData *)layer_get_data(date_layer);

  *length = 0;

  switch (settings_get_date_format()) {

  case DATE_FORMAT_YYYY_MM_DD_HYPHEN:
    *length += graphics_get_character_array_from_integer(&buffer[*length], 4, true, data->year);
    buffer[(*length)++] = CHARACTER_HYPHEN;
    *length += graphics_get_character_array_from_integer(&buffer[*length], 2, true, data->month);
    buffer[(*length)++] = CHARACTER_HYPHEN;
    *length += graphics_get_character_array_from_integer(&buffer[*length], 2, true, data->day);
    break;

  case DATE_FORMAT_DD_MM_YYYY_DOT:
    *length += graphics_get_character_array_from_integer(&buffer[*length], 2, true, data->day);
    buffer[(*length)++] = CHARACTER_DOT;
    *length += graphics_get_character_array_from_integer(&buffer[*length], 2, true, data->month);
    buffer[(*length)++] = CHARACTER_DOT;
    *length += graphics_get_character_array_from_integer(&buffer[*length], 4, true, data->year);
    break;

  case DATE_FORMAT_DD_MM_YYYY_SLASH:
    *length += graphics_get_character_array_from_integer(&buffer[*length], 2, true, data->day);
    buffer[(*length)++] = CHARACTER_SLASH;
    *length += graphics_get_character_array_from_integer(&buffer[*length], 2, true, data->month);
    buffer[(*length)++] = CHARACTER_SLASH;
    *length += graphics_get_character_array_from_integer(&buffer[*length], 4, true, data->year);
    break;

  case DATE_FORMAT_MM_DD_YYYY_SLASH:
    *length += graphics_get_character_array_from_integer(&buffer[*length], 2, true, data->month);
    buffer[(*length)++] = CHARACTER_SLASH;
    *length += graphics_get_character_array_from_integer(&buffer[*length], 2, true, data->day);
    buffer[(*length)++] = CHARACTER_SLASH;
    *length += graphics_get_character_array_from_integer(&buffer[*length], 4, true, data->year);
    break;

  default:
    break;

  }
}

static void date_layer_update_proc(Layer *layer, GContext *ctx) {
  DateLayer *date_layer = (DateLayer *)layer;
  DateLayerData *data = (DateLayerData *)layer_get_data(date_layer);

  GRect rect = layer_get_bounds(date_layer);
  int16_t right = rect.size.w / SIZE_SCALE_FACTOR;

  size_t length;
  Character characters[10];

  date_layer_get_characters(date_layer, characters, &length);
  graphics_draw_character_array(ctx, GPoint(0, 0), characters, length, 11 - data->anim_state, 11);
}

DateLayer* date_layer_create(GRect frame) {
  DateLayer *date_layer = layer_create_with_data(frame, sizeof(DateLayerData));
  layer_set_update_proc(date_layer, date_layer_update_proc);
  layer_mark_dirty(date_layer);
  return date_layer;
}

void date_layer_destroy(DateLayer* date_layer) {
  if (date_layer) {
    layer_destroy(date_layer);
  }
}

void date_layer_set_anim_state(DateLayer* date_layer, int16_t anim_state) {
  DateLayerData *data = (DateLayerData *)layer_get_data(date_layer);
  data->anim_state = anim_state;
  layer_mark_dirty(date_layer);
}
