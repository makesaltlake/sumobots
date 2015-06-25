#include "SumoRobot.h"
#include <SoftwareSerial.h>

//#define mySerial Serial
SumoRobot robot;

SoftwareSerial mySerial(8, 7);

void setup()   {
  mySerial.begin(9600);  
  mySerial.setTimeout(100);
  robot.enableBackLineSensor();
  robot.enableBackDistanceSensor();
}


void loop()                     
{
  if (mySerial.available() > 0) {
      int configVal = mySerial.read();
      if (configVal == 'f'){
        robot.forward(1);
      }
      else if (configVal == 'r'){
        robot.right(1);
      }
      else if (configVal == 'l'){
        robot.left(1);
      }
      else if (configVal == 'z'){
        robot.reverse(1);
      }
      else if (configVal == 's'){
        robot.stop();
      }
   }
   
   
   int* distanceSensors = robot.readDistanceSensors();
   bool* lineSensors = robot.readLineSensors();
   String line = "";
   line.concat(String(distanceSensors[0]));
   line.concat(", ");
   line.concat(String(distanceSensors[1]));
   line.concat(", ");
   line.concat(String(distanceSensors[2]));
   line.concat(", ");
   line.concat(String(lineSensors[0]));
   line.concat(", ");
   line.concat(String(lineSensors[1]));

   mySerial.println(line);
}
