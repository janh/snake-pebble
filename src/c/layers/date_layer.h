/*
 * Copyright (c) 2016 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once


#include <pebble.h>


typedef Layer DateLayer;

DateLayer* date_layer_create(GRect frame);
void date_layer_destroy(DateLayer* date_layer);
void date_layer_set_date(DateLayer* date_layer, uint16_t year, uint8_t month, uint8_t day);
void date_layer_set_anim_state(DateLayer* date_layer, int16_t anim_state);
