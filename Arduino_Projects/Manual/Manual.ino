#include "SumoRobot.h"

SumoRobot robot;

void setup()   {
  Serial.begin(9600);  
  Serial.setTimeout(100);
  robot.enableBackLineSensor();
  robot.enableBackDistanceSensor();
}


void loop()                     
{
  if (Serial.available() > 0) {
      int configVal = Serial.read();
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

   Serial.println(line);
}
