/*
 * Copyright (c) 2017 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

var keys = require('message_keys');

var Clay = require('pebble-clay');
var clayConfig = require('./config.json');
var clay = new Clay(clayConfig, null, { autoHandleEvents: false });

Pebble.addEventListener('showConfiguration', function(e) {
  Pebble.openURL(clay.generateUrl());
});

Pebble.addEventListener('webviewclosed', function(e) {
  if (e && !e.response) {
    return;
  }

  var dict = clay.getSettings(e.response);

  dict[keys.DateFormat] = parseInt(dict[keys.DateFormat])

  Pebble.sendAppMessage(dict, function(e) {
    console.log('Sent configuration');
  }, function(e) {
    console.log('Failed to send configuration');
    console.log(JSON.stringify(e));
  });
});
