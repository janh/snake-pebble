/*
 * Copyright (c) 2016 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "health.h"

#include <pebble.h>


static void health_handler(HealthEventType event, void *context) {
  if (event == HealthEventSignificantUpdate || event == HealthEventMovementUpdate || event == HealthEventHeartRateUpdate) {
    HealthDataChanged callback = (HealthDataChanged)context;
    callback();
  }
}

void health_init(HealthDataChanged callback) {
  health_service_events_subscribe(&health_handler, callback);
}

static bool health_metric_available(HealthMetric metric, time_t time_start, time_t time_end) {
  HealthServiceAccessibilityMask mask = health_service_metric_accessible(metric, time_start, time_end);
  return !(mask & HealthServiceAccessibilityMaskNoPermission || mask & HealthServiceAccessibilityMaskNotSupported);
}

int32_t health_get_steps() {
  if (health_metric_available(HealthMetricStepCount, time_start_of_today(), time(NULL))) {
    HealthValue value = health_service_sum_today(HealthMetricStepCount);
    return (value > 0) ? value : 0;
  } else {
    return -1;
  }
}

int16_t health_get_heart_rate() {
  if (health_metric_available(HealthMetricHeartRateBPM, time(NULL), time(NULL))) {
    HealthValue value = health_service_peek_current_value(HealthMetricHeartRateBPM);
    return (value > 0) ? value : 0;
  } else {
    return -1;
  }
}
