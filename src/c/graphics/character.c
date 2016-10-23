/*
 * Copyright (c) 2016 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "character.h"
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


void graphics_draw_character(GContext *ctx, GPoint pos, Character data) {
  for (int i = 0; i < data.width; i++) {
    for (int j = 0; j < 9; j++) {
      if (data.a[j][i] == ONE) {
        GPoint coords = GPoint(i, j);
        GRect rect = GRect(SIZE_SCALE_FACTOR * (pos.x + coords.x), SIZE_SCALE_FACTOR * (pos.y + coords.y),
                           SIZE_SCALE_FACTOR, SIZE_SCALE_FACTOR);
        graphics_fill_rect(ctx, rect, 0, GCornerNone);
      }
    }
  }
}

void graphics_draw_character_array(GContext *ctx, GPoint pos, Character *data, size_t length) {
  for (size_t i = 0; i < length; i++) {
    Character character = data[i];
    graphics_draw_character(ctx, pos, character);
    pos.x += character.width + 2;
  }
}
