/*
 * Copyright (c) 2016-2017 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "data.h"
#include "demo.h"

#include <pebble.h>


static DataTypeMask s_types;
static DataChanged s_callback;


static void health_handler(HealthEventType event, void *context) {
  DataTypeMask types = 0;

  if (event == HealthEventSignificantUpdate || event == HealthEventMovementUpdate) {
    types |= DATA_TYPE_STEPS;
  }
  if (event == HealthEventSignificantUpdate || event == HealthEventHeartRateUpdate) {
    types |= DATA_TYPE_HEART_RATE;
  }

  types &= s_types;
  if (types > 0) {
    s_callback(types);
  }
}


static void battery_handler(BatteryChargeState charge) {
  s_callback(DATA_TYPE_BATTERY);
}


void data_events_init(DataTypeMask types, DataChanged callback) {
  health_service_events_unsubscribe();
  battery_state_service_unsubscribe();

  s_types = types;
  s_callback = callback;

  if (s_callback != NULL) {
    if (types & DATA_TYPE_STEPS || types & DATA_TYPE_HEART_RATE) {
      health_service_events_subscribe(&health_handler, NULL);
    }
    if (types & DATA_TYPE_BATTERY) {
      battery_state_service_subscribe(&battery_handler);
    }
  }
}


static bool health_metric_available(HealthMetric metric, time_t time_start, time_t time_end) {
  HealthServiceAccessibilityMask mask = health_service_metric_accessible(metric, time_start, time_end);
  return !(mask & HealthServiceAccessibilityMaskNoPermission || mask & HealthServiceAccessibilityMaskNotSupported);
}

int32_t data_get_steps() {
  # if DEMO_MODE
    return 10300;
  # else
    if (health_metric_available(HealthMetricStepCount, time_start_of_today(), time(NULL))) {
      HealthValue value = health_service_sum_today(HealthMetricStepCount);
      return (value > 0) ? value : 0;
    } else {
      return -1;
    }
  # endif
}

int32_t data_get_heart_rate() {
  # if DEMO_MODE
    return 64;
  # else
    if (health_metric_available(HealthMetricHeartRateBPM, time(NULL), time(NULL))) {
      HealthValue value = health_service_peek_current_value(HealthMetricHeartRateBPM);
      return (value > 0) ? value : 0;
    } else {
      return -1;
    }
  # endif
}

bool data_device_has_heart_rate_sensor() {
  WatchInfoModel watch = watch_info_get_model();
  if (watch == WATCH_INFO_MODEL_PEBBLE_2_HR || watch == WATCH_INFO_MODEL_PEBBLE_TIME_2) {
    return true;
  } else if (watch == WATCH_INFO_MODEL_UNKNOWN) {
    #if defined(PBL_PLATFORM_DIORITE) || defined(PBL_PLATFORM_EMERY)
      return true;
    #endif
  }
  return false;
}


uint8_t data_get_battery_percent() {
  # if DEMO_MODE
    return 80;
  # else
    BatteryChargeState state = battery_state_service_peek();
    return state.charge_percent;
  # endif
}

bool data_get_battery_charging() {
  # if DEMO_MODE
    return false;
  # else
    BatteryChargeState state = battery_state_service_peek();
    return state.is_charging;
  # endif
}
