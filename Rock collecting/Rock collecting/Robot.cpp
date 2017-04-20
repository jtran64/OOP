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
	direction = 'n';
	amount = 0;
}
//Parmeterized constructor for robot
Robot::Robot( int b, int c, int a, char d)
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

//Picks up a rock and adds one to the amount the robot has
void Robot::pickupRock(int a)
{
	amount = amount + 1;
}

//Sets the direction of the robot
void Robot::setDirection(char d)
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
char Robot::showDirection()
{
	return direction;
}

//destructor of the robot
Robot::~Robot()
{
}
