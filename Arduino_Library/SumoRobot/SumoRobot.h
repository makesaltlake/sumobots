#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include "Arduino.h"

#define NUM_READINGS 3
#define TIME_BETWEEN_READINGS 2
#define TIME_FOR_COMPLETE_TURN 1

class SumoRobot{
	
	private:
		bool m_backDistanceSensorEnabled;
		bool m_backLineSensorEnabled;
		int* m_distanceSensorReadings;
		bool* m_lineSensorReadings;
		bool m_advancedSearch;
		bool m_turboSpeed;
		int getDistanceReading(int reading);
		void setPWM(int leftPWM, int rightPWM);
		
	public:
		SumoRobot();
		void stop();
		void forward();
		void reverse();
		void left();
		void right();
		void sharpLeft();
		void sharpRight();	
		void search();
		void turnAround();	
		int* readDistanceSensors();
		bool* readLineSensors();
		void enableBackDistanceSensor();
		void enableBackLineSensor();
		void enableTurboSpeed();
		void enableAdvancedSearch();
		void reverseTurn();
};

#endif
