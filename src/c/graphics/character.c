/*
 * Copyright (c) 2016 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "character.h"
#include "../lib/color.h"
#include "../lib/sizes.h"


const Character CHARACTER_0 = {5, {{ZERO, ONE , ONE , ONE , ZERO},
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ONE , ONE , ONE , ZERO}}};

const Character CHARACTER_1 = {5, {{ZERO, ZERO, ZERO, ONE , ZERO},
                                   {ZERO, ZERO, ONE , ONE , ZERO},
                                   {ZERO, ONE , ZERO, ONE , ZERO},
                                   {ZERO, ZERO, ZERO, ONE , ZERO},
                                   {ZERO, ZERO, ZERO, ONE , ZERO},
                                   {ZERO, ZERO, ZERO, ONE , ZERO},
                                   {ZERO, ZERO, ZERO, ONE , ZERO},
                                   {ZERO, ZERO, ZERO, ONE , ZERO},
                                   {ZERO, ZERO, ZERO, ONE , ZERO}}};

const Character CHARACTER_2 = {5, {{ZERO, ONE , ONE , ONE , ZERO},
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ZERO, ONE , ONE , ZERO},
                                   {ZERO, ONE , ZERO, ZERO, ZERO},
                                   {ONE , ZERO, ZERO, ZERO, ZERO},
                                   {ONE , ZERO, ZERO, ZERO, ZERO},
                                   {ONE , ONE , ONE , ONE , ONE }}};

const Character CHARACTER_3 = {5, {{ZERO, ONE , ONE , ONE , ZERO},
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ONE , ONE , ONE , ZERO},
                                   {ZERO, ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ZERO, ZERO, ZERO, ONE },
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ONE , ONE , ONE , ZERO}}};

const Character CHARACTER_4 = {5, {{ZERO, ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ZERO, ZERO, ONE , ONE },
                                   {ZERO, ZERO, ONE , ZERO, ONE },
                                   {ZERO, ONE , ZERO, ZERO, ONE },
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ONE , ONE , ONE , ONE , ONE },
                                   {ZERO, ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ZERO, ZERO, ZERO, ONE }}};

const Character CHARACTER_5 = {5, {{ONE , ONE , ONE , ONE , ONE },
                                   {ONE , ZERO, ZERO, ZERO, ZERO},
                                   {ONE , ZERO, ZERO, ZERO, ZERO},
                                   {ONE , ONE , ONE , ONE , ZERO},
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ZERO, ZERO, ZERO, ONE },
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ONE , ONE , ONE , ZERO}}};

const Character CHARACTER_6 = {5, {{ZERO, ONE , ONE , ONE , ZERO},
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ONE , ZERO, ZERO, ZERO, ZERO},
                                   {ONE , ZERO, ZERO, ZERO, ZERO},
                                   {ONE , ONE , ONE , ONE , ZERO},
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ONE , ONE , ONE , ZERO}}};

const Character CHARACTER_7 = {5, {{ONE , ONE , ONE , ONE , ONE },
                                   {ZERO, ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ZERO, ZERO, ONE , ZERO},
                                   {ZERO, ZERO, ZERO, ONE , ZERO},
                                   {ZERO, ZERO, ONE , ZERO, ZERO},
                                   {ZERO, ZERO, ONE , ZERO, ZERO},
                                   {ZERO, ZERO, ONE , ZERO, ZERO},
                                   {ZERO, ZERO, ONE , ZERO, ZERO}}};

const Character CHARACTER_8 = {5, {{ZERO, ONE , ONE , ONE , ZERO},
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ONE , ONE , ONE , ZERO},
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ONE , ONE , ONE , ZERO}}};

const Character CHARACTER_9 = {5, {{ZERO, ONE , ONE , ONE , ZERO},
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ONE , ONE , ONE , ONE },
                                   {ZERO, ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ZERO, ZERO, ZERO, ONE },
                                   {ONE , ZERO, ZERO, ZERO, ONE },
                                   {ZERO, ONE , ONE , ONE , ZERO}}};


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


const Character CHARACTER_HYPHEN = {3, {{ZERO, ZERO, ZERO, ZERO, ZERO},
                                        {ZERO, ZERO, ZERO, ZERO, ZERO},
                                        {ZERO, ZERO, ZERO, ZERO, ZERO},
                                        {ZERO, ZERO, ZERO, ZERO, ZERO},
                                        {ONE , ONE , ONE , ZERO, ZERO},
                                        {ZERO, ZERO, ZERO, ZERO, ZERO},
                                        {ZERO, ZERO, ZERO, ZERO, ZERO},
                                        {ZERO, ZERO, ZERO, ZERO, ZERO},
                                        {ZERO, ZERO, ZERO, ZERO, ZERO}}};

const Character CHARACTER_DOT = {3, {{ZERO, ZERO, ZERO, ZERO, ZERO},
                                     {ZERO, ZERO, ZERO, ZERO, ZERO},
                                     {ZERO, ZERO, ZERO, ZERO, ZERO},
                                     {ZERO, ZERO, ZERO, ZERO, ZERO},
                                     {ZERO, ZERO, ZERO, ZERO, ZERO},
                                     {ZERO, ZERO, ZERO, ZERO, ZERO},
                                     {ZERO, ZERO, ZERO, ZERO, ZERO},
                                     {ZERO, ZERO, ZERO, ZERO, ZERO},
                                     {ONE , ZERO, ZERO, ZERO, ZERO}}};

const Character CHARACTER_DOT_NARROW = {1, {{ZERO, ZERO, ZERO, ZERO, ZERO},
                                            {ZERO, ZERO, ZERO, ZERO, ZERO},
                                            {ZERO, ZERO, ZERO, ZERO, ZERO},
                                            {ZERO, ZERO, ZERO, ZERO, ZERO},
                                            {ZERO, ZERO, ZERO, ZERO, ZERO},
                                            {ZERO, ZERO, ZERO, ZERO, ZERO},
                                            {ZERO, ZERO, ZERO, ZERO, ZERO},
                                            {ZERO, ZERO, ZERO, ZERO, ZERO},
                                            {ONE , ZERO, ZERO, ZERO, ZERO}}};


const Character CHARACTER_K = {4, {{ONE , ZERO, ZERO, ZERO, ZERO},
                                   {ONE , ZERO, ZERO, ZERO, ZERO},
                                   {ONE , ZERO, ZERO, ZERO, ZERO},
                                   {ONE , ZERO, ZERO, ONE , ZERO},
                                   {ONE , ZERO, ONE , ZERO, ZERO},
                                   {ONE , ONE , ZERO, ZERO, ZERO},
                                   {ONE , ONE , ZERO, ZERO, ZERO},
                                   {ONE , ZERO, ONE , ZERO, ZERO},
                                   {ONE , ZERO, ZERO, ONE , ZERO}}};


const Character CHARACTER_HEART = {5, {{ZERO, ZERO, ZERO, ZERO, ZERO},
                                       {ZERO, ZERO, ZERO, ZERO, ZERO},
                                       {ZERO, ONE , ZERO, ONE , ZERO},
                                       {ONE , ZERO, ONE , ZERO, ONE },
                                       {ONE , ZERO, ZERO, ZERO, ONE },
                                       {ZERO, ONE , ZERO, ONE , ZERO},
                                       {ZERO, ZERO, ONE , ZERO, ZERO},
                                       {ZERO, ZERO, ZERO, ZERO, ZERO},
                                       {ZERO, ZERO, ZERO, ZERO, ZERO}}};

const Character CHARACTER_FOOT = {5, {{ZERO, ZERO, ZERO, ZERO, ZERO},
                                      {ZERO, ZERO, ZERO, ZERO, ZERO},
                                      {ZERO, ZERO, ZERO, ZERO, ZERO},
                                      {ONE , ZERO, ONE , ZERO, ZERO},
                                      {ONE , ONE , ONE , ONE , ZERO},
                                      {ONE , ZERO, ZERO, ZERO, ONE },
                                      {ONE , ONE , ONE , ONE , ONE },
                                      {ZERO, ZERO, ZERO, ZERO, ZERO},
                                      {ZERO, ZERO, ZERO, ZERO, ZERO}}};


void graphics_draw_character(GContext *ctx, GPoint pos, Character data, int16_t min, int16_t max) {
  if (min < 0) { min = 0; }
  if (max < 0) { max = 9; }
  graphics_context_set_fill_color(ctx, color_get_foreground());
  for (int i = 0; i < data.width; i++) {
    for (int j = 0; j < 9; j++) {
      if (data.a[j][i] == ONE && j >= min && j < max) {
        GPoint coords = GPoint(i, j);
        GRect rect = GRect(SIZE_SCALE_FACTOR * (pos.x + coords.x), SIZE_SCALE_FACTOR * (pos.y + coords.y),
                           SIZE_SCALE_FACTOR, SIZE_SCALE_FACTOR);
        graphics_fill_rect(ctx, rect, 0, GCornerNone);
      }
    }
  }
}

void graphics_draw_character_array(GContext *ctx, GPoint pos, Character *data, size_t length, int16_t min, int16_t max) {
  for (size_t i = 0; i < length; i++) {
    Character character = data[i];
    graphics_draw_character(ctx, pos, character, min, max);
    pos.x += character.width + 2;
  }
}

void graphics_draw_character_array_right(GContext *ctx, GPoint pos, Character *data, size_t length, int16_t min, int16_t max) {
  for (size_t i = length; i > 0; i--) {
    Character character = data[i-1];
    pos.x -= character.width;
    graphics_draw_character(ctx, pos, character, min, max);
    pos.x -= 2;
  }
}

int16_t graphics_get_character_array_width(Character *data, size_t length) {
  int16_t width = (length - 1) * 2;
  for (size_t i = 0; i < length; i++) {
    Character character = data[i];
    width += character.width;
  }
  return width;
}
