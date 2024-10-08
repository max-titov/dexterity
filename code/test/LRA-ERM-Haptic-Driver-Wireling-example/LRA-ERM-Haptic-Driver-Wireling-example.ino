/*************************************************************************
 * DRV2605 LRA ERM Haptic Driver Wireling
 * This program is an expanded example that is part of the Adafruit_DRV2605 
 * library. The DRV_2605 will send 116 different waveform effects to a 
 * vibrating or buzzing motor. If you are interested in the individual 
 * effects, the list of effects can be found on page 57 of the datasheet: 
 * http://www.ti.com/lit/ds/symlink/drv2605.pdf
 * 
 * Modified by: Laveréna Wienclaw for TinyCircuits 
 *************************************************************************/
 
#include <Wire.h>             // For using I2C communication
#include "Adafruit_DRV2605.h" // For interfacing with the DRV2605 chip
#include <Wireling.h>

Adafruit_DRV2605 drv;   // The variable used to interface with the DRV2605 chip
uint8_t effect = 1;     // The global variable used to keep track of Waveform effects

//Make Serial Monitor compatible for all TinyCircuits processors
#if defined(ARDUINO_ARCH_AVR)
  #define SerialMonitorInterface Serial
#elif defined(ARDUINO_ARCH_SAMD)
  #define SerialMonitorInterface SerialUSB
 #endif

void setup() {
  // Initialize and power wireling
  Wireling.begin();

  //The port is the number on the Adapter board where the sensor is attached
  Wireling.selectPort(0);

  SerialMonitorInterface.begin(9600);
  SerialMonitorInterface.println("DRV Effects Test");
  drv.begin();

  drv.selectLibrary(1);

  // I2C trigger by sending 'go' command
  // default, internal trigger when sending GO command
  drv.setMode(DRV2605_MODE_INTTRIG);
  drv.useLRA();
}

int delay_ms = 1000;

// Print the DRV effect number and then play the effect
void loop() {
  setup();
  SerialMonitorInterface.print("Effect #"); 
  SerialMonitorInterface.println(effect);

  // Set the effect to play
  drv.setWaveform(0, effect);  // Set effect
  drv.setWaveform(1, 0);       // End waveform

  // Play the effect
  drv.go();

  // Pause for differentiation between effects
  delay(delay_ms);

  // delay_ms -= 50;

  // if (delay_ms <= 300){
  //   delay_ms=1000;
  // }

  // effect = 30;

  effect++;
  if (effect > 117) effect = 1;
}
