/*
 * Copyright (c) 2016-2017 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "main_window.h"
#include "../graphics/character.h"
#include "../layers/snake_layer.h"
#include "../layers/content_layer.h"
#include "../layers/date_layer.h"
#include "../layers/animation.h"
#include "../lib/settings.h"
#include "../lib/sizes.h"
#include "../lib/data.h"
#include "../lib/demo.h"

#include <pebble.h>
#include <stdbool.h>
#include <inttypes.h>


static Window *s_main_window;
static Layer *s_snake_layer;
static Layer *s_date_layer;
static Layer *s_content_layer;


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

  int16_t content_offset = PBL_IF_ROUND_ELSE(3, (snake_margin - SIZE_CONTENT_HEIGHT) / 2);
  GRect rect_content = GRect(SIZE_GRID_OFFSET.x + SIZE_SCALE_FACTOR * ((width - SIZE_CONTENT_WIDTH) / 2),
                            SIZE_GRID_OFFSET.y + SIZE_SCALE_FACTOR * (snake_margin + SIZE_TIME_HEIGHT + content_offset),
                            SIZE_SCALE_FACTOR * SIZE_CONTENT_WIDTH,
                            SIZE_SCALE_FACTOR * SIZE_CONTENT_HEIGHT);

  layer_set_frame(s_snake_layer, rect_snake);
  layer_set_frame(s_date_layer, rect_date);
  layer_set_frame(s_content_layer, rect_content);
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

static void update_date_layer(tm *time) {
  # if DEMO_MODE
    snake_layer_set_time(s_snake_layer, 9, 35);
    date_layer_set_date(s_date_layer, 2016, 10, 23, 0);
  # else
    snake_layer_set_time(s_snake_layer, format_hour(time->tm_hour), time->tm_min);
    date_layer_set_date(s_date_layer, 1900 + time->tm_year, time->tm_mon + 1, time->tm_mday, time->tm_wday);
  # endif
}

static ContentLayerItem get_content_layer_item(ContentType type) {
  ContentLayerItem item;

  int32_t heart_rate;
  uint8_t battery_percent;
  bool battery_charging;

  time_t timestamp;
  tm *timeinfo;

  switch (type) {

  case CONTENT_STEPS:
    item.icon = &CHARACTER_FOOT;
    item.value = data_get_steps();
    break;

  case CONTENT_HEART_RATE:
    item.icon = &CHARACTER_HEART;
    item.value = data_get_heart_rate();
    break;

  case CONTENT_BATTERY:
    item.icon = data_get_battery_charging() ? &CHARACTER_CHARGING : &CHARACTER_BATTERY;
    item.value = data_get_battery_percent();
    break;

  case CONTENT_HEART_RATE_BATTERY:
    heart_rate = data_get_heart_rate();
    battery_percent = data_get_battery_percent();
    battery_charging = data_get_battery_charging();
    if (battery_charging || battery_percent <= 15 || heart_rate <= 0) {
      item.icon = battery_charging ? &CHARACTER_CHARGING : &CHARACTER_BATTERY;
      item.value = battery_percent;
    } else {
      item.icon = &CHARACTER_HEART;
      item.value = heart_rate;
    }
    break;

  case CONTENT_DAY_OF_YEAR:
    # if DEMO_MODE
      item.icon = &CHARACTER_CALENDAR;
      item.value = 297;
    # else
      timestamp = time(NULL) + 2;
      timeinfo = localtime(&timestamp);
      item.icon = &CHARACTER_CALENDAR;
      item.value = timeinfo->tm_yday + 1;
    # endif
    break;

  }

  return item;
}

static void update_content_layer() {
  ContentLayerItem left = get_content_layer_item(settings_get_content_left());
  ContentLayerItem right = get_content_layer_item(settings_get_content_right());
  content_layer_set_data(s_content_layer, left, right);
}

static void unobstracted_area_changed(AnimationProgress progress, void *context) {
  update_layout();
}

static void window_load(Window *window) {
  window_set_background_color(window, settings_get_color_background());

  Layer *window_layer = window_get_root_layer(s_main_window);

  s_snake_layer = snake_layer_create(GRect(0, 0, 0, 0));
  layer_add_child(window_layer, s_snake_layer);

  s_date_layer = date_layer_create(GRect(0, 0, 0, 0));
  layer_add_child(window_layer, s_date_layer);

  s_content_layer = content_layer_create(GRect(0, 0, 0, 0));
  layer_add_child(window_layer, s_content_layer);

  update_layout();

  unobstructed_area_service_subscribe((UnobstructedAreaHandlers) {
    .change = unobstracted_area_changed
  }, NULL);
}

static void tick_handler(tm *tick_time, TimeUnits units_changed) {
  update_date_layer(tick_time);

  ContentType content_left = settings_get_content_left();
  ContentType content_right = settings_get_content_right();

  if (content_left == CONTENT_DAY_OF_YEAR || content_right == CONTENT_DAY_OF_YEAR) {
    update_content_layer();
  }
}

static void data_changed(DataTypeMask types) {
  update_content_layer();
}

static void update_events() {
  ContentType content_left = settings_get_content_left();
  ContentType content_right = settings_get_content_right();

  DataTypeMask data_types = 0;
  if (content_left == CONTENT_STEPS || content_right == CONTENT_STEPS) {
    data_types |= DATA_TYPE_STEPS;
  }
  if (content_left == CONTENT_HEART_RATE || content_right == CONTENT_HEART_RATE
      || content_left == CONTENT_HEART_RATE_BATTERY || content_right == CONTENT_HEART_RATE_BATTERY) {
    data_types |= DATA_TYPE_HEART_RATE;
  }
  if (content_left == CONTENT_BATTERY || content_right == CONTENT_BATTERY
      || content_left == CONTENT_HEART_RATE_BATTERY || content_right == CONTENT_HEART_RATE_BATTERY) {
    data_types |= DATA_TYPE_BATTERY;
  }

  data_events_init(data_types, data_changed);
}

static void settings_changed() {
  window_set_background_color(s_main_window, settings_get_color_background());

  update_events();
  update_content_layer();

  Layer *window_layer = window_get_root_layer(s_main_window);
  layer_mark_dirty(window_layer);
}

static void date_content_animation_complete() {
  tick_timer_service_subscribe(YEAR_UNIT | MONTH_UNIT | DAY_UNIT | HOUR_UNIT | MINUTE_UNIT, tick_handler);
  update_events();
}

static void snake_animation_complete() {
  date_content_layers_animate(s_date_layer, s_content_layer, date_content_animation_complete);
}

static void window_appear(Window *window) {
  settings_set_callback(settings_changed);

  // prefer showing next minute a bit early over an update at the moment the animation completes
  time_t timestamp = time(NULL) + 2;
  tm *timeinfo = localtime(&timestamp);

  update_date_layer(timeinfo);
  update_content_layer();

  snake_layer_animate(s_snake_layer, snake_animation_complete);
}

static void window_disappear(Window *window) {
  settings_set_callback(NULL);
}

static void window_unload(Window *window) {
  snake_layer_destroy(s_snake_layer);
  date_layer_destroy(s_date_layer);
  content_layer_destroy(s_content_layer);
  window_destroy(s_main_window);
  s_main_window = NULL;
}

void main_window_push() {
  if (!s_main_window) {
    s_main_window = window_create();
    window_set_window_handlers(s_main_window, (WindowHandlers) {
      .load = window_load,
      .appear = window_appear,
      .disappear = window_disappear,
      .unload = window_unload,
    });
  }
  window_stack_push(s_main_window, true);
}
