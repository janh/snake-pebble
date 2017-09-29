/*
 * Copyright (c) 2017 Jan Hoffmann
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

var html = require('html');
var keys = require('message_keys');


var watchInfo = Pebble.getActiveWatchInfo();


var options = [
  {
    "title": "Appearance",
    "items": [
      {
        "key": keys.GraphicsHighResolution,
        "type": "checkbox",
        "default": true,
        "title": "High resolution graphics",
        "visible": (watchInfo.platform != "emery")
      },
      {
        "key": keys.ColorBackground,
        "type": "color",
        "default": 0x000000,
        "title": "Background color",
        "color": (watchInfo.platform != "aplite" && watchInfo.platform != "diorite")
      },
      {
        "key": keys.ColorSnake,
        "type": "color",
        "default": 0xffffff,
        "title": "Time color",
        "color": (watchInfo.platform != "aplite" && watchInfo.platform != "diorite")
      },
      {
        "key": keys.ColorText,
        "type": "color",
        "default": 0xaaaaaa,
        "title": "Text color",
        "color": true,
        "visible": (watchInfo.platform != "aplite" && watchInfo.platform != "diorite")
      }
    ]
  },
  {
    "title": "Content",
    "items": [
      {
        "key": keys.DateFormat,
        "type": "select",
        "default": 0,
        "title": "Date format",
        "options": [
          {
            "value": 0,
            "text": "YYYY-MM-DD"
          },
          {
            "value": 1,
            "text": "DD.MM.YYYY"
          },
          {
            "value": 2,
            "text": "DD/MM/YYYY"
          },
          {
            "value": 3,
            "text": "MM/DD/YYYY"
          },
          {
            "value": 4,
            "text": "Day DD Mon"
          },
          {
            "value": 5,
            "text": "Day, DD. Mon"
          },
          {
            "value": 6,
            "text": "Day Mon DD"
          }
        ]
      }
    ]
  }
];


function generateUrl() {
  var content = html.config;

  var data = localStorage.getItem('data');
  if (data != null) {
    data = JSON.parse(data);
  } else {
    data = {};
  }

  content = content.replace('{{DATA}}', JSON.stringify(data));
  content = content.replace('{{OPTIONS}}', JSON.stringify(options));

  var url = 'data:text/html;charset=utf-8,' + encodeURIComponent(content);

  return url;
}


function update(data) {
  var dict = JSON.parse(data);
  localStorage.setItem('data', data);

  Pebble.sendAppMessage(dict, function(e) {
    console.log('Sent configuration');
  }, function(e) {
    console.log('Failed to send configuration');
    console.log(JSON.stringify(e));
  });
}


module.exports.generateUrl = generateUrl;
module.exports.update = update;
