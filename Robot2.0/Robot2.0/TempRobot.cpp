//Johnny Tran
//TempRobot.cpp
//Defines the TempRobot funcitons

#include "TempRobot.h"
#include<random>
#include<ctime>

//constructor for Temp robot
TempRobot::TempRobot()
{
	temperature = 0, numTemp = 0;
}

//paramaterized constructor for TempRobot
TempRobot::TempRobot(int t, int n)
{
	temperature = t;
	numTemp = n;
}

//Copy constructor for TempRobot
TempRobot::TempRobot(const TempRobot& other)
{
	temperature = other.temperature;
	numTemp = other.numTemp;
}

//takes a random temperature between -140 and 20
void TempRobot::takeTemp()
{
	numTemp++;
	temperature = rand() % 161 + (-140);
}

//show the temperature
int TempRobot::showTemp()
{
	return temperature;
}

//shows number of temperatures taken
int TempRobot::showNumTemp()
{
	return numTemp;
}

//moves the robot to a random x and y value
void TempRobot::move()
{
	setX(rand() % 101);
	setY(rand() % 101);
}

TempRobot::~TempRobot()
{
}
