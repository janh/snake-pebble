/*
 * Copyright (c) 2016 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once


#ifdef PBL_PLATFORM_EMERY
  #define SIZE_SCALE_FACTOR 3
#else
  #define SIZE_SCALE_FACTOR 2
#endif

#ifdef PBL_PLATFORM_EMERY
  #define SIZE_TIME_WIDTH 67
#else
  #define SIZE_TIME_WIDTH 68
#endif
#define SIZE_TIME_HEIGHT 28

#define SIZE_TIME_DIGIT_POSITION_1 GPoint(0, 0)
#define SIZE_TIME_DIGIT_POSITION_2 GPoint(16, 0)
#define SIZE_TIME_COLON_POSITION_1 GPoint(32, 4 * 2)
#define SIZE_TIME_COLON_POSITION_2 GPoint(32, 4 * 4)
#define SIZE_TIME_DIGIT_POSITION_3 GPoint(SIZE_TIME_WIDTH - 32, 0)
#define SIZE_TIME_DIGIT_POSITION_4 GPoint(SIZE_TIME_WIDTH - 16, 0)
