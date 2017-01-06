/*
 * Copyright (c) 2017 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include<stdlib.h>


extern const char *STRING_MONTHS[12][2];
extern const char *STRING_WEEKDAYS[7][2];


const char* strings_get_localized_array_item(const char * (*string)[2], size_t index);
