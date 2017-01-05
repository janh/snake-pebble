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
  int16_t anim_state;
} DateLayerData;


void date_layer_set_date(DateLayer* date_layer, uint16_t year, uint8_t month, uint8_t day) {
  DateLayerData *data = (DateLayerData *)layer_get_data(date_layer);
  if (year <= 9999 && month <= 12 && day <= 31) {
    data->year = year;
    data->month = month;
    data->day = day;
    layer_mark_dirty(date_layer);
  }
}

static void date_layer_update_proc(Layer *layer, GContext *ctx) {
  DateLayer *date_layer = (DateLayer *)layer;
  DateLayerData *data = (DateLayerData *)layer_get_data(date_layer);

  size_t length = 0;
  Character characters[10];

  switch (settings_get_date_format()) {

  case DATE_FORMAT_YYYY_MM_DD_HYPHEN:
    length += graphics_get_character_array_from_integer(&characters[length], 4, true, data->year);
    characters[length++] = CHARACTER_HYPHEN;
    length += graphics_get_character_array_from_integer(&characters[length], 2, true, data->month);
    characters[length++] = CHARACTER_HYPHEN;
    length += graphics_get_character_array_from_integer(&characters[length], 2, true, data->day);
    break;

  case DATE_FORMAT_DD_MM_YYYY_DOT:
    length += graphics_get_character_array_from_integer(&characters[length], 2, true, data->day);
    characters[length++] = CHARACTER_DOT;
    length += graphics_get_character_array_from_integer(&characters[length], 2, true, data->month);
    characters[length++] = CHARACTER_DOT;
    length += graphics_get_character_array_from_integer(&characters[length], 4, true, data->year);
    break;

  case DATE_FORMAT_DD_MM_YYYY_SLASH:
    length += graphics_get_character_array_from_integer(&characters[length], 2, true, data->day);
    characters[length++] = CHARACTER_SLASH;
    length += graphics_get_character_array_from_integer(&characters[length], 2, true, data->month);
    characters[length++] = CHARACTER_SLASH;
    length += graphics_get_character_array_from_integer(&characters[length], 4, true, data->year);
    break;

  case DATE_FORMAT_MM_DD_YYYY_SLASH:
    length += graphics_get_character_array_from_integer(&characters[length], 2, true, data->month);
    characters[length++] = CHARACTER_SLASH;
    length += graphics_get_character_array_from_integer(&characters[length], 2, true, data->day);
    characters[length++] = CHARACTER_SLASH;
    length += graphics_get_character_array_from_integer(&characters[length], 4, true, data->year);
    break;

  default:
    break;

  }

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
