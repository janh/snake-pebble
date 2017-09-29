/*
 * Copyright (c) 2016 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once


#include "date_layer.h"
#include "content_layer.h"


typedef void (*DateContentLayersAnimationComplete)(void);

void date_content_layers_animate(DateLayer* date_layer, ContentLayer* content_layer, DateContentLayersAnimationComplete callback);
