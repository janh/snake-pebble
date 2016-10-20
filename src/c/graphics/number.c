/*
 * Copyright (c) 2016 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "number.h"
#include "snake.h"


NumberDesc NUMBER_0_DESC = {{{1,0}, {-1,-1}, {-1,-1}},
                            {{EL_DOWN , EL_LEFT , EL_HEAD , EL_LEFT },
                             {EL_DOWN , EL_NONE , EL_NONE , EL_UP   },
                             {EL_DOWN , EL_NONE , EL_NONE , EL_UP   },
                             {EL_DOWN , EL_NONE , EL_NONE , EL_UP   },
                             {EL_DOWN , EL_NONE , EL_NONE , EL_UP   },
                             {EL_DOWN , EL_NONE , EL_NONE , EL_UP   },
                             {EL_RIGHT, EL_RIGHT, EL_RIGHT, EL_UP   }}};

NumberDesc NUMBER_1_DESC = {{{2,6}, {-1,-1}, {-1,-1}},
                            {{EL_NONE , EL_HEAD , EL_LEFT , EL_NONE },
                             {EL_NONE , EL_NONE , EL_UP   , EL_NONE },
                             {EL_NONE , EL_NONE , EL_UP   , EL_NONE },
                             {EL_NONE , EL_NONE , EL_UP   , EL_NONE },
                             {EL_NONE , EL_NONE , EL_UP   , EL_NONE },
                             {EL_NONE , EL_NONE , EL_UP   , EL_NONE },
                             {EL_NONE , EL_NONE , EL_UP   , EL_NONE }}};

NumberDesc NUMBER_2_DESC = {{{0,0}, {-1,-1}, {-1,-1}},
                            {{EL_RIGHT, EL_RIGHT, EL_RIGHT, EL_DOWN },
                             {EL_NONE , EL_NONE , EL_NONE , EL_DOWN },
                             {EL_NONE , EL_NONE , EL_NONE , EL_DOWN },
                             {EL_DOWN , EL_LEFT , EL_LEFT , EL_LEFT },
                             {EL_DOWN , EL_NONE , EL_NONE , EL_NONE },
                             {EL_DOWN , EL_NONE , EL_NONE , EL_NONE },
                             {EL_RIGHT, EL_RIGHT, EL_RIGHT, EL_HEAD }}};

NumberDesc NUMBER_3_DESC = {{{0,0}, {2,3}, {-1,-1}},
                            {{EL_RIGHT, EL_RIGHT, EL_RIGHT, EL_DOWN },
                             {EL_NONE , EL_NONE , EL_NONE , EL_DOWN },
                             {EL_NONE , EL_NONE , EL_NONE , EL_DOWN },
                             {EL_NONE , EL_HEAD , EL_LEFT , EL_DOWN },
                             {EL_NONE , EL_NONE , EL_NONE , EL_DOWN },
                             {EL_NONE , EL_NONE , EL_NONE , EL_DOWN },
                             {EL_HEAD , EL_LEFT , EL_LEFT , EL_LEFT }}};

NumberDesc NUMBER_4_DESC = {{{3,6}, {2,3}, {-1,-1}},
                            {{EL_HEAD , EL_NONE , EL_NONE , EL_HEAD },
                             {EL_UP   , EL_NONE , EL_NONE , EL_UP   },
                             {EL_UP   , EL_NONE , EL_NONE , EL_UP   },
                             {EL_UP   , EL_LEFT , EL_LEFT , EL_UP   },
                             {EL_NONE , EL_NONE , EL_NONE , EL_UP   },
                             {EL_NONE , EL_NONE , EL_NONE , EL_UP   },
                             {EL_NONE , EL_NONE , EL_NONE , EL_UP   }}};

NumberDesc NUMBER_5_DESC = {{{0,6}, {-1,-1}, {-1,-1}},
                            {{EL_RIGHT, EL_RIGHT, EL_RIGHT, EL_HEAD },
                             {EL_UP   , EL_NONE , EL_NONE , EL_NONE },
                             {EL_UP   , EL_NONE , EL_NONE , EL_NONE },
                             {EL_UP   , EL_LEFT , EL_LEFT , EL_LEFT },
                             {EL_NONE , EL_NONE , EL_NONE , EL_UP   },
                             {EL_NONE , EL_NONE , EL_NONE , EL_UP   },
                             {EL_RIGHT, EL_RIGHT, EL_RIGHT, EL_UP   }}};

NumberDesc NUMBER_6_DESC = {{{1,3}, {-1,-1}, {-1,-1}},
                            {{EL_RIGHT, EL_RIGHT, EL_RIGHT, EL_HEAD },
                             {EL_UP   , EL_NONE , EL_NONE , EL_NONE },
                             {EL_UP   , EL_NONE , EL_NONE , EL_NONE },
                             {EL_UP   , EL_RIGHT, EL_RIGHT, EL_DOWN },
                             {EL_UP   , EL_NONE , EL_NONE , EL_DOWN },
                             {EL_UP   , EL_NONE , EL_NONE , EL_DOWN },
                             {EL_UP   , EL_LEFT , EL_LEFT , EL_LEFT }}};

NumberDesc NUMBER_7_DESC = {{{3,6}, {-1,-1}, {-1,-1}},
                            {{EL_DOWN , EL_LEFT , EL_LEFT , EL_LEFT },
                             {EL_HEAD , EL_NONE , EL_NONE , EL_UP   },
                             {EL_NONE , EL_NONE , EL_NONE , EL_UP   },
                             {EL_NONE , EL_NONE , EL_NONE , EL_UP   },
                             {EL_NONE , EL_NONE , EL_NONE , EL_UP   },
                             {EL_NONE , EL_NONE , EL_NONE , EL_UP   },
                             {EL_NONE , EL_NONE , EL_NONE , EL_UP   }}};

NumberDesc NUMBER_8_DESC = {{{0,2}, {3,4}, {1,3}},
                            {{EL_RIGHT, EL_RIGHT, EL_RIGHT, EL_DOWN },
                             {EL_UP   , EL_NONE , EL_NONE , EL_DOWN },
                             {EL_UP   , EL_NONE , EL_NONE , EL_DOWN },
                             {EL_HEAD , EL_RIGHT, EL_HEAD , EL_HEAD },
                             {EL_UP   , EL_NONE , EL_NONE , EL_DOWN },
                             {EL_UP   , EL_NONE , EL_NONE , EL_DOWN },
                             {EL_UP   , EL_LEFT , EL_LEFT , EL_LEFT }}};


NumberDesc NUMBER_9_DESC = {{{2,3}, {-1,-1}, {-1,-1}},
                            {{EL_RIGHT, EL_RIGHT, EL_RIGHT, EL_DOWN },
                             {EL_UP   , EL_NONE , EL_NONE , EL_DOWN },
                             {EL_UP   , EL_NONE , EL_NONE , EL_DOWN },
                             {EL_UP   , EL_LEFT , EL_LEFT , EL_DOWN },
                             {EL_NONE , EL_NONE , EL_NONE , EL_DOWN },
                             {EL_NONE , EL_NONE , EL_NONE , EL_DOWN },
                             {EL_HEAD , EL_LEFT , EL_LEFT , EL_LEFT }}};


static NumberPointer next_pointer(NumberPointer pointer, NumberElement element) {
  switch (element) {
  case EL_UP:
    pointer.y--;
    break;
  case EL_RIGHT:
    pointer.x++;
    break;
  case EL_DOWN:
    pointer.y++;
    break;
  case EL_LEFT:
    pointer.x--;
    break;
  default:
    break;
  }
  return pointer;
}

void graphics_draw_number(GContext *ctx, GPoint pos, NumberDesc number) {
  for (int i = 0; i < 3; i++) {
    NumberPointer pointer = number.start[i];
    if (pointer.x < 0 || pointer.y < 0) {
      continue;
    }

    bool end = false;
    NumberElement last, current = EL_NONE;
    while (!end) {
      last = current;
      current = number.el[pointer.y][pointer.x];

      SnakeElement element;
      bool mirror;
      SnakeRotation rotation;

      if (current == last || current == EL_HEAD || last == EL_NONE) {
        if (last == EL_NONE) {
          element = SNAKE_TAIL;
          last = current;
        } else if (current == EL_HEAD) {
          element = SNAKE_HEAD;
        } else {
          element = SNAKE_LINE;
        }
        mirror = (last == EL_LEFT || last == EL_DOWN) ? true : false;
        rotation = (last == EL_UP || last == EL_DOWN) ? ROTATION_90 : ROTATION_0;
      }

      if (current != last && current != EL_HEAD && current != EL_NONE) {
        element = SNAKE_EDGE;
        mirror = false;
        if ((current == EL_RIGHT && last == EL_UP) || (current == EL_DOWN && last == EL_LEFT)) {
          rotation = ROTATION_0;
        } else if ((current == EL_UP && last == EL_LEFT) || (current == EL_RIGHT && last == EL_DOWN)) {
          rotation = ROTATION_90;
        } else if ((current == EL_LEFT && last == EL_DOWN) || (current == EL_UP && last == EL_RIGHT)) {
          rotation = ROTATION_180;
        } else if ((current == EL_DOWN && last == EL_RIGHT) || (current == EL_LEFT && last == EL_UP)) {
          rotation = ROTATION_270;
        }
      }

      graphics_draw_snake_element(ctx, GPoint(pos.x + 4 * pointer.x, pos.y + 4 * pointer.y), element, mirror, rotation);

      if (current == EL_HEAD || current == EL_NONE) {
        end = true;
      } else {
        pointer = next_pointer(pointer, current);
      }
    }
  }
}
