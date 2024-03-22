#include "EmonLib.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <Wire.h>

// Constants for calibration
const float vCalibration = 1.3;
const float currCalibration = 2.6;
 
//credentials
const char ssid[] = "Your SSID";
const char pass[] = "Your password";

// EnergyMonitor instance
EnergyMonitor emon;
 
// Variables for energy calculation
float kWh = 0.0;
unsigned long lastMillis = millis();
 
float current;

void setup() {
  Serial.begin(115200);
 
  // Setup voltage and current inputs
  emon.voltage(35, vCalibration, 1.7); // Voltage: input pin, calibration, phase_shift
  emon.current(34, currCalibration);    // Current: input pin, calibration
 
  // A small delay for system to stabilize
  delay(1000);

}

void loop() {
  sendEnergyData();
  delay(500);
}

void sendEnergyData()
{
  emon.calcVI(20, 2000); // Calculate all. No.of half wavelengths (crossings), time-out
 
  // Calculate energy consumed in kWh
  unsigned long currentMillis = millis();
  kWh += emon.apparentPower * (currentMillis - lastMillis) / 3600000000.0;
  lastMillis = currentMillis;
 
  // Print data to Serial for debugging
  Serial.printf("Vrms: %.2fV\tIrms: %.4fAn", emon.Vrms, emon.Irms);
}
