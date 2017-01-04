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

static void write_digits_4(Character* buffer, uint16_t value) {
  buffer[0] = *CHARACTER_NUMBERS[value / 1000];
  buffer[1] = *CHARACTER_NUMBERS[(value / 100) % 10];
  buffer[2] = *CHARACTER_NUMBERS[(value / 10) % 10];
  buffer[3] = *CHARACTER_NUMBERS[value % 10];
}

static void write_digits_2(Character* buffer, uint8_t value) {
  buffer[0] = *CHARACTER_NUMBERS[value / 10];
  buffer[1] = *CHARACTER_NUMBERS[value % 10];
}

static void date_layer_update_proc(Layer *layer, GContext *ctx) {
  DateLayer *date_layer = (DateLayer *)layer;
  DateLayerData *data = (DateLayerData *)layer_get_data(date_layer);

  size_t length = 10;
  Character characters[10];

  switch (settings_get_date_format()) {

  case DATE_FORMAT_YYYY_MM_DD_HYPHEN:
    write_digits_4(&characters[0], data->year);
    characters[4] = CHARACTER_HYPHEN;
    write_digits_2(&characters[5], data->month);
    characters[7] = CHARACTER_HYPHEN;
    write_digits_2(&characters[8], data->day);
    break;

  case DATE_FORMAT_DD_MM_YYYY_DOT:
    write_digits_2(&characters[0], data->day);
    characters[2] = CHARACTER_DOT;
    write_digits_2(&characters[3], data->month);
    characters[5] = CHARACTER_DOT;
    write_digits_4(&characters[6], data->year);
    break;

  case DATE_FORMAT_DD_MM_YYYY_SLASH:
    write_digits_2(&characters[0], data->day);
    characters[2] = CHARACTER_SLASH;
    write_digits_2(&characters[3], data->month);
    characters[5] = CHARACTER_SLASH;
    write_digits_4(&characters[6], data->year);
    break;

  case DATE_FORMAT_MM_DD_YYYY_SLASH:
    write_digits_2(&characters[0], data->month);
    characters[2] = CHARACTER_SLASH;
    write_digits_2(&characters[3], data->day);
    characters[5] = CHARACTER_SLASH;
    write_digits_4(&characters[6], data->year);
    break;

  }

  graphics_draw_character_array(ctx, GPoint(0, 0), characters, length, 9 - data->anim_state, 9);
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
