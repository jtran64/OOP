//Johnny Tran
//RockRobot.cpp
//Defines the RockRobot functions

#include "RockRobot.h"

//constructor for rock robot
RockRobot::RockRobot()
{
	numRocks = 0;
}

//Paramaterized constructor for Rock Robot
RockRobot::RockRobot(int n)
{
	numRocks = n;
}

//copy constructor for Rock Robot
RockRobot::RockRobot(const RockRobot& other)
{
	numRocks = other.numRocks;
}

//finds the closest rock using two loops
void RockRobot::findClosestRock(RockList &l, RockRobot r, int& count1)
{
	double minDist = 0, dist;
	int count = 0;
	Rock tempRock, closestRock;

	//This loop will find the first rock that has not been picked up
	//and set it as the minimum
	do
	{
		l.showRock(count, tempRock);
		if (tempRock.showStatus() == true)
		{
			minDist = calculateDistance(r.showX(), r.showY(), tempRock);
			closestRock.setX(tempRock.showX());
			closestRock.setY(tempRock.showY());
			count1 = count;
		}
		count++;
	} while (minDist <= 0);

	//This loop will go through the entire list and find the closest
	//Rock
	while (count < l.provideLength())
	{
		l.showRock(count, tempRock);
		if (tempRock.showStatus() == true)
		{
			dist = calculateDistance(r.showX(), r.showY(), tempRock);
			if (dist < minDist)
			{
				minDist = dist;
				closestRock.setX(tempRock.showX());
				closestRock.setY(tempRock.showY());
				count1 = count;
			}
		}
		count++;
	}
}

//calculates the distance between the robot and a rock
double RockRobot::calculateDistance(int a, int b, Rock r)
{
	double d;
	int x, y;
	x = (r.showX() - a);
	x = abs(x);
	y = (r.showY() - b);
	y = abs(y);
	d = sqrt((x*x) + (y*y));
	return d;
}

//adds 1 to current number of rocks
void RockRobot::pickupRock()
{
	numRocks = numRocks + 1;
}

//shows number of rocks
int RockRobot::showNumRocks()
{
	return numRocks;
}

RockRobot::~RockRobot()
{
}
