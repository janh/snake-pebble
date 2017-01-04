/*
 * Copyright (c) 2016 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "animation.h"

#include <pebble.h>


static DateLayer *s_date_layer;
static HealthLayer *s_health_layer;
static int16_t s_progress;
static AppTimer *s_timer;
static DateHealthLayersAnimationComplete s_callback;


static void date_health_layers_timer_cancel() {
  if (s_timer) {
    app_timer_cancel(s_timer);
    s_timer = NULL;
  }
}

static void date_health_layers_callback(void *context);

static void date_health_layers_timer_register() {
  s_timer = app_timer_register(33, date_health_layers_callback, NULL);
}

static void date_health_layers_callback(void *context) {
  s_timer = NULL;
  if (s_progress < 11) {
    s_progress += (s_progress < 8) ? 2 : 3;
    date_layer_set_anim_state(s_date_layer, s_progress);
    health_layer_set_anim_state(s_health_layer, s_progress);
    date_health_layers_timer_register();
  } else {
    if (s_callback != NULL) {
      s_callback();
    }
  }
}

void date_health_layers_animate(DateLayer* date_layer, HealthLayer* health_layer, DateHealthLayersAnimationComplete callback) {
  s_date_layer = date_layer;
  s_health_layer = health_layer;
  s_progress = 2;
  s_callback = callback;

  date_layer_set_anim_state(s_date_layer, s_progress);
  health_layer_set_anim_state(s_health_layer, s_progress);

  date_health_layers_timer_cancel();
  date_health_layers_timer_register();
}
