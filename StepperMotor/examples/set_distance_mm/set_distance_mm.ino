/*
 * This code makes a stepper motor to turn the exact number of revolutions required
 * to move a linear timing belt "d" milimeters.
 * d = pi*D*n
 * where : 
 * pi =3.14
 * D = 12 [mm] the diameter of standard timing belt pully.
 * n = number of revolutions required. (a float parameter).
 * 
 * ******************NOTE: this function is suitable ONLY if a 12 [mm] diameter pully gear is used!***************
 */
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
  //turning stepper motor 37.7 [mm] CCW direction((37.7)/(PI*12) = 1 revolution))
  cartMotor.setStepperDistance(RPM,stepsPerRevolution,CCW,37.7);
  delay(1000);

   //turning stepper motor 37.7 [mm] CW direction((37.7)/(PI*12) = 1 revolution))
  cartMotor.setStepperDistance(RPM,stepsPerRevolution,CW,37.7);
  delay(1000);
}
