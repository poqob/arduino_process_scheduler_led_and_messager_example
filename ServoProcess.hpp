#include <stdint.h>
#include "HardwareSerial.h"
#include "Arduino.h"
#include <Servo.h>
#include <ProcessScheduler.h>
class ServoProcess : public Process {
public:
  uint8_t servoPin;
  Servo servo;
  int angle = 10;
  // Call the Process constructor
  ServoProcess(Scheduler &manager, ProcPriority pr, unsigned int period, int iterations, uint8_t servoPin)
    : Process(manager, pr, period, iterations) {
    this->servoPin = servoPin;
  }

protected:
  String input = "";
  // Create our service routine
  virtual void service() {

    for (angle = 10; angle < 180; angle++) {
      servo.write(angle);
    }
    // now scan back from 180 to 0 degrees
    for (angle = 180; angle > 10; angle--) {
      servo.write(angle);
    }
  }

  virtual void setup() {
    servo.attach(this->servoPin);
    servo.write(angle);
  }

  virtual void onEnable() {
  }

  virtual void onDisable() {
  }
};