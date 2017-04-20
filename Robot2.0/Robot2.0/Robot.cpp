//Johnny Tran
//Robot.cpp
//Defines the functions of the Robot class

#include "Robot.h"

//Constructor for the robot
Robot::Robot()
{
	x = 0;
	y = 0;
	status = true;
	direction = "north";
	amount = 0;
}
//Parmeterized constructor for robot
Robot::Robot(int b, int c, int a, string d)
{
	x = b;
	y = c;
	direction = d;
	amount = a;
}

//copy constructor for Robot
Robot::Robot(const Robot& other)
{
	x = other.x;
	y = other.y;
	direction = other.direction;
	amount = other.amount;
}

//sets the status of the robot
void Robot::setStatus(bool s)
{
	status = s;
}

//Sets the x coordinate of the robot
void Robot::setX(int b)
{
	x = b;
}

//Sets the y coordinate of the robot
void Robot::setY(int a)
{
	y = a;
}

//Sets the direction of the robot
void Robot::setDirection(string d)
{
	direction = d;
}

//changes the status of the robot
void Robot::changeStatus()
{
	status = !status;
}

//shows the status of the robot
bool Robot::showStatus()
{
	return status;
}

//shows the x coordinate of the robot
int Robot::showX()
{
	return x;
}

//shows the y coordinate of the robot
int Robot::showY()
{
	return y;
}

//Shows the amount of rocks the robot has
int Robot::showAmount()
{
	return amount;
}

//Shows the direction of the robot
string Robot::showDirection()
{
	return direction;
}

//sets the total distance
void Robot::setTotalDist(double t)
{
	totalDist = t;
}

//shows total distance
double Robot::showTotalDist()
{
	return totalDist;
}

//turns the robot left
void Robot::turnLeft()
{
	if (showDirection() == "north")
		setDirection("west");
	else if (showDirection() == "west")
		setDirection("south");
	else if (showDirection() == "south")
		setDirection("east");
	else
		setDirection("north");
}

//turns the robot right
void Robot::turnRight()
{
	if (showDirection() == "north")
		setDirection("east");
	else if (showDirection() == "east")
		setDirection("south");
	else if (showDirection() == "south")
		setDirection("west");
	else
		setDirection("north");
}

//destructor of the robot
Robot::~Robot()
{
}
