#include <NewPing.h>
#include "settings.h"
#include "basic.h"

NewPing sonarright(12, 13, 40);
NewPing sonarmidright(8, 9, 40);
NewPing sonarmid(3, 4, 40);
NewPing sonarmidleft(3, 4, 40);

void forwardTo(int val);

void setup() {
  // put your setup code here, to run once:
  init_motors();
  Serial.begin(9600);
  //while(1){Serial.println(sonarmid.ping_cm());delay(20);}
  forwardToOnlyMid(sonarmid,15,2);
  turnLeft(650);
  asservRight();
  while(1);{
    if (asservRight())
    {forward(300);rotateRight(500);forward(1500);rotateRight(500);forward(1000);}
    else {turnLeft(650);}
  }
  stopMotors();  
  while(1);
  for(int i=0;i<2;i++){
        forwardToOnlyMid(sonarmid,15,2);
        delay(500);
        turnLeft(650);
        delay(500);
        forwardToOnlyMid(sonarmid,15,2);
        delay(500);
        turnLeft(650);
        delay(500);
        forwardToEmptyRight();
        delay(500);
        turnRight(650);
        delay(500);
        forward(1250);
        delay(500);
        turnRight(650);
  }

        
      
  //leanRight(3000);
 // nextlevel();
// backwardToEmptyAsservRight(7);

//  myNextLevel();
  while(1);
  while (1)  nextlevel();
}


void loop() {
  
}
void forwardToEmptyRight(){
char i = 0, j = 0;
  int cr;
  int c;
  while ((i < 4) && (j < 4))
  {
    cr = sonarright.ping_cm();
    c = sonarmid.ping_cm();
    delay(10);
    Serial.print(c);
    Serial.print(' ');    Serial.println(cr);
    if ((c < 30) && (c != 0))
      j++;
    else j = 0;
    if (cr == 0)
      i++;
    else {
      i = 0;
      forward();
    }
  }
  stopMotors();  
}



void myNextLevel(){
    /*
     * un seule cas critique lorsque on a une porte prés de 15 cm du mur à droite
     */
  forwardToOnlyMid(sonarmid,20,2);
while(1);
  
  //turnLeft(550); // pwm 150 -> 1000ms
  char im = 0,ir = 0;

  while((sonarmid.ping_cm() != 0)||(sonarright.ping_cm()>16)||(sonarright.ping_cm() == 0))
      turnLeft();
   
  char correctionType = 0;
  int drref = sonarright.ping_cm();
  while(1){
    int m = sonarmid.ping_cm();
    delay(20);
    int r = sonarright.ping_cm();
    //int b = sonarmidright.ping_cm(); 
    Serial.print(m);
    Serial.print(" ");
    Serial.println(r);
    /*if (b<20)
    {
      forward(motorLeftPWM,motorRightPWM+20);
    }else if (b)
    {
      forward(motorLeftPWM+20,motorRightPWM);
    }else */if (r == 0)
    {
      stopMotors();
      pinMode(13,OUTPUT);
      digitalWrite(13,1);
      Serial.println("r==0");
      while(1);
      leanRight(250);
      delay(20);
      forward(500);
      delay(20);
      leanRight(1000);
    }else if ((m == 0)||(m>16)){
       if (r<drref-2)//leanleft
          //leanLeft(10);
        forward(motorLeftPWM,motorRightPWM+22);
      else if (r>drref+2)
        {//leanright
          if(r<20)
              forward(motorLeftPWM+5+r,motorRightPWM);
          else forward(motorLeftPWM+23,motorRightPWM);
        }
      else forward();
    }else if (m< 14)
      backward();
    else {stopMotors();pinMode(13,OUTPUT);digitalWrite(13,0);while(1);}
    
  }
  forwardToEmptyAsservRight(14);

  turnLeft(650); // pwm 150 -> 1000ms

  forwardToEmptyAsservRight(14);

  
   forward(motorLeftPWM,motorRightPWM/4);
    delay(900);
    stopMotors();

    leanRight(250);
    delay(20);
    forward(500);
    delay(20);
    leanRight(1000);

  //forwardToOnlyMid(sonarright,5,4);

}
int asservRight()
{    
  int motorleftpwm,motorrightpwm;
  int index=0;
  
  
  while(index<2){
  motorrightpwm=120;
      motorleftpwm=120;
    int cm = sonarmid.ping_cm();
    delay(10);
    if ((cm < 12)&&(cm>0))
         index++;
    else index=0;
    int cr = sonarright.ping_cm();
    delay(10);
    Serial.print(cr);
    Serial.print(' ');
    if (cr==0){stopMotors();return 1;forward(300);rotateRight(500);forward(1500);rotateRight(500);forward(1000);}
 float e=10-cr; 
      if ((e>0)&&(e<1)) {
              motorrightpwm=e*12+motorrightpwm;
              motorleftpwm=120;
      }
      if ((e<0)&&e>-1) {
        e=-e;motorleftpwm=e*12+motorleftpwm;motorrightpwm=120;}
        
         if ((e>=1)&&(e<3)) {
              motorrightpwm=e*6+motorrightpwm;motorleftpwm=120;
      }
      
      if ((e<=-1)&&(e>-3)) {
        e=-e;motorleftpwm=e*6+motorleftpwm;motorrightpwm=120;}
         if ((e>=3)) {leanLeft(300);leanRight(150);
             }
      
      if (e<=-3) {
          leanRight(220);
          leanLeft(150);
       }

      if(e==0){
          motorrightpwm=120;
          motorleftpwm=120;
      }
      forward();
  }
  stopMotors();
  return 0;
            
}


