//Johnny Tran
//RockRobot.h
//.h file for RockRobot.A RockRobot can find the distance to a rock, find the 
//closest rock, and pick up that rock.

#include"Robot.h"
#include"RockList.h"
#pragma once

class RockRobot:public Robot
{
	int numRocks;
public:
	//Constructor for RockRobot
	RockRobot();

	//Paramaterized constructor for RockRobot
	RockRobot(int n);

	//Copy constructor for RockRobot
	RockRobot(const RockRobot& other);

	//Finds the closest rock using the calculate Distance function
	void findClosestRock(RockList &l, RockRobot r, int&);

	//Finds the distance between the Rock Robot and a rock
	double calculateDistance(int x, int y, Rock r);

	//adds 1 to its current number of rocks
	void pickupRock();

	//retrieves the number of rocks
	int showNumRocks();

	~RockRobot();
};
