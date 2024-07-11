#include "HardwareSerial.h"
#include <ProcessScheduler.h>
class DistanceProcess : public Process {
private:
  int trigPin;
  int echoPin;
  long time;
  long distance;


  unsigned long previousMillis = 0;  // Stores the last time the action was taken
  const long interval = 1000;        // Interval at which to repeat the action (milliseconds)
  unsigned long triggerStartMillis = 0;
  unsigned long triggerHighMillis = 0;
  bool triggered = false;
  bool measuring = false;
public:
  // Call the Process constructor
  DistanceProcess(Scheduler &manager, ProcPriority pr, unsigned int period, int iterations, int trigPin, int echoPin)
    : Process(manager, pr, period, iterations) {
    this->trigPin = trigPin;
    this->echoPin = echoPin;
  }

protected:
  // Create our service routine
  virtual void service() {
    this->force();
  }

  virtual void setup() {
    pinMode(this->trigPin, OUTPUT);
    pinMode(this->echoPin, INPUT);
  }

  virtual void force() {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      // Start the trigger pulse
      digitalWrite(trigPin, LOW);
      triggerStartMillis = currentMillis;
      triggered = true;
      measuring = false;
    }

    if (triggered && (currentMillis - triggerStartMillis >= 5)) {
      // Set the trigPin to HIGH for 10 microseconds
      digitalWrite(trigPin, HIGH);
      triggerHighMillis = currentMillis;
      triggered = false;
      measuring = true;
    }

    if (measuring && (currentMillis - triggerHighMillis >= 10)) {
      // Set the trigPin back to LOW and start measuring
      digitalWrite(trigPin, LOW);
      measuring = false;

      long duration = pulseIn(echoPin, HIGH);
      float distance = (duration / 29.1) / 2;
      Serial.print("distance: ");
      Serial.println(distance);
    }
  }

  virtual void onEnable() {
  }

  virtual void onDisable() {
  }
};

// TODO: problem is we are not able to apply custom delay.