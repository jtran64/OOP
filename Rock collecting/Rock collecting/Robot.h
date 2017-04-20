//Johnny Tran	
//Robot.h
//.h file for Robot

#pragma once
class Robot
{
	bool status;
	int x, y, amount;
	char direction;
public:
	//Constructor for Robot
	Robot();
	//Paramaterized constructor for Robot
	Robot(int, int, int, char);
	//Copy constuctor for robot
	Robot(const Robot & other);
	//Sets status to true or false
	void setStatus(bool s);
	//Sets a vlue for x
	void setX(int b);
	//Sets a value for y
	void setY(int c);
	//Sets a value for amount
	void pickupRock(int a);
	//Sets a value for direction
	void setDirection(char d);
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
	char showDirection();
	//Destructor for Robot
	~Robot();
};

