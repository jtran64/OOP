//Johnny Tran
//TempRobot.h
//.h file for TempRobot.A temp robot can move to a random location
// and take a temperature

#include"Robot.h"
#pragma once

class TempRobot:public Robot
{
	int temperature, numTemp;
public:
	//Constructor for TempRobot
	TempRobot();

	//paramaterized constructor for tempRobot
	TempRobot(int t, int n);
	
	//copy constructor for TEmpRobot
	TempRobot(const TempRobot& other);

	//Takes a random temperature between two values
	void takeTemp();


	//shows the temperature
	int showTemp();

	//shows the number of temperatures it has recorded
	int showNumTemp();

	//moves to a random x and y location
	virtual void move();

	~TempRobot();
};
