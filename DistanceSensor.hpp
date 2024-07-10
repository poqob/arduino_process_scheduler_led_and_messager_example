#include "HardwareSerial.h"
#include <ProcessScheduler.h>
class DistanceProcess : public Process
{
private:
  int trigPin;
  int echoPin;
  long time;
  long distance;
public:
    // Call the Process constructor
    DistanceProcess(Scheduler &manager, ProcPriority pr, unsigned int period, int iterations,int trigPin,int echoPin)
        :  Process(manager, pr, period, iterations) {this->trigPin=trigPin; this->echoPin=echoPin;}

protected:
    // Create our service routine
    virtual void service()
    {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(5);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      time = pulseIn(echoPin, HIGH);
      distance = (time / 29.1) / 2;
      Serial.print("distance:");
      Serial.println(distance);
    }

    virtual void setup(){
      pinMode(this->trigPin, OUTPUT);
      pinMode(this->echoPin, INPUT);
    }
    
    virtual void onEnable()
    {
    }

    virtual void onDisable()
    {
    }

};

// TODO: problem is we are not able to apply custom delay.