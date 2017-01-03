/*
 * Copyright (c) 2016 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "settings.h"


GColor settings_get_color_background() {
  return GColorBlack;
}

GColor settings_get_color_snake() {
  return GColorWhite;
}

GColor settings_get_color_text() {
  return PBL_IF_COLOR_ELSE(GColorLightGray, settings_get_color_snake());
}
