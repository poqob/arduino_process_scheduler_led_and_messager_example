#include <ProcessScheduler.h>
class MessageProcess : public Process
{
  String msg;
public:
    // Call the Process constructor
    MessageProcess(Scheduler &manager, ProcPriority pr, unsigned int period, int iterations,String msg)
        :  Process(manager, pr, period, iterations) {this->msg=msg;}

protected:
    // Create our service routine
    virtual void service()
    {
        Serial.print("message:");
        Serial.println(msg);
    }

};