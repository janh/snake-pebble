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

const Character CHARACTER_SPACE_NARROW = {2, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
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

const Character CHARACTER_F = {4, {CHARACTER_ROW(0, 0, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
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

const Character CHARACTER_J = {2, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0)}};

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

const Character CHARACTER_M = {5, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 1, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 1, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 1, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 1, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 1, 0, 1, 0, 0, 0),
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

const Character CHARACTER_Q = {4, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 1, 0, 0, 0, 0)}};

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

const Character CHARACTER_S = {4, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 1, 1, 0, 0, 0, 0, 0),
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

const Character CHARACTER_W = {5, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 1, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 1, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 1, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_X = {5, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
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

const Character CHARACTER_Z = {4, {CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                   CHARACTER_ROW(1, 1, 1, 1, 0, 0, 0, 0),
                                   CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};


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

const Character CHARACTER_CAPITAL_B = {5, {CHARACTER_ROW(1, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_CAPITAL_C = {5, {CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
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

const Character CHARACTER_CAPITAL_E = {5, {CHARACTER_ROW(1, 1, 1, 1, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 1, 1, 1, 1, 0, 0, 0),
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

const Character CHARACTER_CAPITAL_G = {5, {CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 1, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 1, 1, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_CAPITAL_H = {5, {CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 1, 1, 1, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_CAPITAL_I = {3, {CHARACTER_ROW(1, 1, 1, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 1, 1, 0, 0, 0, 0, 0),
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

const Character CHARACTER_CAPITAL_K = {5, {CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 1, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 1, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 1, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 1, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_CAPITAL_L = {5, {CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 1, 1, 1, 1, 0, 0, 0),
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

const Character CHARACTER_CAPITAL_P = {5, {CHARACTER_ROW(1, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_CAPITAL_Q = {5, {CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 1, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0)}};

const Character CHARACTER_CAPITAL_R = {5, {CHARACTER_ROW(1, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 1, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
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

const Character CHARACTER_CAPITAL_U = {5, {CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 1, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_CAPITAL_V = {5, {CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 0, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 0, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 0, 1, 0, 0, 0, 0),
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

const Character CHARACTER_CAPITAL_X = {5, {CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 0, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 0, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 0, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 0, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_CAPITAL_Y = {5, {CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 0, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 0, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};

const Character CHARACTER_CAPITAL_Z = {5, {CHARACTER_ROW(1, 1, 1, 1, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 1, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 1, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(0, 1, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 0, 0, 0, 0, 0, 0, 0),
                                           CHARACTER_ROW(1, 1, 1, 1, 1, 0, 0, 0),
                                           CHARACTER_ROW(0, 0, 0, 0, 0, 0, 0, 0)}};


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


static void graphics_draw_scaled_rect(GContext *ctx, GPoint pos, GPoint coords) {
  GRect rect = GRect(SIZE_SCALE_FACTOR * (pos.x + coords.x), SIZE_SCALE_FACTOR * (pos.y + coords.y),
                     SIZE_SCALE_FACTOR, SIZE_SCALE_FACTOR);
  graphics_fill_rect(ctx, rect, 0, GCornerNone);
}

void graphics_draw_character(GContext *ctx, GPoint pos, ExtendedCharacter data, int16_t min, int16_t max) {
  if (min < 0) { min = 0; }
  if (max < 0) { max = 11; }

  graphics_context_set_fill_color(ctx, settings_get_color_text());

  const Character *character = data.character;
  Diacritic diacritic = data.diacritic;
  int diacritics_line = (character->a[0] == 0) ? 2 : 0;

  for (int j = 0; j < 11; j++) {
    if (j >= min && j < max) {
      GPoint coords = GPoint(0, j);

      if (j == diacritics_line && diacritic != DIACRITIC_NONE) {
        if (diacritic == DIACRITIC_DIAERESIS_UMLAUT) {
          int inset = (character->width - 1) / 2 - 1;
          coords.x = 0 + inset;
          graphics_draw_scaled_rect(ctx, pos, coords);
          coords.x = character->width - 1 - inset;
          graphics_draw_scaled_rect(ctx, pos, coords);
        }
      } else if (j > 0) {
        CharacterRow row = character->a[j-1];
        for (uint8_t i = 0; i < character->width; i++) {
          if (CHARACTER_ROW_ITEM(row, i)) {
            coords.x = i;
            graphics_draw_scaled_rect(ctx, pos, coords);
          }
        }
      }

    }
  }
}

void graphics_draw_character_array(GContext *ctx, GPoint pos, ExtendedCharacter *data, size_t length, int16_t min, int16_t max) {
  for (size_t i = 0; i < length; i++) {
    ExtendedCharacter item = data[i];
    graphics_draw_character(ctx, pos, item, min, max);
    pos.x += item.character->width + 2;
  }
}

void graphics_draw_character_array_right(GContext *ctx, GPoint pos, ExtendedCharacter *data, size_t length, int16_t min, int16_t max) {
  for (size_t i = length; i > 0; i--) {
    ExtendedCharacter item = data[i-1];
    pos.x -= item.character->width;
    graphics_draw_character(ctx, pos, item, min, max);
    pos.x -= 2;
  }
}

int16_t graphics_get_character_array_width(ExtendedCharacter *data, size_t length) {
  int16_t width = (length - 1) * 2;
  for (size_t i = 0; i < length; i++) {
    const Character *character = data[i].character;
    width += character->width;
  }
  return width;
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
