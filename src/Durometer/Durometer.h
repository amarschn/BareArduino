#ifndef Durometer_h
#define Durometer_h

#include <Arduino.h>
#include "AccelStepper.h"

//Pins
int m1DirPin = 6;
int m1StepPin = 5;
int upButtonPin = 10;
int DownButtonPin = 11;
int eStopPin = 2;

//Debug (change to stop printing to the serial port)
#define PRINT_SERIAL 1

//Constants relating to movement
int maxSpeed = 3200;
int motorSpeed = 3200;
int motorAccel = 10000;
int revolutions = 10;
int stepsPerR = 3200;
int debounceTime = 500;
long goalPos = revolutions*stepsPerR*-1;
long lastPress = millis();

AccelStepper stepper1(1,m1StepPin, m1DirPin);

void moveSTOP(){
	if (millis() - lastPress > debounceTime)
	{
		lastPress = millis();
		stepper1.stop();
		stepper1.setCurrentPosition(0);
		if(PRINT_SERIAL)
			Serial.println("E STOP");
	}
}

/*
void moveUp(){
	if (millis()-lastPress > debounceTime)
	{
	lastpress = millis();
	stepperGoal = 32000;
	stepper1.moveTo(stepperGoal);
	stepper1.setSpeed(motorSpeed);
	Serial.println("moveup");
	}
}

void moveDown(){
	if (millis()-lastPress > debounceTime)
	{
	lastpress = millis();
	stepperGoal = -32000;
	stepper1.moveTo(stepperGoal);
	stepper1.setSpeed(motorSpeed);
	Serial.println("movedown");
	}
}
*/

#endif
