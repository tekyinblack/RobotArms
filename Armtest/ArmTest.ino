/*
Test program for a 3DOF robot arm with a gripper
Control input if taken from the serial input, there is no error detection and
invalid input can cause the program to fail or the arm to be damaged
*/

#include <Servo.h>

Servo rotate;  
Servo lift;
Servo bend;
Servo claw;

int timer = 10;

int rotateangle = 90;
int liftangle = 90;
int bendangle = 90;
int clawangle = 90;

int v = 0;

void setup() {

  rotate.attach(9);
  delay(500);
  lift.attach(10);
  delay(500);
  bend.attach(11);
  delay(500);
  claw.attach(12);
  Serial.begin(115200);  
  Serial.println("Starting....");
}

void loop() {

  // if there's any serial available, read it:
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    int motor = Serial.parseInt();
    Serial.println(motor);
    // do it again:
    int angle = Serial.parseInt();
    Serial.println(angle);
    Serial.println("Moving...");
    // look for the newline. That's the end of your sentence:
    if (Serial.read() == '\n') {
      Serial.println("Newline found...");
      switch (motor) {
        case 1:
          Serial.print("Rotating to ");
          Serial.println(angle);
          if (angle < rotateangle) {
            for (int i = rotateangle; i >= angle; i--) {
              Serial.print("Rotate ");
              Serial.println(i);
              delay(timer);
              rotate.write(i);
            }
            v = analogRead(A0);
            Serial.print("Complete=");
            Serial.print(v);
          }
          if (angle > rotateangle) {
            for (int i = rotateangle; i <= angle; i++) {
              Serial.print("Rotate ");
              Serial.println(i);
              delay(timer);
              rotate.write(i);
            }
            v = analogRead(A0);
            Serial.print("Complete=");
            Serial.print(v);
          }
          rotateangle = angle;
          break;
        case 2:
          Serial.print("Lifting to ");
          Serial.println(angle);
          if (angle < liftangle) {
            for (int i = liftangle; i >= angle; i--) {
              Serial.print("Lift ");
              Serial.println(i);
              delay(timer);
              lift.write(i);
            }
            v = analogRead(A1);
            Serial.print("Complete=");
            Serial.print(v);
          }
          if (angle > liftangle) {
            for (int i = liftangle; i <= angle; i++) {
              Serial.print("Lift ");
              Serial.println(i);
              delay(timer);
              lift.write(i);
            }
            v = analogRead(A1);
            Serial.print("Complete=");
            Serial.print(v);
          }
          liftangle = angle;
          //      lift.write(angle);
          break;
        case 3:
          Serial.print("Bending to ");
          Serial.println(angle);
          if (angle < bendangle) {
            for (int i = bendangle; i >= angle; i--) {
              Serial.print("Bend ");
              Serial.println(i);
              delay(timer);
              bend.write(i);
            }
            v = analogRead(A2);
            Serial.print("Complete=");
            Serial.print(v);
          }
          if (angle > bendangle) {
            for (int i = bendangle; i <= angle; i++) {
              Serial.print("Bend ");
              Serial.println(i);
              delay(timer);
              bend.write(i);
            }
            v = analogRead(A2);
            Serial.print("Complete=");
            Serial.print(v);
          }
          bendangle = angle;
          //      bend.write(angle);
          break;
        case 4:
          Serial.print("Claw to ");
          Serial.println(angle);
          if (angle < clawangle) {
            for (int i = clawangle; i >= angle; i--) {
              Serial.print("Claw ");
              Serial.println(i);
              delay(timer);
              claw.write(i);
            }
            v = analogRead(A3);
            Serial.print("Complete=");
            Serial.print(v);
          }
          if (angle > clawangle) {
            for (int i = clawangle; i <= angle; i++) {
              Serial.print("Claw ");
              Serial.println(i);
              delay(timer);
              claw.write(i);
            }
            v = analogRead(A3);
            Serial.print("Complete=");
            Serial.print(v);
          }
          clawangle = angle;
          //       claw.write(angle):
          break;
      }
    }
  }
}
