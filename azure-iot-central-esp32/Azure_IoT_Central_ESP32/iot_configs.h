// Copyright (c) Microsoft Corporation. All rights reserved.
// SPDX-License-Identifier: MIT

// Wifi
#define IOT_CONFIG_WIFI_SSID              "MotoKal"
#define IOT_CONFIG_WIFI_PASSWORD          "kall8900"

// DHT. 
// Change the DHT_PIN to the pin you are using.
#define DHT_PIN 14

// Azure IoT Central
#define DPS_ID_SCOPE                      "0ne00C1CAC5"
#define IOT_CONFIG_DEVICE_ID              "1p7ms6ec177"
#define IOT_CONFIG_DEVICE_KEY             "Y81Ncoi3r4VwepJtUXxg+8o7uvZYDrIElAbTDkZ8FTY="

// User-agent (url-encoded) provided by the MQTT client to Azure IoT Services.
// When developing for your own Arduino-based platform,
// please update the suffix with the format '(ard;<platform>)' as an url-encoded string.
#define AZURE_SDK_CLIENT_USER_AGENT       "c%2F" AZ_SDK_VERSION_STRING "(ard%3Besp32)"

// Publish 1 message every 2 seconds.
#define TELEMETRY_FREQUENCY_IN_SECONDS    2

// For how long the MQTT password (SAS token) is valid, in minutes.
// After that, the sample automatically generates a new password and re-connects.
#define MQTT_PASSWORD_LIFETIME_IN_MINUTES 60
