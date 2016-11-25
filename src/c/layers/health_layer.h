/*
 * Copyright (c) 2016 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once


#include <pebble.h>


typedef Layer HealthLayer;

HealthLayer* health_layer_create(GRect frame);
void health_layer_destroy(HealthLayer* health_layer);
void health_layer_set_data(HealthLayer* health_layer, int32_t steps, int16_t heart_rate);
