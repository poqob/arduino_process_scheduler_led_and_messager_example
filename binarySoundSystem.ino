#include <ProcessScheduler.h>
#include "HardwareSerial.h"
#include "LedProcess.hpp"
#include "MessageProcess.hpp"
#include "DistanceSensor.hpp"
#include "SerialListener.hpp"


Scheduler sched; // Create a global Scheduler object

// Create our high priority process that will get serviced as often as possible and run forever
LedProcess myProc(sched, HIGH_PRIORITY, 200, RUNTIME_FOREVER,8);
LedProcess myProc1(sched, HIGH_PRIORITY, 2500, RUNTIME_FOREVER, 9);
LedProcess myProc2(sched, HIGH_PRIORITY, 2000, RUNTIME_FOREVER,10);
MessageProcess msg0(sched, LOW_PRIORITY, 10000, RUNTIME_FOREVER,"MESSAGGE FROM CONSOLE");
MessageProcess msg1(sched, HIGH_PRIORITY, 1000, RUNTIME_FOREVER,"second");
MessageProcess msg2(sched, HIGH_PRIORITY, 1000, RUNTIME_FOREVER,"third");
SerialListener ser(sched, HIGH_PRIORITY, 1000, RUNTIME_FOREVER);
DistanceProcess dst0(sched, HIGH_PRIORITY, 5, RUNTIME_FOREVER,3,2);
DistanceProcess dst1(sched, HIGH_PRIORITY, 5, RUNTIME_FOREVER,5,4);

void setup() 
{

    Serial.begin(9600);
    msg0.add(true);
    myProc.add(true);
    dst0.add(true);
    dst1.add(true);
    ser.add(true);

}

void loop() 
{
    sched.run();
}