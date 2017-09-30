/*
 * Copyright (c) 2016-2017 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <inttypes.h>
#include <stdbool.h>


typedef enum {
  DATA_TYPE_STEPS = 1 << 0,
  DATA_TYPE_HEART_RATE = 1 << 1,
} DataTypeMask;


typedef void (*DataChanged)(DataTypeMask types);


void data_events_init(DataTypeMask types, DataChanged callback);

int32_t data_get_steps();
int32_t data_get_heart_rate();
bool data_device_has_heart_rate_sensor();
