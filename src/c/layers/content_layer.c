/*
 * Copyright (c) 2016-2017 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdbool.h>

#include "content_layer.h"
#include "../lib/sizes.h"


typedef struct {
  ContentLayerItem item_left;
  ContentLayerItem item_right;
  int16_t anim_state;
} ContentLayerData;


void content_layer_set_data(ContentLayer* content_layer, ContentLayerItem left, ContentLayerItem right) {
  ContentLayerData *data = (ContentLayerData *)layer_get_data(content_layer);
  data->item_left = left;
  data->item_right = right;
  layer_mark_dirty(content_layer);
}

static void content_layer_get_characters(ExtendedCharacter *buffer, size_t *length, ContentLayerItem item, bool left) {
  *length = 0;
  if (left) {
    buffer[(*length)++] = (ExtendedCharacter) {item.icon, DIACRITIC_NONE};
  }
  if (item.value < 0) {
    buffer[(*length)++] = (ExtendedCharacter) {&CHARACTER_HYPHEN, DIACRITIC_NONE};
  } else {
    if (item.value >= 10000) {
      *length += graphics_get_character_array_from_integer(&buffer[*length], 3, false, item.value / 1000);
      if (item.value < 100000) {
        buffer[(*length)++] = (ExtendedCharacter) {&CHARACTER_DOT_NARROW, DIACRITIC_NONE};
        buffer[(*length)++] = (ExtendedCharacter) {CHARACTER_NUMBERS[(item.value / 100) % 10], DIACRITIC_NONE};
      }
      buffer[(*length)++] = (ExtendedCharacter) {&CHARACTER_K, DIACRITIC_NONE};
    } else {
      *length += graphics_get_character_array_from_integer(&buffer[*length], 4, false, item.value);
    }
  }
  if (!left) {
    buffer[(*length)++] = (ExtendedCharacter) {item.icon, DIACRITIC_NONE};
  }
}

static void content_layer_update_proc(Layer *layer, GContext *ctx) {
  ContentLayer *content_layer = (ContentLayer *)layer;
  ContentLayerData *data = (ContentLayerData *)layer_get_data(content_layer);

  GRect rect = layer_get_bounds(layer);
  int16_t right = rect.size.w / SIZE_SCALE_FACTOR;

  size_t length;
  ExtendedCharacter characters[6];

  content_layer_get_characters(characters, &length, data->item_left, true);
  graphics_draw_character_array(ctx, GPoint(0, 0), characters, length, 0, data->anim_state);

  content_layer_get_characters(characters, &length, data->item_right, false);
  graphics_draw_character_array_right(ctx, GPoint(right, 0), characters, length, 0, data->anim_state);
}

ContentLayer* content_layer_create(GRect frame) {
  ContentLayer *content_layer = layer_create_with_data(frame, sizeof(ContentLayerData));

  ContentLayerData *data = (ContentLayerData *)layer_get_data(content_layer);
  data->item_left.icon = &CHARACTER_SPACE_WIDE;
  data->item_right.icon = &CHARACTER_SPACE_WIDE;

  layer_set_update_proc(content_layer, content_layer_update_proc);
  layer_mark_dirty(content_layer);

  return content_layer;
}

void content_layer_destroy(ContentLayer* content_layer) {
  if (content_layer) {
    layer_destroy(content_layer);
  }
}

void content_layer_set_anim_state(ContentLayer* content_layer, int16_t anim_state) {
  ContentLayerData *data = (ContentLayerData *)layer_get_data(content_layer);
  data->anim_state = anim_state;
  layer_mark_dirty(content_layer);
}
