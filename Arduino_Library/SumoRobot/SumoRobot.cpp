#include "SumoRobot.h"
#include "Robot1Config.h"



SumoRobot::SumoRobot(){
	
	m_backDistanceSensorEnabled = false;
	m_backLineSensorEnabled = false;
	m_advancedSearch = false;
	m_turboSpeed = false;
	
	m_distanceSensorReadings = new int[3];
	m_lineSensorReadings = new bool[2];
	
	pinMode(LeftMotor, OUTPUT);
	pinMode(RightMotor, OUTPUT);
	pinMode(LeftDistanceSensor, INPUT);
	pinMode(RightDistanceSensor, INPUT);
	pinMode(BackDistanceSensor, INPUT);
	pinMode(FrontLineSensor, INPUT);
	pinMode(BackLineSensor, INPUT);
}

int SumoRobot::getDistanceReading(int pin){
	int reading = 0;
	for (int i = 0; i < NUM_READINGS; i++){
		reading += analogRead(pin);
		delay(TIME_BETWEEN_READINGS);
	}
	return reading / NUM_READINGS;
}


int* SumoRobot::readDistanceSensors(){
	m_distanceSensorReadings[0] = getDistanceReading(LeftDistanceSensor);
	m_distanceSensorReadings[1] = getDistanceReading(RightDistanceSensor);
	
	if (m_backDistanceSensorEnabled){
		m_distanceSensorReadings[2] = getDistanceReading(BackDistanceSensor);
	} else {
		m_distanceSensorReadings[2] = -1;
	}
	return m_distanceSensorReadings;
}

bool* SumoRobot::readLineSensors(){
	m_lineSensorReadings[0] = !digitalRead(FrontLineSensor);
	
	if (m_backLineSensorEnabled){
		m_lineSensorReadings[1] = !digitalRead(BackLineSensor);
	} else {
		m_lineSensorReadings[1] = false;
	}
	return m_lineSensorReadings;
}



void SumoRobot::setPWM(int leftPWM, int rightPWM){
	analogWrite(LeftMotor, leftPWM);
	analogWrite(RightMotor, rightPWM);
}

void SumoRobot::stop(){
	setPWM(STOP, STOP);
}


void SumoRobot::forward(int n){
	if (m_turboSpeed){
		setPWM(LEFT_FWD, RIGHT_FWD);
		delay(n);	
	} else {
		setPWM(LEFT_FWD, RIGHT_FWD);
		delay(n);	
	}
}

void SumoRobot::reverse(int n){
	if (m_turboSpeed){
		setPWM(LEFT_REVERSE, RIGHT_REVERSE);
		delay(n);
	} else {
		setPWM(LEFT_REVERSE, RIGHT_REVERSE);
		delay(n);	
	}
}

void SumoRobot::left(int n){
	setPWM(STOP, RIGHT_FWD);
	delay(n);
}

void SumoRobot::right(int n){
	setPWM(LEFT_FWD, STOP);
	delay(n);
}

void SumoRobot::sharpLeft(int n){
	for (int i = 0; i < n; i++){
		setPWM(LEFT_REVERSE, RIGHT_FWD);
		delay(10);
		stop();
		delay(20);
	}
}

void SumoRobot::sharpRight(int n){
	setPWM(LEFT_FWD, RIGHT_REVERSE);
	delay(10);
}

void SumoRobot::turnAround(){
	sharpRight(TIME_FOR_COMPLETE_TURN);

}

void SumoRobot::search(){
	if (m_advancedSearch){
		forward(5);
	}
	else {
		forward(5);
	}
}

void SumoRobot::enableBackDistanceSensor(){
	m_backDistanceSensorEnabled = true;
}

void SumoRobot::enableBackLineSensor(){
	m_backLineSensorEnabled = true;
}

void SumoRobot::enableTurboSpeed(){
	m_turboSpeed = true;
}

void SumoRobot::enableAdvancedSearch(){
	m_advancedSearch = true;
}