void nextlevel()
{
  forwardTo(15);
  while(1);
  turnLeft(1000);
  
  
  if (forwardToEmptyAsservRight(9) == 0)
  {
   backwardToEmptyAsservRight(9);
    backLeft();
    delay(950);
    forward(1000) ;
    stopMotors();
  } else leanRight(1100);

}

void nextLevel2CapteurMaxSpeed()
{
/*
 * Bug List:
 *   - Robot prés du mur gauche il entre dans le coin et il se bloque distance minimale du mur 15cm
 */
  forwardToOnlyMid(sonarmid,15,2);

  turnLeft(650); // pwm 150 -> 1000ms

  if (forwardToEmptyAsservRight(9) == 0)
  {
    backwardToEmptyAsservRight(9);
    backLeft(700);//pwm = 150 -> 950
    forward(1000) ;
  } else {
    forward(motorLeftPWM,motorRightPWM/4);
    delay(900);
    stopMotors();
  }

}
void forwardToOnlyMid(NewPing k,int val,int tolerance)
{
  char i = 0;
  while (i < 4)
  {
    int c = k.ping_cm();
    delay(10);
    Serial.print(c);
    Serial.print(' ');
    if ((c >= val - tolerance) && (c <= val + tolerance))
      i++;
    else {
      i = 0;
      if ((c > val) || (c == 0)) {
        forward();
      } else {
        backward();
        }
      }
  }
  stopMotors();
}
#define between(val,_min,_max) ((val >= _min)&&(val <= _max))
void forwardTo(int val) {
  /*char i = 0,j = 0,k = 0;
  while(i < 4)
  {
    //int c = sonar.ping_cm();
    //delay(30);
    int cmr = sonarmidright.ping_cm();
    if (cmr == 0) cmr = 255;
    delay(10);
    int cml = sonarmidleft.ping_cm();
    if (cml == 0) cml = 255;
    delay(10);
    bool l1 = between(cml,val-2,val + 6);
    bool r1 = between(cmr,val-2,val + 6);
    if (l1 && r1)
    {
      stopMotors();
    }
    
    
    
    delay(500);
    
  }*/
    char i = 0,l=0,r=0;
  while (i < 4)
  {
    int cmr = sonarmidright.ping_cm();
    if (cmr == 0) cmr = 255;
    delay(10);
    int cml = sonarmidleft.ping_cm();
    if (cml == 0) cml = 255;
    delay(10);
    bool l1 = between(cml,val-2,val + 6);
    bool r1 = between(cmr,val-2,val + 6);
    
    Serial.print(cml);
    Serial.print(' ');
    Serial.print(cmr);
    Serial.println(' ');
    if (l1 && r1)
    {
      i++;
      stopMotors();
    }else{
      i = 0;
      if ((cml == 255)&&(cmr == 255)) {
        forward();
      }else if (cml == 255)
      {
        l++;
        r = 0;
        if (l == 4)
          zigzagLeft();
      }else if (cmr == 255)
      {
        r++;
        l = 0;
        if (r == 4)
          zigzagRight();
      }
      else {
        r = 0;
        l = 0;
        stopMotors();
      }
      
    }
  }

  stopMotors();
}
void zigzagLeft()
{
    int t1 = millis();
    //forward(motorLeftPWM/3,motorRightPWM);//leanLeft();
    int cmr1,rp1=0;
    while(rp1 < 4){
      if(sonarmidright.ping_cm() == 0)
        rp1++;
      else rp1 = 0;
      delay(20);
    }
    //forward(motorLeftPWM,motorRightPWM/3);//leanRight(millis() - t1);  
    delay(millis() - t1);
    stopMotors();
}
void zigzagRight()
{
    int t1 = millis();
    //forward(motorLeftPWM,motorRightPWM/3);//leanRight();
    int cmr1,rp1=0;
    while(rp1 < 4){
      if(sonarmidleft.ping_cm() == 0)
        rp1++;
      else rp1 = 0;
      delay(20);
    }
    //forward(motorLeftPWM/3,motorRightPWM);//leanLeft(millis() - t1);  
    delay(millis() - t1);
    stopMotors();
}


