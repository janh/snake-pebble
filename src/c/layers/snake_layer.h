/*
 * Copyright (c) 2016 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once


#include <pebble.h>


typedef Layer SnakeLayer;

SnakeLayer* snake_layer_create(GRect frame);
void snake_layer_destroy(SnakeLayer* snake_layer);
