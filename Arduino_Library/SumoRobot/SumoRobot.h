#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include "Arduino.h"


#define TIME_FOR_COMPLETE_TURN 1

class SumoRobot{
	
	private:
		bool m_backDistanceSensorEnabled;
		bool m_backLineSensorEnabled;
		int* m_distanceSensorReadings;
		bool* m_lineSensorReadings;
		int getDistanceReading(int reading);
		void setPWM(int leftPWM, int rightPWM);
		int m_frontLineSensorBlackVal;
		int m_backLineSensorBlackVal;
	public:
		SumoRobot();
		void stop();
		void forward();
		void reverse();
		void left();
		void right();
		void sharpLeft();
		void sharpRight();	
		int* readDistanceSensors();
		bool* readLineSensors();
		void enableBackDistanceSensor();
		void enableBackLineSensor();
		void reverseTurn();
};

#endif
