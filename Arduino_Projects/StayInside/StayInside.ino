#include "SumoRobot.h"

SumoRobot robot;


void setup()   {
  Serial.begin(9600);  
}


void loop()                     
{
  bool* lineSensorReadings = robot.readLineSensors();
  bool frontLineSensor = lineSensorReadings[0];
  bool backLineSensor = lineSensorReadings[1];
  
  if (frontLineSensor){
      robot.reverse(500);
      robot.sharpLeft(5);
  } else if (backLineSensor){
      robot.forward(500);
      robot.sharpLeft(5); 
  } else {
     robot.forward(1); 
  }
  
  delay(100);
  
  
}
