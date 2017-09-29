/*
 * Copyright (c) 2016-2017 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once


#include <inttypes.h>
#include <pebble.h>

#include "../graphics/character.h"


typedef struct ContentLayerItem {
  const Character *icon;
  int32_t value;
} ContentLayerItem;

typedef Layer ContentLayer;

ContentLayer* content_layer_create(GRect frame);
void content_layer_destroy(ContentLayer* content_layer);
void content_layer_set_data(ContentLayer* content_layer, ContentLayerItem left, ContentLayerItem right);
void content_layer_set_anim_state(ContentLayer* content_layer, int16_t anim_state);
