#ifndef BASIC
#define BASIC

  void init_motors();
  void stopMotors();
  void stopMotorsAfter(unsigned int ms);
  
  void forward(unsigned char speedleft,unsigned char speedright);
  void forward();
  void forward(unsigned int ms);
  
  void backward(unsigned char speedleft,unsigned char speedright);
  void backward();
  void backward(unsigned int ms);
  
  void turnLeft();
  void turnLeft(unsigned int ms);
  void backLeft();
  void backLeft(unsigned int ms);
  void turnRight();
  void turnRight(unsigned int ms);
  void backRight();
  void backRight(unsigned int ms);  
  
  void rotateLeft();
  void rotateLeft(unsigned int ms);
  void rotateRight();
  void rotateRight(unsigned int ms);

  void leanRight();
  void leanRight(unsigned int ms);
  void leanBackRight();
  void leanBackRight(unsigned int ms);
  
  void leanLeft();
  void leanLeft(unsigned int ms);
  void leanBackLeft();
  void leanBackLeft(int ms);
    
#endif


