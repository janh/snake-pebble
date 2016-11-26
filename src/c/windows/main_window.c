/*
 * Copyright (c) 2016 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "main_window.h"
#include "../layers/snake_layer.h"
#include "../layers/date_layer.h"
#include "../layers/health_layer.h"
#include "../lib/color.h"
#include "../lib/sizes.h"
#include "../lib/health.h"

#include <pebble.h>
#include <stdbool.h>
#include <inttypes.h>


static Window *s_main_window;
static Layer *s_snake_layer;
static Layer *s_date_layer;
static Layer *s_health_layer;


static void update_layout() {
  Layer *window_layer = window_get_root_layer(s_main_window);
  GRect bounds = layer_get_unobstructed_bounds(window_layer);

  int16_t width = (bounds.size.w - SIZE_GRID_OFFSET.x) / SIZE_SCALE_FACTOR;
  int16_t height = (bounds.size.h - SIZE_GRID_OFFSET.y) / SIZE_SCALE_FACTOR;

  int16_t snake_margin = (height - SIZE_TIME_HEIGHT) / 2;

  GRect rect_snake = GRect(SIZE_GRID_OFFSET.x + SIZE_SCALE_FACTOR * ((width - SIZE_TIME_WIDTH) / 2),
                           SIZE_GRID_OFFSET.y + SIZE_SCALE_FACTOR * snake_margin,
                           SIZE_SCALE_FACTOR * SIZE_TIME_WIDTH,
                           SIZE_SCALE_FACTOR * SIZE_TIME_HEIGHT);

  int16_t date_offset = PBL_IF_ROUND_ELSE(3, (snake_margin - SIZE_DATE_HEIGHT) / 2);
  GRect rect_date = GRect(SIZE_GRID_OFFSET.x + SIZE_SCALE_FACTOR * ((width - SIZE_DATE_WIDTH) / 2),
                          SIZE_GRID_OFFSET.y + SIZE_SCALE_FACTOR * (snake_margin - SIZE_DATE_HEIGHT - date_offset),
                          SIZE_SCALE_FACTOR * SIZE_DATE_WIDTH,
                          SIZE_SCALE_FACTOR * SIZE_DATE_HEIGHT);

  int16_t health_offset = PBL_IF_ROUND_ELSE(3, (snake_margin - SIZE_HEALTH_HEIGHT) / 2);
  GRect rect_health = GRect(SIZE_GRID_OFFSET.x + SIZE_SCALE_FACTOR * ((width - SIZE_HEALTH_WIDTH) / 2),
                            SIZE_GRID_OFFSET.y + SIZE_SCALE_FACTOR * (snake_margin + SIZE_TIME_HEIGHT + health_offset),
                            SIZE_SCALE_FACTOR * SIZE_HEALTH_WIDTH,
                            SIZE_SCALE_FACTOR * SIZE_HEALTH_HEIGHT);

  layer_set_frame(s_snake_layer, rect_snake);
  layer_set_frame(s_date_layer, rect_date);
  layer_set_frame(s_health_layer, rect_health);
}

static void unobstracted_area_changed(AnimationProgress progress, void *context) {
  update_layout();
}

static void window_load(Window *window) {
  window_set_background_color(window, color_get_background());

  Layer *window_layer = window_get_root_layer(s_main_window);

  s_snake_layer = snake_layer_create(GRect(0, 0, 0, 0));
  layer_add_child(window_layer, s_snake_layer);

  s_date_layer = date_layer_create(GRect(0, 0, 0, 0));
  layer_add_child(window_layer, s_date_layer);

  s_health_layer = health_layer_create(GRect(0, 0, 0, 0));
  layer_add_child(window_layer, s_health_layer);

  update_layout();

  unobstructed_area_service_subscribe((UnobstructedAreaHandlers) {
    .change = unobstracted_area_changed
  }, NULL);
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
  date_layer_set_date(s_date_layer, 1900 + tick_time->tm_year, tick_time->tm_mon + 1, tick_time->tm_mday);
}

static void health_data_changed() {
  int32_t steps = health_get_steps();
  int16_t heart_rate = health_get_heart_rate();
  health_layer_set_data(s_health_layer, steps, heart_rate);
}

static void animation_complete() {
  tick_timer_service_subscribe(YEAR_UNIT | MONTH_UNIT | DAY_UNIT | HOUR_UNIT | MINUTE_UNIT, tick_handler);
}

static void window_appear(Window *window) {
  // prefer showing next minute a bit early over an update at the moment the animation completes
  time_t timestamp = time(NULL) + 2;
  tm *timeinfo = localtime(&timestamp);

  snake_layer_set_time(s_snake_layer, format_hour(timeinfo->tm_hour), timeinfo->tm_min);
  snake_layer_animate(s_snake_layer, animation_complete);

  date_layer_set_date(s_date_layer, 1900 + timeinfo->tm_year, timeinfo->tm_mon + 1, timeinfo->tm_mday);

  health_layer_set_data(s_health_layer, health_get_steps(), health_get_heart_rate());
  health_init(health_data_changed);
}

static void window_unload(Window *window) {
  snake_layer_destroy(s_snake_layer);
  date_layer_destroy(s_date_layer);
  health_layer_destroy(s_health_layer);
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
