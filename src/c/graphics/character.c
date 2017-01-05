/*
 * Copyright (c) 2016-2017 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "character.h"
#include "../lib/settings.h"
#include "../lib/sizes.h"


#define CHARACTER_ROW(a,b,c,d,e,f,g,h) 1*a + 2*b + 4*c + 8*d + 16*e + 32*f + 64*g + 128*h
#define CHARACTER_ROW_ITEM(row,i) row & (1 << i)


const Character CHARACTER_0 = {5, {CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_1 = {5, {CHARACTER_ROW(0, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_2 = {5, {CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 1, 1, 1, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_3 = {5, {CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_4 = {5, {CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 1, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 1, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 1, 1, 1, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_5 = {5, {CHARACTER_ROW(1, 1, 1, 1, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_6 = {5, {CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_7 = {5, {CHARACTER_ROW(1, 1, 1, 1, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_8 = {5, {CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_9 = {5, {CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 1, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};


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


const Character CHARACTER_HYPHEN = {3, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                        CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                        CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                        CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                        CHARACTER_ROW(1, 1, 1, 0, 0, 0, 0, 0),
                                        CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                        CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                        CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                        CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                        CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_DOT = {3, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                     CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                     CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                     CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                     CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                     CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                     CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                     CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                     CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                     CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_DOT_NARROW = {1, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                            CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                            CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                            CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                            CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                            CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                            CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                            CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                            CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                            CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_SLASH = {3, {CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_SPACE = {3, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};


const Character CHARACTER_A = {4, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_B = {4, {CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 1, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 1, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_C = {4, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_D = {4, {CHARACTER_ROW(0, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_E = {4, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_G = {4, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 0, 0, 0, 0, 0)}};

const Character CHARACTER_H = {4, {CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 1, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_I = {1, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_K = {4, {CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_L = {2, {CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_N = {4, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 1, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_O = {4, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_P = {4, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 1, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 1, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_R = {4, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_T = {4, {CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_U = {4, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_V = {5, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_Y = {4, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 1, 1, 0, 0, 0, 0, 0)}};


const Character *CHARACTER_LETTERS[26] = {&CHARACTER_A,
                                          &CHARACTER_B,
                                          &CHARACTER_C,
                                          &CHARACTER_D,
                                          &CHARACTER_E,
                                          NULL,
                                          &CHARACTER_G,
                                          &CHARACTER_H,
                                          &CHARACTER_I,
                                          NULL,
                                          &CHARACTER_K,
                                          &CHARACTER_L,
                                          NULL,
                                          &CHARACTER_N,
                                          &CHARACTER_O,
                                          &CHARACTER_P,
                                          NULL,
                                          &CHARACTER_R,
                                          NULL,
                                          &CHARACTER_T,
                                          &CHARACTER_U,
                                          &CHARACTER_V,
                                          NULL,
                                          NULL,
                                          &CHARACTER_Y,
                                          NULL};


const Character CHARACTER_CAPITAL_A = {5, {CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 1, 1, 1, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_CAPITAL_D = {5, {CHARACTER_ROW(1, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_CAPITAL_F = {5, {CHARACTER_ROW(1, 1, 1, 1, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_CAPITAL_J = {5, {CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_CAPITAL_M = {7, {CHARACTER_ROW(1, 0, 0, 0, 0, 0, 1, 0),
                                           CHARACTER_ROW(1, 1, 0, 0, 0, 1, 1, 0),
                                           CHARACTER_ROW(1, 0, 1, 0, 1, 0, 1, 0),
                                           CHARACTER_ROW(1, 0, 1, 0, 1, 0, 1, 0),
                                           CHARACTER_ROW(1, 0, 0, 1, 0, 0, 1, 0),
                                           CHARACTER_ROW(1, 0, 0, 1, 0, 0, 1, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 1, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 1, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 1, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_CAPITAL_N = {6, {CHARACTER_ROW(1, 0, 0, 0, 0, 1, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 1, 0, 0),
                                           CHARACTER_ROW(1, 1, 0, 0, 0, 1, 0, 0),
                                           CHARACTER_ROW(1, 0, 1, 0, 0, 1, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 1, 0, 1, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 1, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 1, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 1, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 1, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_CAPITAL_O = {5, {CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_CAPITAL_S = {5, {CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_CAPITAL_T = {5, {CHARACTER_ROW(1, 1, 1, 1, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_CAPITAL_W = {7, {CHARACTER_ROW(1, 0, 0, 0, 0, 0, 1, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 1, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 1, 0),
                                           CHARACTER_ROW(1, 0, 0, 1, 0, 0, 1, 0),
                                           CHARACTER_ROW(1, 0, 0, 1, 0, 0, 1, 0),
                                           CHARACTER_ROW(1, 0, 1, 0, 1, 0, 1, 0),
                                           CHARACTER_ROW(1, 0, 1, 0, 1, 0, 1, 0),
                                           CHARACTER_ROW(0, 1, 0, 0, 0, 1, 0, 0),
                                           CHARACTER_ROW(0, 1, 0, 0, 0, 1, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};


const Character *CHARACTER_CAPITAL_LETTERS[26] = {&CHARACTER_CAPITAL_A,
                                                  NULL,
                                                  NULL,
                                                  &CHARACTER_CAPITAL_D,
                                                  NULL,
                                                  &CHARACTER_CAPITAL_F,
                                                  NULL,
                                                  NULL,
                                                  NULL,
                                                  &CHARACTER_CAPITAL_J,
                                                  NULL,
                                                  NULL,
                                                  &CHARACTER_CAPITAL_M,
                                                  &CHARACTER_CAPITAL_N,
                                                  &CHARACTER_CAPITAL_O,
                                                  NULL,
                                                  NULL,
                                                  NULL,
                                                  &CHARACTER_CAPITAL_S,
                                                  &CHARACTER_CAPITAL_T,
                                                  NULL,
                                                  NULL,
                                                  &CHARACTER_CAPITAL_W,
                                                  NULL,
                                                  NULL,
                                                  NULL};


const Character CHARACTER_HEART = {5, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(0, 1, 0, 1, 0, 0, 0, 0),
                                       CHARACTER_ROW(1, 0, 1, 0, 1, 0, 0, 0),
                                       CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                       CHARACTER_ROW(0, 1, 0, 1, 0, 0, 0, 0),
                                       CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                       CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_FOOT = {5, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                      CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                      CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                      CHARACTER_ROW(1, 0, 1, 0, 0, 0, 0, 0),
                                      CHARACTER_ROW(1, 1, 1, 1, 0, 0, 0, 0),
                                      CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                      CHARACTER_ROW(1, 1, 1, 1, 1, 0, 0, 0),
                                      CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                      CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                      CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};


void graphics_draw_character(GContext *ctx, GPoint pos, Character data, int16_t min, int16_t max) {
  if (min < 0) { min = 0; } else { min--; }
  if (max < 0) { max = 10; } else { max--; }
  graphics_context_set_fill_color(ctx, settings_get_color_text());
  for (int j = 0; j < 10; j++) {
    if (j >= min && j < max) {
      CharacterRow row = data.a[j];
      for (uint8_t i = 0; i < data.width; i++) {
        if (CHARACTER_ROW_ITEM(row, i)) {
          GPoint coords = GPoint(i, j);
          GRect rect = GRect(SIZE_SCALE_FACTOR * (pos.x + coords.x), SIZE_SCALE_FACTOR * (1 + pos.y + coords.y),
                             SIZE_SCALE_FACTOR, SIZE_SCALE_FACTOR);
          graphics_fill_rect(ctx, rect, 0, GCornerNone);
        }
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

size_t graphics_get_character_array_from_text(Character *buffer, size_t length, const char *text) {
  for (size_t i = 0; i < length; i++) {
    char c = text[i];
    if (c == '\0') {
      return i;
      break;
    }

    const Character *character = NULL;

    if (c >= 'A' && c <= 'Z') {
      character = CHARACTER_CAPITAL_LETTERS[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
      character = CHARACTER_LETTERS[c - 'a'];
    } else if (c >= '0' && c <= '9') {
      character = CHARACTER_NUMBERS[c - '0'];
    }

    if (character != NULL) {
      buffer[i] = *character;
    } else {
      buffer[i] = CHARACTER_DOT_NARROW;
    }
  }

  return length;
}

size_t graphics_get_character_array_from_integer(Character *buffer, size_t length, bool padding, uint32_t integer) {
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
    buffer[i-1] = *CHARACTER_NUMBERS[integer % 10];
    integer /= 10;
  }

  return length;
}
