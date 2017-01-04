/*
 * Copyright (c) 2016-2017 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <pebble.h>


typedef enum {
  DATE_FORMAT_YYYY_MM_DD_HYPHEN = 0,
  DATE_FORMAT_DD_MM_YYYY_DOT = 1,
  DATE_FORMAT_DD_MM_YYYY_SLASH = 2,
  DATE_FORMAT_MM_DD_YYYY_SLASH = 3,
} DateFormat;


typedef void (*SettingsChanged)();

GColor settings_get_color_background();
GColor settings_get_color_snake();
GColor settings_get_color_text();
DateFormat settings_get_date_format();

void settings_set_callback(SettingsChanged callback);
void settings_init();
