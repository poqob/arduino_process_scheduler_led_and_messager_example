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
MessageProcess msg0(sched, HIGH_PRIORITY, 3000, RUNTIME_FOREVER,"first");
MessageProcess msg1(sched, HIGH_PRIORITY, 1000, RUNTIME_FOREVER,"second");
MessageProcess msg2(sched, HIGH_PRIORITY, 1000, RUNTIME_FOREVER,"third");
SerialListener ser(sched, HIGH_PRIORITY, 2000, RUNTIME_FOREVER);
DistanceProcess dst0(sched, HIGH_PRIORITY, 1000, RUNTIME_FOREVER,2,3);

void setup() 
{

    Serial.begin(9600);
    msg0.add(true);
    myProc.add(true);
    dst0.add();
    dst0.enable();

}

void loop() 
{
    sched.run();
}