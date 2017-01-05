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
extern const Character CHARACTER_SPACE;

extern const Character CHARACTER_A;
extern const Character CHARACTER_B;
extern const Character CHARACTER_C;
extern const Character CHARACTER_D;
extern const Character CHARACTER_E;
extern const Character CHARACTER_G;
extern const Character CHARACTER_H;
extern const Character CHARACTER_I;
extern const Character CHARACTER_K;
extern const Character CHARACTER_L;
extern const Character CHARACTER_N;
extern const Character CHARACTER_O;
extern const Character CHARACTER_P;
extern const Character CHARACTER_R;
extern const Character CHARACTER_T;
extern const Character CHARACTER_U;
extern const Character CHARACTER_V;
extern const Character CHARACTER_Y;

extern const Character *CHARACTER_LETTERS[26];

extern const Character CHARACTER_CAPITAL_A;
extern const Character CHARACTER_CAPITAL_D;
extern const Character CHARACTER_CAPITAL_F;
extern const Character CHARACTER_CAPITAL_J;
extern const Character CHARACTER_CAPITAL_M;
extern const Character CHARACTER_CAPITAL_N;
extern const Character CHARACTER_CAPITAL_O;
extern const Character CHARACTER_CAPITAL_S;
extern const Character CHARACTER_CAPITAL_T;
extern const Character CHARACTER_CAPITAL_W;

extern const Character *CHARACTER_CAPITAL_LETTERS[26];

extern const Character CHARACTER_HEART;
extern const Character CHARACTER_FOOT;

void graphics_draw_character(GContext *ctx, GPoint pos, Character data, int16_t min, int16_t max);
void graphics_draw_character_array(GContext *ctx, GPoint pos, Character *data, size_t length, int16_t min, int16_t max);
void graphics_draw_character_array_right(GContext *ctx, GPoint pos, Character *data, size_t length, int16_t min, int16_t max);
int16_t graphics_get_character_array_width(Character *data, size_t length);
size_t graphics_get_character_array_from_text(Character *buffer, size_t length, const char *text);
size_t graphics_get_character_array_from_integer(Character *buffer, size_t length, bool padding, uint32_t integer);
