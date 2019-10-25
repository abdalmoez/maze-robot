#include <Arduino.h>
#include "settings.h"

void init_motors()
{
  pinMode(motorRightForward,OUTPUT);
  pinMode(motorRightBackward,OUTPUT);
  pinMode(motorLeftForward,OUTPUT);
  pinMode(motorLeftBackward,OUTPUT);
}



void forward(unsigned char speedleft,unsigned char speedright){
  analogWrite(motorRightForward,speedright);
  analogWrite(motorRightBackward,0);
  analogWrite(motorLeftForward,speedleft);
  analogWrite(motorLeftBackward,0);
}
void stopMotors(){
  forward(0,0);
}
void stopMotorsAfter(unsigned int ms){
  delay(ms);
  stopMotors();
}
void backward(unsigned char speedleft,unsigned char speedright){
  analogWrite(motorRightForward,0);
  analogWrite(motorRightBackward,speedright);
  analogWrite(motorLeftForward,0);
  analogWrite(motorLeftBackward,speedleft);
}
void forward(){
  forward(motorLeftPWM,motorRightPWM);
}


void forward(unsigned int ms){
  forward();
  stopMotorsAfter(ms);
}

void backward(){
    backward(motorLeftPWM,motorRightPWM);
}
void backward(unsigned int ms){
  backward();
  stopMotorsAfter(ms);
}

void turnLeft(){  
  forward(0,motorRightPWM);
}
void turnLeft(unsigned int ms){
  turnLeft();
  stopMotorsAfter(ms);
}
void backLeft(){
  backward(0,motorRightPWM);  
}
void backLeft(unsigned int ms){
  backLeft();
  stopMotorsAfter(ms);
}
void turnRight(){
    forward(motorLeftPWM,0);
}
void turnRight(unsigned int ms){
  turnRight();
  stopMotorsAfter(ms);
}
void backRight(){
  backward(motorLeftPWM,0);  
}
void backRight(unsigned int ms){
  backLeft();
  stopMotorsAfter(ms);
}
void rotateLeft(){
  analogWrite(motorRightForward,motorRightPWM);
  analogWrite(motorRightBackward,0);
  analogWrite(motorLeftForward,0);
  analogWrite(motorLeftBackward,motorLeftPWM);
}
void rotateLeft(unsigned int ms){
  rotateLeft();
  stopMotorsAfter(ms);
}

void rotateRight(){
  analogWrite(motorRightForward,0);
  analogWrite(motorRightBackward,motorRightPWM);
  analogWrite(motorLeftForward,motorLeftPWM);
  analogWrite(motorLeftBackward,0);
}
void rotateRight(unsigned int ms){
  rotateRight();
  stopMotorsAfter(ms);
}



void leanRight(){
   forward(motorLeftPWM,motorRightPWM/2);
}
void leanRight(unsigned int ms){
  leanRight();
  stopMotorsAfter(ms);
}
void leanBackRight(){
  backward(motorLeftPWM,2*motorRightPWM/3);
}
void leanBackRight(unsigned int ms){
  leanBackRight();
  stopMotorsAfter(ms);
}
void leanLeft(){
   forward(motorLeftPWM / 2,motorRightPWM);
}
void leanLeft(unsigned int ms){
  leanLeft();
  stopMotorsAfter(ms);
}
void leanBackLeft(){
   backward(2*motorLeftPWM/3,motorRightPWM);
}
void leanBackLeft(int ms){
  leanBackLeft();
  stopMotorsAfter(ms);
}



