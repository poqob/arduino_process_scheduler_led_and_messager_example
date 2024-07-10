#include <ProcessScheduler.h>

class LedProcess : public Process
{
  bool status;
  int gpio;
public:
    // Call the Process constructor
    LedProcess(Scheduler &manager, ProcPriority pr, unsigned int period, int iterations,int gpio)
        :  Process(manager, pr, period, iterations) {this->gpio=gpio;this->status=true;}
  
  String toString(){
    String _output="gpio:";
    _output+=gpio;
    _output+=" id:";
    _output+=getID();
    _output+=" status:";
    _output+=this->status;
    return _output;
  }

  
  
  

protected:
    // Create our service routine
    virtual void service()
    {
        //Serial.println(this->toString());
        digitalWrite(this->gpio, HIGH*this->status);

        if(this->status==true)
          this->status=false;
        else
          this->status=true;
    }

    virtual void setup(){
      pinMode(this->gpio, OUTPUT); 
    }
    
    virtual void onEnable()
    {
    }

    virtual void onDisable()
    {
    }
};