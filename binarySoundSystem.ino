#include <ProcessScheduler.h>
#include "LedProcess.hpp"
#include "MessageProcess.hpp"


Scheduler sched; // Create a global Scheduler object

// Create our high priority process that will get serviced as often as possible and run forever
LedProcess myProc(sched, HIGH_PRIORITY, 500, RUNTIME_FOREVER,8);
LedProcess myProc1(sched, HIGH_PRIORITY, 100, RUNTIME_FOREVER, 9);
LedProcess myProc2(sched, HIGH_PRIORITY, 200, RUNTIME_FOREVER,10);
MessageProcess msg0(sched, HIGH_PRIORITY, 2000, RUNTIME_FOREVER,"Dag");
MessageProcess msg1(sched, HIGH_PRIORITY, 3000, RUNTIME_FOREVER,"lumburs");

void setup() 
{

    Serial.begin(9600);
    // Add our process to the scheduler
    myProc.add();
    myProc1.add();
    myProc2.add();
    msg0.add();
    msg1.add();
    //enable it
    myProc.enable();
    myProc1.enable();
    myProc2.enable();
    msg0.enable();
    msg1.enable();
}

void loop() 
{
    sched.run();
}