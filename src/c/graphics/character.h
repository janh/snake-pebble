/*
 * Copyright (c) 2016 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include "common.h"

#include <pebble.h>
#include <inttypes.h>


typedef struct Character {
  uint8_t width;
  Pixel a[9][5];
} Character;


extern const Character CHARACTER_0;
extern const Character CHARACTER_1;
extern const Character CHARACTER_2;
extern const Character CHARACTER_3;
extern const Character CHARACTER_4;
extern const Character CHARACTER_5;
extern const Character CHARACTER_6;
extern const Character CHARACTER_7;
extern const Character CHARACTER_8;
extern const Character CHARACTER_9;

extern const Character CHARACTER_HYPHEN;
extern const Character CHARACTER_DOT;


void graphics_draw_character(GContext *ctx, GPoint pos, Character data);
void graphics_draw_character_array(GContext *ctx, GPoint pos, Character *data, size_t length);
