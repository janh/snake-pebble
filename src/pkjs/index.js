/*
 * Copyright (c) 2017 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
 
var config = require('./config');


Pebble.addEventListener('showConfiguration', function(e) {
  Pebble.openURL(config.generateUrl());
});


Pebble.addEventListener('webviewclosed', function(e) {
  if (!e || !e.response) {
    return;
  }

  var data = decodeURIComponent(e.response);
  config.update(data);
});
