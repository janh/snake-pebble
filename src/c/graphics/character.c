/*
 * Copyright (c) 2016-2017 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdbool.h>

#include "character.h"
#include "../lib/settings.h"
#include "../lib/sizes.h"


#define CHARACTER(length,length_2x,fixed_spacing,index) {length, length_2x, fixed_spacing, &s_character_data[index], &s_character_data_2x[index]}

#define CHARACTER_ROW_ITEM(row,i) row & (1 << (7 - (i)))
#define CHARACTER_ROW_ITEM_2X(row,i) row & (1 << ((i < 8) ? 7-(i) : 8+15-(i)))


#define CHARACTER_COUNT 72
#define INDEX_NUMBERS_START 0
#define INDEX_LETTERS_CAPITAL_START 10
#define INDEX_LETTERS_START 36
#define INDEX_PUNCTUATION_START 62
#define INDEX_ICONS_START 67


static bool s_loaded = false;
static CharacterData s_character_data[CHARACTER_COUNT];
static CharacterData2X s_character_data_2x[CHARACTER_COUNT];


const Character CHARACTER_0 = CHARACTER(5, 10, true, INDEX_NUMBERS_START + 0);
const Character CHARACTER_1 = CHARACTER(5, 10, true, INDEX_NUMBERS_START + 1);
const Character CHARACTER_2 = CHARACTER(5, 10, true, INDEX_NUMBERS_START + 2);
const Character CHARACTER_3 = CHARACTER(5, 10, true, INDEX_NUMBERS_START + 3);
const Character CHARACTER_4 = CHARACTER(5, 10, true, INDEX_NUMBERS_START + 4);
const Character CHARACTER_5 = CHARACTER(5, 10, true, INDEX_NUMBERS_START + 5);
const Character CHARACTER_6 = CHARACTER(5, 10, true, INDEX_NUMBERS_START + 6);
const Character CHARACTER_7 = CHARACTER(5, 10, true, INDEX_NUMBERS_START + 7);
const Character CHARACTER_8 = CHARACTER(5, 10, true, INDEX_NUMBERS_START + 8);
const Character CHARACTER_9 = CHARACTER(5, 10, true, INDEX_NUMBERS_START + 9);

const Character *CHARACTER_NUMBERS[10] = {&CHARACTER_0,
                                          &CHARACTER_1,
                                          &CHARACTER_2,
                                          &CHARACTER_3,
                                          &CHARACTER_4,
                                          &CHARACTER_5,
                                          &CHARACTER_6,
                                          &CHARACTER_7,
                                          &CHARACTER_8,
                                          &CHARACTER_9};


const Character CHARACTER_HYPHEN = CHARACTER(3, 6, true, INDEX_PUNCTUATION_START + 0);

const Character CHARACTER_DOT = CHARACTER(3, 6, true, INDEX_PUNCTUATION_START + 1);
const Character CHARACTER_DOT_NARROW = CHARACTER(1, 2, true, INDEX_PUNCTUATION_START + 1);
const Character CHARACTER_DOT_WIDE = CHARACTER(5, 10, true, INDEX_PUNCTUATION_START + 1);

const Character CHARACTER_COMMA_NARROW = CHARACTER(1, 2, true, INDEX_PUNCTUATION_START + 2);

const Character CHARACTER_SLASH = CHARACTER(3, 6, true, INDEX_PUNCTUATION_START + 3);

const Character CHARACTER_SPACE = CHARACTER(3, 6, true, INDEX_PUNCTUATION_START + 4);
const Character CHARACTER_SPACE_NARROW = CHARACTER(2, 4, true, INDEX_PUNCTUATION_START + 4);
const Character CHARACTER_SPACE_WIDE = CHARACTER(5, 10, true, INDEX_PUNCTUATION_START + 4);


const Character CHARACTER_A = CHARACTER(4, 8, false, INDEX_LETTERS_START + 0);
const Character CHARACTER_B = CHARACTER(4, 8, false, INDEX_LETTERS_START + 1);
const Character CHARACTER_C = CHARACTER(4, 8, false, INDEX_LETTERS_START + 2);
const Character CHARACTER_D = CHARACTER(4, 8, false, INDEX_LETTERS_START + 3);
const Character CHARACTER_E = CHARACTER(4, 8, false, INDEX_LETTERS_START + 4);
const Character CHARACTER_F = CHARACTER(4, 8, false, INDEX_LETTERS_START + 5);
const Character CHARACTER_G = CHARACTER(4, 8, false, INDEX_LETTERS_START + 6);
const Character CHARACTER_H = CHARACTER(4, 8, false, INDEX_LETTERS_START + 7);
const Character CHARACTER_I = CHARACTER(1, 2, false, INDEX_LETTERS_START + 8);
const Character CHARACTER_J = CHARACTER(2, 4, false, INDEX_LETTERS_START + 9);
const Character CHARACTER_K = CHARACTER(4, 8, false, INDEX_LETTERS_START + 10);
const Character CHARACTER_L = CHARACTER(2, 4, false, INDEX_LETTERS_START + 11);
const Character CHARACTER_M = CHARACTER(5, 10, false, INDEX_LETTERS_START + 12);
const Character CHARACTER_N = CHARACTER(4, 8, false, INDEX_LETTERS_START + 13);
const Character CHARACTER_O = CHARACTER(4, 8, false, INDEX_LETTERS_START + 14);
const Character CHARACTER_P = CHARACTER(4, 8, false, INDEX_LETTERS_START + 15);
const Character CHARACTER_Q = CHARACTER(4, 8, false, INDEX_LETTERS_START + 16);
const Character CHARACTER_R = CHARACTER(4, 8, false, INDEX_LETTERS_START + 17);
const Character CHARACTER_S = CHARACTER(4, 8, false, INDEX_LETTERS_START + 18);
const Character CHARACTER_T = CHARACTER(4, 8, false, INDEX_LETTERS_START + 19);
const Character CHARACTER_U = CHARACTER(4, 8, false, INDEX_LETTERS_START + 20);
const Character CHARACTER_V = CHARACTER(5, 10, false, INDEX_LETTERS_START + 21);
const Character CHARACTER_W = CHARACTER(5, 10, false, INDEX_LETTERS_START + 22);
const Character CHARACTER_X = CHARACTER(5, 10, false, INDEX_LETTERS_START + 23);
const Character CHARACTER_Y = CHARACTER(4, 8, false, INDEX_LETTERS_START + 24);
const Character CHARACTER_Z = CHARACTER(4, 8, false, INDEX_LETTERS_START + 25);

const Character *CHARACTER_LETTERS[26] = {&CHARACTER_A,
                                          &CHARACTER_B,
                                          &CHARACTER_C,
                                          &CHARACTER_D,
                                          &CHARACTER_E,
                                          &CHARACTER_F,
                                          &CHARACTER_G,
                                          &CHARACTER_H,
                                          &CHARACTER_I,
                                          &CHARACTER_J,
                                          &CHARACTER_K,
                                          &CHARACTER_L,
                                          &CHARACTER_M,
                                          &CHARACTER_N,
                                          &CHARACTER_O,
                                          &CHARACTER_P,
                                          &CHARACTER_Q,
                                          &CHARACTER_R,
                                          &CHARACTER_S,
                                          &CHARACTER_T,
                                          &CHARACTER_U,
                                          &CHARACTER_V,
                                          &CHARACTER_W,
                                          &CHARACTER_X,
                                          &CHARACTER_Y,
                                          &CHARACTER_Z};


const Character CHARACTER_CAPITAL_A = CHARACTER(5, 10, false, INDEX_LETTERS_CAPITAL_START + 0);
const Character CHARACTER_CAPITAL_B = CHARACTER(5, 10, false, INDEX_LETTERS_CAPITAL_START + 1);
const Character CHARACTER_CAPITAL_C = CHARACTER(5, 10, false, INDEX_LETTERS_CAPITAL_START + 2);
const Character CHARACTER_CAPITAL_D = CHARACTER(5, 10, false, INDEX_LETTERS_CAPITAL_START + 3);
const Character CHARACTER_CAPITAL_E = CHARACTER(5, 10, false, INDEX_LETTERS_CAPITAL_START + 4);
const Character CHARACTER_CAPITAL_F = CHARACTER(5, 10, false, INDEX_LETTERS_CAPITAL_START + 5);
const Character CHARACTER_CAPITAL_G = CHARACTER(5, 10, false, INDEX_LETTERS_CAPITAL_START + 6);
const Character CHARACTER_CAPITAL_H = CHARACTER(5, 10, false, INDEX_LETTERS_CAPITAL_START + 7);
const Character CHARACTER_CAPITAL_I = CHARACTER(3, 6, false, INDEX_LETTERS_CAPITAL_START + 8);
const Character CHARACTER_CAPITAL_J = CHARACTER(5, 10, false, INDEX_LETTERS_CAPITAL_START + 9);
const Character CHARACTER_CAPITAL_K = CHARACTER(5, 10, false, INDEX_LETTERS_CAPITAL_START + 10);
const Character CHARACTER_CAPITAL_L = CHARACTER(5, 10, false, INDEX_LETTERS_CAPITAL_START + 11);
const Character CHARACTER_CAPITAL_M = CHARACTER(7, 14, false, INDEX_LETTERS_CAPITAL_START + 12);
const Character CHARACTER_CAPITAL_N = CHARACTER(6, 12, false, INDEX_LETTERS_CAPITAL_START + 13);
const Character CHARACTER_CAPITAL_O = CHARACTER(5, 10, false, INDEX_LETTERS_CAPITAL_START + 14);
const Character CHARACTER_CAPITAL_P = CHARACTER(5, 10, false, INDEX_LETTERS_CAPITAL_START + 15);
const Character CHARACTER_CAPITAL_Q = CHARACTER(5, 10, false, INDEX_LETTERS_CAPITAL_START + 16);
const Character CHARACTER_CAPITAL_R = CHARACTER(5, 10, false, INDEX_LETTERS_CAPITAL_START + 17);
const Character CHARACTER_CAPITAL_S = CHARACTER(5, 10, false, INDEX_LETTERS_CAPITAL_START + 18);
const Character CHARACTER_CAPITAL_T = CHARACTER(5, 10, false, INDEX_LETTERS_CAPITAL_START + 19);
const Character CHARACTER_CAPITAL_U = CHARACTER(5, 10, false, INDEX_LETTERS_CAPITAL_START + 20);
const Character CHARACTER_CAPITAL_V = CHARACTER(5, 10, false, INDEX_LETTERS_CAPITAL_START + 21);
const Character CHARACTER_CAPITAL_W = CHARACTER(7, 14, false, INDEX_LETTERS_CAPITAL_START + 22);
const Character CHARACTER_CAPITAL_X = CHARACTER(5, 10, false, INDEX_LETTERS_CAPITAL_START + 23);
const Character CHARACTER_CAPITAL_Y = CHARACTER(5, 10, false, INDEX_LETTERS_CAPITAL_START + 24);
const Character CHARACTER_CAPITAL_Z = CHARACTER(5, 10, false, INDEX_LETTERS_CAPITAL_START + 25);

const Character *CHARACTER_CAPITAL_LETTERS[26] = {&CHARACTER_CAPITAL_A,
                                                  &CHARACTER_CAPITAL_B,
                                                  &CHARACTER_CAPITAL_C,
                                                  &CHARACTER_CAPITAL_D,
                                                  &CHARACTER_CAPITAL_E,
                                                  &CHARACTER_CAPITAL_F,
                                                  &CHARACTER_CAPITAL_G,
                                                  &CHARACTER_CAPITAL_H,
                                                  &CHARACTER_CAPITAL_I,
                                                  &CHARACTER_CAPITAL_J,
                                                  &CHARACTER_CAPITAL_K,
                                                  &CHARACTER_CAPITAL_L,
                                                  &CHARACTER_CAPITAL_M,
                                                  &CHARACTER_CAPITAL_N,
                                                  &CHARACTER_CAPITAL_O,
                                                  &CHARACTER_CAPITAL_P,
                                                  &CHARACTER_CAPITAL_Q,
                                                  &CHARACTER_CAPITAL_R,
                                                  &CHARACTER_CAPITAL_S,
                                                  &CHARACTER_CAPITAL_T,
                                                  &CHARACTER_CAPITAL_U,
                                                  &CHARACTER_CAPITAL_V,
                                                  &CHARACTER_CAPITAL_W,
                                                  &CHARACTER_CAPITAL_X,
                                                  &CHARACTER_CAPITAL_Y,
                                                  &CHARACTER_CAPITAL_Z};


const Character CHARACTER_HEART = CHARACTER(5, 10, true, INDEX_ICONS_START + 0);
const Character CHARACTER_FOOT = CHARACTER(5, 10, true, INDEX_ICONS_START + 1);
const Character CHARACTER_BATTERY = CHARACTER(5, 10, true, INDEX_ICONS_START + 2);
const Character CHARACTER_CHARGING = CHARACTER(5, 10, true, INDEX_ICONS_START + 3);
const Character CHARACTER_CALENDAR = CHARACTER(5, 10, true, INDEX_ICONS_START + 4);


static void load_resource(uint32_t id, uint8_t *buffer, size_t length) {
  ResHandle handle = resource_get_handle(id);
  size_t size = resource_size(handle);
  if (length < size) {
    resource_load_byte_range(handle, size - length, buffer, size);
  }
}

static void load_character_data() {
  load_resource(RESOURCE_ID_CHARACTERS, (uint8_t *)s_character_data, sizeof(s_character_data));
  load_resource(RESOURCE_ID_CHARACTERS_2X, (uint8_t *)s_character_data_2x, sizeof(s_character_data_2x));
  s_loaded = true;
}


static void graphics_draw_scaled_rect(GContext *ctx, GPoint pos) {
  GRect rect = GRect(pos.x, pos.y, SIZE_SCALE_FACTOR, SIZE_SCALE_FACTOR);
  graphics_fill_rect(ctx, rect, 0, GCornerNone);
}

static void graphics_draw_character(GContext *ctx, GPoint pos, ExtendedCharacter data, int16_t min, int16_t max) {
  if (!s_loaded) {
    load_character_data();
  }

  if (min < 0) { min = 0; }
  if (max < 0) { max = 11; }

  graphics_context_set_fill_color(ctx, settings_get_color_text());
  graphics_context_set_stroke_color(ctx, settings_get_color_text());

  const Character *character = data.character;

  bool high_resolution_2x = (settings_get_graphics_high_resolution() && SIZE_SCALE_FACTOR == 2);

  // draw character
  if (high_resolution_2x) {
    for (int16_t j = 0; j < 22; j++) {
      if (j >= 2 && j >= 2*min && j < 2*max) {
        CharacterRow2X row = character->b->r[j-2];
        for (int16_t i = 0; i < character->width_2x; i++) {
          if (CHARACTER_ROW_ITEM_2X(row, i)) {
            GPoint point = GPoint(pos.x + i, pos.y + j);
            graphics_draw_pixel(ctx, point);
          }
        }
      }
    }
  } else {
    for (int j = 0; j < 11; j++) {
      if (j >= 1 && j >= min && j < max) {
        CharacterRow row = character->a->r[j-1];
        for (uint8_t i = 0; i < character->width; i++) {
          if (CHARACTER_ROW_ITEM(row, i)) {
            GPoint point = GPoint(pos.x + SIZE_SCALE_FACTOR * i, pos.y + SIZE_SCALE_FACTOR * j);
            graphics_draw_scaled_rect(ctx, point);
          }
        }
      }
    }
  }

  // draw diacritic
  Diacritic diacritic = data.diacritic;
  int diacritics_line = (character->a->r[0] == 0) ? 2 : 0;
  if (diacritics_line >= min && diacritics_line < max && diacritic != DIACRITIC_NONE) {
    if (diacritic == DIACRITIC_DIAERESIS_UMLAUT) {
      int16_t width = high_resolution_2x ? character->width_2x : SIZE_SCALE_FACTOR * character->width;
      GPoint point = GPoint(pos.x, pos.y + SIZE_SCALE_FACTOR * diacritics_line);

      graphics_context_set_fill_color(ctx, settings_get_color_background());
      graphics_fill_rect(ctx, GRect(point.x, point.y, width, SIZE_SCALE_FACTOR), 0, GCornerNone);
      graphics_context_set_fill_color(ctx, settings_get_color_text());

      int16_t inset = (width - SIZE_SCALE_FACTOR * 3) / 2;
      if (!high_resolution_2x) {
        inset = (inset % 2 == 0) ? inset : inset - 1;
      }

      point.x = pos.x + inset;
      graphics_draw_scaled_rect(ctx, point);
      point.x = pos.x + width - SIZE_SCALE_FACTOR - inset;
      graphics_draw_scaled_rect(ctx, point);
    }
  }
}

static int16_t graphics_get_character_spacing(const Character *left, const Character *right) {
  if (left == NULL || right == NULL) {
    return 0;
  }

  int16_t dist_left, dist_right, dist;

  if (!left->fixed_spacing && !right->fixed_spacing) {
    if (settings_get_graphics_high_resolution() && SIZE_SCALE_FACTOR == 2) {

      int16_t min = left->width_2x + right->width_2x;
      int16_t dists[20];
      int16_t dists_left[20];
      int16_t dists_right[20];

      // calculate individual distances and minimum distance
      for (size_t i = 0; i < 20; i++) {
        CharacterRow2X row_left = left->b->r[i];
        CharacterRow2X row_right = right->b->r[i];

        dist_left = -1;
        for (int j = 0; j < left->width_2x; j++) {
          if (CHARACTER_ROW_ITEM_2X(row_left, left->width_2x-1-j)) {
            dist_left = j;
            break;
          }
        }

        dist_right = -1;
        for (int j = 0; j < right->width_2x; j++) {
          if (CHARACTER_ROW_ITEM_2X(row_right, j)) {
            dist_right = j;
            break;
          }
        }

        if (dist_left >= 0 && dist_right >= 0) {
          dist = dist_left + dist_right;
          if (dist < min) {
            min = dist;
          }
        } else {
          dist = -1;
        }

        dists[i] = dist;
        dists_left[i] = dist_left;
        dists_right[i] = dist_right;
      }

      int16_t dist_last = -1;
      int16_t sum = 0;
      int16_t count = 0;
      int16_t count_0 = 0;
      int16_t count_0_max = 0;
      int16_t count_4plus = 0;

      // calculate sum of distances and count for rows with normalized distance <= 3,
      // as well as consecutive number of 0 and total number of rows with distance > 3
      for (size_t i = 0; i < 20; i++) {
        dist_last = dist;
        dist = dists[i];
        if (dist >= 0 && dist - min <= 3) {
          sum += dist;
          count++;
        }
        if (dist - min == 0) {
          if (dist_last == 0) {
            count_0++;
          } else {
            count_0 = 1;
          }
          if (count_0 > count_0_max) {
            count_0_max = count_0;
          }
        }
        if (dist - min > 3) {
          count_4plus++;
        }
      }

      // rounded down average of low distances
      if (count > 0) {
        sum /= count;
      }

      // heuristic to balance out cases with large differences in distances
      if (sum == min && count_0_max <= 2 && count_4plus > 2) {
        sum += 1;
      }

      // set space with lower limit
      int16_t space = (sum <= 2) ? 4 - sum : 2;

      // ensure there is enough distance in the end, also on adjacent lines
      for (size_t i = 0; i < 20; i++) {
        if (dists[i] >= 0 && dists[i] + space < 3) {
          space++;
        }
        if (i > 0) {
          if (dists_left[i-1] >= 0 && dists_right[i] >= 0) {
            if (dists_left[i-1] + dists_right[i] + space < 3) {
              space++;
            }
          }
          if (dists_left[i] >= 0 && dists_right[i-1] >= 0) {
            if (dists_left[i] + dists_right[i-1] + space < 3) {
              space++;
            }
          }
        }
      }

      return space;

    } else {

      int16_t min = SIZE_SCALE_FACTOR;

      for (size_t i = 0; i < 10; i++) {
        CharacterRow row_left = left->a->r[i];
        CharacterRow row_right = right->a->r[i];

        dist_left = left->width;
        for (int j = 0; j < left->width; j++) {
          if (CHARACTER_ROW_ITEM(row_left, left->width-1-j)) {
            dist_left = SIZE_SCALE_FACTOR * j;
            break;
          }
        }

        dist_right = right->width;
        for (int j = 0; j < right->width; j++) {
          if (CHARACTER_ROW_ITEM(row_right, j)) {
            dist_right = SIZE_SCALE_FACTOR * j;
            break;
          }
        }

        dist = dist_left + dist_right;
        if (dist < min) {
          min = dist;
        }
      }

      return 2 * SIZE_SCALE_FACTOR - min;

    }
  }

  return 2 * SIZE_SCALE_FACTOR;
}

void graphics_draw_character_array(GContext *ctx, GPoint pos, ExtendedCharacter *data, size_t length, int16_t min, int16_t max) {
  bool high_resolution_2x = (settings_get_graphics_high_resolution() && SIZE_SCALE_FACTOR == 2);

  pos.x *= SIZE_SCALE_FACTOR;
  pos.y *= SIZE_SCALE_FACTOR;

  for (size_t i = 0; i < length; i++) {
    ExtendedCharacter item = data[i];
    graphics_draw_character(ctx, pos, item, min, max);
    pos.x += high_resolution_2x ? item.character->width_2x : SIZE_SCALE_FACTOR * item.character->width;

    const Character *character_next = (i + 1 < length) ? data[i+1].character : NULL;
    pos.x += graphics_get_character_spacing(item.character, character_next);
  }
}

void graphics_draw_character_array_right(GContext *ctx, GPoint pos, ExtendedCharacter *data, size_t length, int16_t min, int16_t max) {
  bool high_resolution_2x = (settings_get_graphics_high_resolution() && SIZE_SCALE_FACTOR == 2);

  pos.x *= SIZE_SCALE_FACTOR;
  pos.y *= SIZE_SCALE_FACTOR;

  for (size_t i = length; i > 0; i--) {
    ExtendedCharacter item = data[i-1];
    pos.x -= high_resolution_2x ? item.character->width_2x : SIZE_SCALE_FACTOR * item.character->width;
    graphics_draw_character(ctx, pos, item, min, max);

    const Character *character_next = (i - 1 > 0) ? data[i-2].character : NULL;
    pos.x -= graphics_get_character_spacing(character_next, item.character);
  }
}

size_t graphics_get_character_array_from_text(ExtendedCharacter *buffer, size_t length, const char *text) {
  size_t pos_src = 0;
  size_t pos_dst = 0;
  bool search_diacritic = false;

  while (pos_dst < length) {
    char c = text[pos_src];
    pos_src++;

    if (search_diacritic) {
      search_diacritic = false;
      if (c == '\x01') {
        buffer[pos_dst].diacritic = DIACRITIC_DIAERESIS_UMLAUT;
      }
      pos_dst++;
    }

    if (c == '\0') {
      return pos_dst;
    }

    if (c >= '\x20' && c <= '\x7F') {
      const Character *character = NULL;

      if (c >= 'A' && c <= 'Z') {
        character = CHARACTER_CAPITAL_LETTERS[c - 'A'];
      } else if (c >= 'a' && c <= 'z') {
        character = CHARACTER_LETTERS[c - 'a'];
      } else if (c >= '0' && c <= '9') {
        character = CHARACTER_NUMBERS[c - '0'];
      }

      if (character != NULL) {
        buffer[pos_dst] = (ExtendedCharacter) {character, DIACRITIC_NONE};
      } else {
        buffer[pos_dst] = (ExtendedCharacter) {&CHARACTER_DOT_NARROW, DIACRITIC_NONE};
      }

      search_diacritic = true;
    }
  }

  return length;
}

size_t graphics_get_character_array_from_integer(ExtendedCharacter *buffer, size_t length, bool padding, uint32_t integer) {
  if (!padding) {
    size_t count = 1;
    uint32_t value = integer / 10;
    while (count < length) {
      if (value == 0) {
        break;
      }
      value /= 10;
      count++;
    }
    length = count;
  }

  for (size_t i = length; i > 0; i--) {
    buffer[i-1] = (ExtendedCharacter) {CHARACTER_NUMBERS[integer % 10], DIACRITIC_NONE};
    integer /= 10;
  }

  return length;
}
