#ifndef StepperMotor_h
#define StepperMotor_h

#include <Arduino.h>
class StepperMotor
{
  public:
    StepperMotor(int stepsPerRevolution,int DIR_PIN,int PUL_PIN,int EN_PIN);
    long int RPMtoPulseDelay(long int RPM,long int stepPerRev);
    void oneStep(int motorVelocity,long int stepPerRev,bool dirPinState);
    void turnNRotations(int motorVelocity,long int stepPerRev,bool dirPinState,float numberOfRotations);
    void setStepperDistance(int motorVelocity,long int stepPerRev,bool dirPinState,float distanceMM);
    
  private:
    int _stepsPerRevolution;
    int _DIR_PIN;
    int _PUL_PIN;
    int _EN_PIN;
};

#endif
