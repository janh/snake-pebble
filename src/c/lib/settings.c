/*
 * Copyright (c) 2016-2017 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "settings.h"


static SettingsChanged s_callback;

static int32_t s_color_background;
static int32_t s_color_snake;
static int32_t s_color_text;

static int32_t s_date_format;

static bool s_graphics_high_resolution;


GColor settings_get_color_background() {
  return GColorFromHEX(s_color_background);
}

GColor settings_get_color_snake() {
  return GColorFromHEX(s_color_snake);
}

GColor settings_get_color_text() {
  return PBL_IF_COLOR_ELSE(GColorFromHEX(s_color_text), settings_get_color_snake());
}

DateFormat settings_get_date_format() {
  return s_date_format;
}

bool settings_get_graphics_high_resolution() {
  return s_graphics_high_resolution;
}


static void save() {
  persist_write_int(MESSAGE_KEY_ColorBackground, s_color_background);
  persist_write_int(MESSAGE_KEY_ColorSnake, s_color_snake);
  persist_write_int(MESSAGE_KEY_ColorText, s_color_text);
  persist_write_int(MESSAGE_KEY_DateFormat, s_date_format);
  persist_write_bool(MESSAGE_KEY_GraphicsHighResolution, s_graphics_high_resolution);
}

static int read_int(uint32_t key, int32_t fallback) {
  if (persist_exists(key)) {
    return persist_read_int(key);
  } else {
    return fallback;
  }
}

static int read_bool(uint32_t key, bool fallback) {
  if (persist_exists(key)) {
    return persist_read_bool(key);
  } else {
    return fallback;
  }
}

static void load() {
  s_color_background = read_int(MESSAGE_KEY_ColorBackground, 0x000000);
  s_color_snake = read_int(MESSAGE_KEY_ColorSnake, 0xffffff);
  s_color_text = read_int(MESSAGE_KEY_ColorText, 0xaaaaaa);
  s_date_format = read_int(MESSAGE_KEY_DateFormat, DATE_FORMAT_YYYY_MM_DD_HYPHEN);
  s_graphics_high_resolution = read_bool(MESSAGE_KEY_GraphicsHighResolution, false);
}


static void inbox_received_handler(DictionaryIterator *iterator, void *context) {
  Tuple *color_background_tuple = dict_find(iterator, MESSAGE_KEY_ColorBackground);
  if (color_background_tuple) {
    s_color_background = color_background_tuple->value->int32;
  }

  Tuple *color_snake_tuple = dict_find(iterator, MESSAGE_KEY_ColorSnake);
  if (color_snake_tuple) {
    s_color_snake = color_snake_tuple->value->int32;
  }

  Tuple *color_text_tuple = dict_find(iterator, MESSAGE_KEY_ColorText);
  if (color_text_tuple) {
    s_color_text = color_text_tuple->value->int32;
  }

  Tuple *date_format_tuple = dict_find(iterator, MESSAGE_KEY_DateFormat);
  if (date_format_tuple) {
    s_date_format = date_format_tuple->value->int32;
  }

  Tuple *graphics_high_resolution_tuple = dict_find(iterator, MESSAGE_KEY_GraphicsHighResolution);
  if (graphics_high_resolution_tuple) {
    s_graphics_high_resolution = (graphics_high_resolution_tuple->value->int16 > 0);
  }

  save();

  if (s_callback != NULL) {
    s_callback();
  }
}


void settings_set_callback(SettingsChanged callback) {
  s_callback = callback;
}

void settings_init() {
  load();

  app_message_register_inbox_received(inbox_received_handler);
  app_message_open(2048, 32);
}
