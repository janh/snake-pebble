/*
 * Copyright (c) 2016-2017 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "settings.h"


static int32_t s_color_background;
static int32_t s_color_snake;
static int32_t s_color_text;


GColor settings_get_color_background() {
  return GColorFromHEX(s_color_background);
}

GColor settings_get_color_snake() {
  return GColorFromHEX(s_color_snake);
}

GColor settings_get_color_text() {
  return PBL_IF_COLOR_ELSE(GColorFromHEX(s_color_text), settings_get_color_snake());
}


static void save() {
  persist_write_int(MESSAGE_KEY_ColorBackground, s_color_background);
  persist_write_int(MESSAGE_KEY_ColorSnake, s_color_snake);
  persist_write_int(MESSAGE_KEY_ColorText, s_color_text);
}

static int read_int(uint32_t key, int32_t fallback) {
  if (persist_exists(key)) {
    return persist_read_int(key);
  } else {
    return fallback;
  }
}

static void load() {
  s_color_background = read_int(MESSAGE_KEY_ColorBackground, 0x000000);
  s_color_snake = read_int(MESSAGE_KEY_ColorSnake, 0xffffff);
  s_color_text = read_int(MESSAGE_KEY_ColorText, 0xaaaaaa);
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

  save();
}


void settings_init() {
  load();

  app_message_register_inbox_received(inbox_received_handler);
  app_message_open(2048, 32);
}