bool forwardToEmptyAsservRight(int val) {
  char i = 0, j = 0;
  int cr;
  int c;
  while ((i < 4) && (j < 4))
  {
    cr = sonarright.ping_cm();
    c = sonarmid.ping_cm();
    delay(10);
    Serial.print(c);
    Serial.print(' ');    Serial.println(cr);
    if ((c < 30) && (c != 0))
      j++;
    else j = 0;
    if (cr == 0)
      i++;
    else {
      i = 0;
      if ((cr >= val - 2) && (cr <= val + 2)) {
        forward();
      } else if ((cr < val - 2)&&(cr!=0)) {
        leanLeft();
      } else {
        leanRight();
      }
    }
  }
  stopMotors();
  return i == 4; //true = we found the door
}

bool backwardToEmptyAsservRight(int val) {
  char i = 0;
  int cr;
  while (i < 3)
  {
    cr = sonarright.ping_cm();
    delay(5);
    Serial.print(cr);
    Serial.print(' ');
    if (cr == 0)
      i++;
    else {
      i = 0;
      if ((cr >= val - 2) && (cr <= val + 2)) {
        backward();
      } else if ((cr < val )&&(cr!=0)) {
        leanBackLeft();
      } else {
        leanBackRight();
      }
    }
  }
  stopMotors();
  return true;
}

bool backwardToEmptyAsservLeft(int val) {
  char i = 0;
  int cr;
  while (i < 3)
  {
    cr = sonarright.ping_cm();
    delay(5);
    Serial.print(cr);
    Serial.print(' ');
    if (cr == 0)
      i++;
    else {
      i = 0;
      if ((cr >= val - 2) && (cr <= val + 2)) {
        backward();
      } else if ((cr < val )&&(cr!=0)) {
        leanBackLeft();
      } else {
        leanBackRight();
      }
    }
  }
  stopMotors();
  return false;
}
/*
void straight (int val, int d)
{ int cr, c ; 
cr = sonarright.ping_cm() ;
c = sonar.ping_cm() ;
while ((c < val )&& (c!=0)) 
 { if (cr ==d)
 forward(val) ; 
 else { if ((cr <d )&&(cr !=0))
   
  { if (c > 1){
    forward (500) ;
   leanLeft() ;}
   else { backward(500) ;
   leanLeft();}}

 else { if ((cr > d )&& (cr !=0))  
    if (c > 1){
    forward (500) ;
   leanLeft() ;}
   else { backward(500) ;
   leanLeft();
   }
 }
 

 */
