//Johnny Tran	
//Robot.h
//.h file for Robot.A robot has an x and y coordinate, a status, a direction
//and total distance travelled

#include<string>
using namespace std;
#pragma once
class Robot
{
	bool status;
	int x, y, amount;
	string direction;
	double totalDist;
public:
	//Constructor for Robot
	Robot();

	//Paramaterized constructor for Robot
	Robot(int, int, int, string);

	//Copy constuctor for robot
	Robot(const Robot & other);

	//Sets status to true or false
	void setStatus(bool s);

	//Sets a vlue for x
	void setX(int b);

	//Sets a value for y
	void setY(int c);

	//Sets a value for direction
	void setDirection(string d);

	void setTotalDist(double t);

	//Changes the status
	void changeStatus();

	//Retrieves the status
	bool showStatus();

	//Retrieves the value from x
	int showX();

	//Retrieves the value from y
	int showY();

	//Retrieves the value from amount
	int showAmount();

	//Retrieves the direction
	string showDirection();

	//Retrieves the total distance
	double showTotalDist();

	//moves the robot to a location
	void move();

	//turns the robot to the left  of its current position
	void turnLeft();

	//turns the robot right of its current position
	void turnRight();

	//Destructor for Robot
	~Robot();
};

