#include "SumoRobot.h"
#include "SoftwareSerial.h"
SumoRobot robot;

#define mySerial Serial
//SoftwareSerial mySerial(6, 5);

void setup()   {
  
  mySerial.begin(9600);  
  mySerial.setTimeout(1000);
  //robot.enableBackLineSensor();
  //robot.enableBackDistanceSensor();
}


void loop()                     
{
    int configVal = mySerial.read();
    if (configVal == 'f'){
      robot.forward(); 
    }
    else if (configVal == 'r'){
      robot.right();
    }
    else if (configVal == 'l'){
      robot.left();
    }
    else if (configVal == 'z'){
      robot.reverse();
    }
    else if (configVal == 's'){
      robot.stop();
    }
}
