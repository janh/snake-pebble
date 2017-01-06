/*
 * Copyright (c) 2017 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "strings.h"

#include <pebble.h>


const char *STRING_MONTHS[12][2] = {{"Jan", "Jan"},
                                    {"Feb", "Feb"},
                                    {"Mar", "Ma\x01r"},
                                    {"Apr", "Apr"},
                                    {"May", "Mai"},
                                    {"Jun", "Jun"},
                                    {"Jul", "Jul"},
                                    {"Aug", "Aug"},
                                    {"Sep", "Sep"},
                                    {"Oct", "Okt"},
                                    {"Nov", "Nov"},
                                    {"Dec", "Dez"}};

const char *STRING_WEEKDAYS[7][2] = {{"Sun", "So"},
                                     {"Mon", "Mo"},
                                     {"Tue", "Di"},
                                     {"Wed", "Mi"},
                                     {"Thu", "Do"},
                                     {"Fri", "Fr"},
                                     {"Sat", "Sa"}};


size_t get_locale_index() {
  const char *locale = i18n_get_system_locale();
  if (strcmp("de_DE", locale) == 0) {
    return 1;
  } else {
    return 0;
  }
}

const char* strings_get_localized_array_item(const char * (*string)[2], size_t index) {
  return string[index][get_locale_index()];
}
