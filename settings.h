#ifndef SETTINGS
#define SETTINGS
    
    //Motors pwm
    #define motorRightPWM 180//255
    #define motorLeftPWM 173//250
    
    //Pin define
   
    #define motorRightBackward 5
    #define motorRightForward 6
    #define motorLeftBackward 10
    #define motorLeftForward 11
    
    #define SensorUSLeft_Trig 2
    #define SensorUSLeft_Echo 3
    #define SensorUSUp_Trig 4
    #define SensorUSUp_Echo 5
    #define SensorUSRight_Trig 6
    #define SensorUSRight_Echo 7
    #define SensorUSBottom_Trig 12
    #define SensorUSBottom_Echo 13


   
    //csts
    #define minimalDistance 5
    #define rotate90timeRight 880
    #define rotate180timeRight 1500
    #define rotate90timeLeft 820
    #define rotate180timeLeft 1551
    #define forward25cmtime 1050
    #define SensorLeftLimitDetect 5
    #define SensorRightLimitDetect 5
    #define SensorBottomimitDetect 5
    #define SensorUpLimitDetect 5
    
#endif

