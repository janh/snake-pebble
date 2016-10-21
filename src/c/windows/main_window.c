/*
 * Copyright (c) 2016 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "main_window.h"
#include "../layers/snake_layer.h"
#include "../lib/sizes.h"

#include <pebble.h>
#include <stdbool.h>
#include <inttypes.h>


static Window *s_main_window;
static Layer *s_snake_layer;


static void window_load(Window *window) {
  window_set_background_color(window, PBL_IF_COLOR_ELSE(GColorSpringBud, GColorWhite));

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  GRect rect = GRect((bounds.size.w - SIZE_SCALE_FACTOR * SIZE_TIME_WIDTH) / 2,
                     (bounds.size.h - SIZE_SCALE_FACTOR * SIZE_TIME_HEIGHT) / 2,
                     SIZE_SCALE_FACTOR * SIZE_TIME_WIDTH,
                     SIZE_SCALE_FACTOR * SIZE_TIME_HEIGHT);
  s_snake_layer = snake_layer_create(rect);
  layer_add_child(window_layer, s_snake_layer);

}

static int format_hour(int hour) {
  if (!clock_is_24h_style()) {
    hour = hour % 12;
    if (hour == 0) {
      hour = 12;
    }
  }
  return hour;
}

static void tick_handler(tm *tick_time, TimeUnits units_changed) {
  snake_layer_set_time(s_snake_layer, format_hour(tick_time->tm_hour), tick_time->tm_min);
}

static void window_appear(Window *window) {
  time_t timestamp = time(NULL);
  tm *timeinfo = localtime(&timestamp);

  snake_layer_set_time(s_snake_layer, format_hour(timeinfo->tm_hour), timeinfo->tm_min);
  snake_layer_animate(s_snake_layer);

  tick_timer_service_subscribe(HOUR_UNIT | MINUTE_UNIT, tick_handler);
}

static void window_unload(Window *window) {
  snake_layer_destroy(s_snake_layer);
  window_destroy(s_main_window);
  s_main_window = NULL;
}

void main_window_push() {
  if (!s_main_window) {
    s_main_window = window_create();
    window_set_window_handlers(s_main_window, (WindowHandlers) {
      .load = window_load,
      .appear = window_appear,
      .unload = window_unload,
    });
  }
  window_stack_push(s_main_window, true);
}
