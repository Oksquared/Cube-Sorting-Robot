#include <AccelStepper.h>
#include <MultiStepper.h>

#include <Servo.h>
const int baseStepperPin1 = 4;
const int baseStepperPin2 = 5;
const int baseStepperPin3 = 6;
const int baseStepperPin4 = 7;
const int gripperServoPin = 3;
const int baseJointServoPin = 2;

AccelStepper baseStepper(AccelStepper::FULL4WIRE, baseStepperPin1, baseStepperPin2, baseStepperPin3, baseStepperPin4);

Servo gripperServo;
Servo baseJointServo;

const int gripperFullOpenDegrees = 120;
const int gripperFullCloseDegrees = 0;
void setup() {
  // put your setup code here, to run once:
  baseStepper.setMaxSpeed(50);
  baseStepper.setAcceleration(200);
  baseJointServo.attach(baseJointServoPin);
  gripperServo.attach(gripperServoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  baseStepperGoTo(200);
  delay(200);
  baseStepperGoTo(-200);
  delay(200);
  openGripper();
  delay(200);
  closeGripper();
  delay(200);
  baseJointServoGoTo(90);
  delay(200);
  baseJointServoGoTo(0);
  delay(200);
}


//________________________THESE ARE JUST WRAPPERS FOR EACH JOINT_________________

void baseStepperGoTo(int pos) {
  baseStepper.runToNewPosition(pos);
}
void baseJointServoGoTo(int pos) {
  baseJointServo.write(pos);  //angle in degrees
}
void openGripper() {
  gripperServo.write(gripperFullOpenDegrees);  //just open it
}
void openGripper(int pos) {
  gripperServo.write(pos);  //angle in degrees
}
void closeGripper() {
  gripperServo.write(gripperFullCloseDegrees);  //just close it
}
void closeGripper(int pos) {
  gripperServo.write(pos);  //angle in degrees
}