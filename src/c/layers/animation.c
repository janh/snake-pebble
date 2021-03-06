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
static ContentLayer *s_content_layer;
static int16_t s_progress;
static AppTimer *s_timer;
static DateContentLayersAnimationComplete s_callback;


static void date_content_layers_timer_cancel() {
  if (s_timer) {
    app_timer_cancel(s_timer);
    s_timer = NULL;
  }
}

static void date_content_layers_callback(void *context);

static void date_content_layers_timer_register() {
  s_timer = app_timer_register(33, date_content_layers_callback, NULL);
}

static void date_content_layers_callback(void *context) {
  s_timer = NULL;
  if (s_progress < 11) {
    s_progress += (s_progress < 8) ? 2 : 3;
    date_layer_set_anim_state(s_date_layer, s_progress);
    content_layer_set_anim_state(s_content_layer, s_progress);
    date_content_layers_timer_register();
  } else {
    if (s_callback != NULL) {
      s_callback();
    }
  }
}

void date_content_layers_animate(DateLayer* date_layer, ContentLayer* content_layer, DateContentLayersAnimationComplete callback) {
  s_date_layer = date_layer;
  s_content_layer = content_layer;
  s_progress = 2;
  s_callback = callback;

  date_layer_set_anim_state(s_date_layer, s_progress);
  content_layer_set_anim_state(s_content_layer, s_progress);

  date_content_layers_timer_cancel();
  date_content_layers_timer_register();
}
