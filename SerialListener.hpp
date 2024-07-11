#include "HardwareSerial.h"
#include "Arduino.h"
#include <ProcessScheduler.h>
class SerialListener : public Process {
public:
  // Call the Process constructor
  SerialListener(Scheduler &manager, ProcPriority pr, unsigned int period, int iterations)
    : Process(manager, pr, period, iterations) {
  }

protected:
  String input = "";
  // Create our service routine
  virtual void service() {

    if (Serial.available()) {
      //input = Serial.readStringUntil('\n');
      input = Serial.readStringUntil('\n');
      if (input == "on")
        digitalWrite(6, HIGH);
      if (input == "off")
        digitalWrite(6, LOW);
      Serial.println(input);
    }
  }

  virtual void setup() {
    pinMode(6, OUTPUT);
  }

  virtual void onEnable() {
  }

  virtual void onDisable() {
  }
};