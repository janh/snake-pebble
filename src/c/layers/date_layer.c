/*
 * Copyright (c) 2016 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "date_layer.h"
#include "../graphics/character.h"
#include "../lib/sizes.h"


typedef struct {
  uint16_t year;
  uint8_t month;
  uint8_t day;
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

  size_t length = 10;
  Character characters[10] = {*CHARACTER_NUMBERS[data->year / 1000],
                              *CHARACTER_NUMBERS[(data->year / 100) % 10],
                              *CHARACTER_NUMBERS[(data->year / 10) % 10],
                              *CHARACTER_NUMBERS[data->year % 10],
                              CHARACTER_HYPHEN,
                              *CHARACTER_NUMBERS[data->month / 10],
                              *CHARACTER_NUMBERS[data->month % 10],
                              CHARACTER_HYPHEN,
                              *CHARACTER_NUMBERS[data->day / 10],
                              *CHARACTER_NUMBERS[data->day % 10]};

  graphics_draw_character_array(ctx, GPoint(0, 0), characters, length);
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
