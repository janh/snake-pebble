/*
 * Copyright (c) 2016-2017 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <pebble.h>
#include <inttypes.h>


typedef uint8_t CharacterRow;

typedef struct Character {
  uint8_t width;
  CharacterRow a[10];
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

extern const Character *CHARACTER_NUMBERS[10];

extern const Character CHARACTER_HYPHEN;
extern const Character CHARACTER_DOT;
extern const Character CHARACTER_DOT_NARROW;
extern const Character CHARACTER_SLASH;

extern const Character CHARACTER_K;

extern const Character CHARACTER_HEART;
extern const Character CHARACTER_FOOT;

void graphics_draw_character(GContext *ctx, GPoint pos, Character data, int16_t min, int16_t max);
void graphics_draw_character_array(GContext *ctx, GPoint pos, Character *data, size_t length, int16_t min, int16_t max);
void graphics_draw_character_array_right(GContext *ctx, GPoint pos, Character *data, size_t length, int16_t min, int16_t max);
int16_t graphics_get_character_array_width(Character *data, size_t length);
