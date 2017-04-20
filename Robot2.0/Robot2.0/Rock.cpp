//Johnny Tran	
//Rock.cpp
//Defines the functions of the rock class
#include "Rock.h"

//Constructor for the rock
Rock::Rock()
{
	x = 0;
	y = 0;
	status = true;
}

//Parameterized constructor for rock
Rock::Rock(int a, int b)
{
	x = a;
	y = b;
	status = true;
}

//copy constructor for rock
Rock::Rock(const Rock& other)
{
	x = other.x;
	y = other.y;
	status = other.status;
}

//sets the x value for the rock
void Rock::setX(int a)
{
	x = a;
}

//sets the y value for the rock
void Rock::setY(int b)
{
	y = b;
}

//sets the stauts of the rock
void Rock::setStatus(bool s)
{
	status = s;
}

//changes the statsu of the rock
void Rock::changeStatus()
{
	status = !status;
}

//shows the x value of a rock
int Rock::showX()
{
	return x;
}

//shows the y value of a rock
int Rock::showY()
{
	return y;
}

//shows the status of a rock
bool Rock::showStatus()
{
	return status;
}

//destructor for a rock
Rock::~Rock()
{
}

