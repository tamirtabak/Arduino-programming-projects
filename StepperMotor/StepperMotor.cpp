#include <Arduino.h>
#include "StepperMotor.h"

StepperMotor::StepperMotor(int stepsPerRevolution,int DIR_PIN,int PUL_PIN,int EN_PIN)
{
  _stepsPerRevolution = stepsPerRevolution;
  _DIR_PIN = DIR_PIN;
  _PUL_PIN = PUL_PIN;
  _EN_PIN = EN_PIN;
}

long int StepperMotor::RPMtoPulseDelay(long int RPM,long int stepPerRev)
{
  long int mone = 30*pow(10,6);
  long int machane = RPM*stepPerRev;
  return (mone/machane);
}

void StepperMotor::oneStep(int motorVelocity,long int stepPerRev,bool dirPinState)
{ 
   long int pulDelay = RPMtoPulseDelay(motorVelocity,stepPerRev);
   digitalWrite(_DIR_PIN,dirPinState);
   digitalWrite(_PUL_PIN, HIGH);
   delayMicroseconds(pulDelay);
   digitalWrite(_PUL_PIN, LOW);
   delayMicroseconds(pulDelay);
}

void StepperMotor::turnNRotations(int motorVelocity,long int stepPerRev,bool dirPinState,float numberOfRotations)
{
  long int pulDelay = RPMtoPulseDelay(motorVelocity,stepPerRev);
  unsigned int stepsRotation = numberOfRotations*stepPerRev;
  for(int i=0; i<stepsRotation; i++)
  {
    oneStep(motorVelocity,stepPerRev,dirPinState);
  }
}

void StepperMotor::setStepperDistance(int motorVelocity,long int stepPerRev,bool dirPinState,float distanceMM)
{
  float numberOfRotations = (distanceMM)/(PI*12);
  turnNRotations(motorVelocity,stepPerRev,dirPinState,numberOfRotations);
}
