/*
 * Copyright (c) 2016 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <inttypes.h>
#include <stdbool.h>


typedef void (*HealthDataChanged)();


void health_init(HealthDataChanged callback);
int32_t health_get_steps();
int16_t health_get_heart_rate();
