#include <RoboticArm_ESPNOW.h>
#include <RoboticArm.h>
#include "PressureSensors.h"
#include "ArmControl.h"
#include <SPI.h>

TaskHandle_t pressureSensor;
TaskHandle_t armControl;

volatile bool ESPNOW_setup;

hw_timer_t *Timer0 = NULL;
volatile bool timer0_triggered = false; // Flag to indicate timer interrupt occurrence
hw_timer_t *Timer1 = NULL;
volatile bool timer1_triggered = false; // Flag to indicate timer interrupt occurrence

void IRAM_ATTR Timer0_ISR();
void IRAM_ATTR Timer1_ISR();

void triggerArmControl(){
  controlArm();
}

void triggerPressureSensors() {
  sendPressureData();
}

void armControlCode(void* params){
  Serial.print("Setting up armControl from core ");
  Serial.println(xPortGetCoreID());
  armControlSetup();
  uint8_t mac[] = PEER_MAC;
  arm_ESPNOWsetup(mac);
  ESPNOW_setup = true;

  Timer0 = timerBegin(0, 80, true); // timer speed (Hz) = Timer clock speed (Mhz) / prescaler --> 1 MHz
  timerAttachInterrupt(Timer0, &Timer0_ISR, true); // Attach ISR0 to Timer0
  timerAlarmWrite(Timer0, 1000000/ISR0_FREQ, true); // Set timer to trigger every 1,000,000/ISR0_FREQ microseconds (1 s/f)
  timerAlarmEnable(Timer0); // Enable the timer alarm

  while (1) {
      if (timer0_triggered) { 
          timer0_triggered = false; // Reset the flag
          triggerArmControl();
      }
      vTaskDelay(10 / portTICK_PERIOD_MS); // Yield CPU for 10 ms to prevent blocking other tasks
  }

}

void pressureSensorCode(void* params){
  Serial.print("Setting up pressureSensor ISR from core ");
  Serial.println(xPortGetCoreID());
  setupPressureSensors();
  while(!ESPNOW_setup){
    vTaskDelay(10 / portTICK_PERIOD_MS); // Yield CPU for 20 ms
  }
  Serial.print("Setting up pressureSensor ISR");

  Timer1 = timerBegin(1, 80, true); // timer speed (Hz) = Timer clock speed (Mhz) / prescaler --> 1 MHz
  timerAttachInterrupt(Timer1, &Timer1_ISR, true); // Attach ISR1 to Timer1
  timerAlarmWrite(Timer1, 1000000/ISR1_FREQ, true); // Set timer to trigger every 1,000,000/ISR1_FREQ microseconds (1 s/f)
  timerAlarmEnable(Timer1); // Enable the timer alarm

  while (1) {
      if (timer1_triggered) { 
          timer1_triggered = false; // Reset the flag
          triggerPressureSensors();
      }
      vTaskDelay(10 / portTICK_PERIOD_MS); // Yield CPU for 10 ms to prevent blocking other tasks
  }
}

void setup() {
  // Start the Serial Monitor
  int baud_rate = 115200;
  Serial.begin(baud_rate);
  Serial.println("initializing . . .");
  ESPNOW_setup = false;
  pinMode(LED_0, OUTPUT);

    // assign armControl to core 0
  xTaskCreatePinnedToCore(
      armControlCode,   // function
      "armControl",     // name
      10000,       // stack depth
      NULL,        // parameters (void*)
      1,           // uxPriority
      &armControl,      // task handle (tracking)
      0);          // coreID

    // assign pressureSensor to core 1
  xTaskCreatePinnedToCore(
      pressureSensorCode,   // function
      "pressureSensor",     // name
      10000,       // stack depth
      NULL,        // parameters (void*)
      1,           // uxPriority
      &pressureSensor,      // task handle (tracking)
      1);          // coreID
}

// Interrupt Service Routine (ISR) for Timer0
void IRAM_ATTR Timer0_ISR() {
  timer0_triggered = true;  // Set a flag for the task to handle instead of printing directly
}

// Interrupt Service Routine (ISR) for Timer1
void IRAM_ATTR Timer1_ISR() {
  timer1_triggered = true;  // Set a flag for the task to handle instead of printing directly
}

void loop() {}
