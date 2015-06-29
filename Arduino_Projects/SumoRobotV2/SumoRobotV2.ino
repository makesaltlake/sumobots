#include "SumoRobot.h"
#include <SoftwareSerial.h>

#define DIST_SENSOR_THRESHOLD 200

//#define mySerial Serial
SoftwareSerial mySerial(8, 7); //Blue Robot 1
//SoftwareSerial mySerial(8, 7); //Red Robot 2
//SoftwareSerial mySerial(7, 6); //Red Robot 2


SumoRobot robot;
bool turboSpeedEnabled = false;
bool advancedSearchMode = false;

void setup()   {
  /*
  mySerial.begin(9600);
  Serial.begin(9600);
  mySerial.setTimeout(60000);
  
  char configStr[10];
  mySerial.readBytesUntil('*', configStr, 10);
  Serial.println(String(configStr));
    
  if (configStr[0] == '3'){
    robot.enableBackDistanceSensor();
    Serial.println("back dist sensor enabled");
  } 
  if (configStr[1] == '2'){
    robot.enableBackLineSensor();
    Serial.println("back line sensor enabled");
  }
  if (configStr[0] == '2'){
    turboSpeedEnabled = true;
    Serial.println("turbo speed enabled");
  }
  if (configStr[0] == '4'){
    advancedSearchMode = true;
    robot.enableBackDistanceSensor();
    Serial.println("adv search enabled");
  }

   */
  robot.enableBackLineSensor();
  robot.enableBackDistanceSensor();
}


void loop()                     
{
  bool* lineSensorReadings = robot.readLineSensors();
  bool frontLineSensor = lineSensorReadings[0];
  bool backLineSensor = lineSensorReadings[1];
	
  int* distanceSensorReadings = robot.readDistanceSensors();
  int leftDistanceSensor = distanceSensorReadings[0];
  int rightDistanceSensor = distanceSensorReadings[1];
  int backDistanceSensor = distanceSensorReadings[2];
  
  if (frontLineSensor){
      Serial.println("Front line sensor active ... reversing");
      robot.reverse();
      delay(300);
      robot.reverseTurn();
      delay(20);
  } else if (backLineSensor){
      Serial.println("Back line sensor active ... going forward");
      robot.forward();
      delay(300);
      robot.left();
      delay(20);
  } else if (leftDistanceSensor >= DIST_SENSOR_THRESHOLD && rightDistanceSensor >= DIST_SENSOR_THRESHOLD){
      Serial.println("Robot detected ahead ... charging");
      robot.forward();
      delay(10);
  } else if (leftDistanceSensor >= DIST_SENSOR_THRESHOLD){
      Serial.println("Robot detected on left ... sharp left");
      robot.left();
      delay(1);
  } else if (rightDistanceSensor >= DIST_SENSOR_THRESHOLD){
      Serial.println("Robot detected on right ... sharp right");
      robot.right();
      delay(1);
  } else if (backDistanceSensor >= DIST_SENSOR_THRESHOLD){
      robot.sharpRight();
      delay(10);
  } else {
      Serial.println("Cant see the other robot ... searching");
      robot.forward();
      
      if (turboSpeedEnabled){
         delay(100); 
      } else {
        delay(50);
      }
      if (advancedSearchMode){
         robot.left(); 
      }
      robot.stop();
  }

}
