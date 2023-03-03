#include <StepperMotor.h>
// CCW = counter clockwise , CW = clockwise.
#define CCW HIGH
#define CW LOW

//Setting stepper microstep driver pins
const int DIR_PIN = 9;
const int PUL_PIN = 10;
const int EN_PIN = 11;

//Setting the steps per revolution based on TB6600 microdriver configuration
const long int stepsPerRevolution = 800;  

//Setting desired RPM that the motor will rotate
long int RPM = 60;

//Declaring a StepperMotor variable with the following parameters
StepperMotor cartMotor(stepsPerRevolution,DIR_PIN,PUL_PIN,EN_PIN);

void setup()
{
  pinMode (DIR_PIN, OUTPUT);
  pinMode (PUL_PIN, OUTPUT);
  pinMode (EN_PIN, OUTPUT);
  digitalWrite(PUL_PIN, LOW);
}

void loop() 
{
  //turning stepper motor 1 revolution CCW direction
  cartMotor.turnNRotations(RPM,stepsPerRevolution,CCW,1);
  delay(1000);

  //turning stepper motor 1 revolution CW direction
  cartMotor.turnNRotations(RPM,stepsPerRevolution,CW,1);
  delay(1000);
}
