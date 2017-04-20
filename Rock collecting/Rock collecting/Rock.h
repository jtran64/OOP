//Johnny Tran
//Rock.h
//.h file for the rock class

#pragma once
class Rock
{
	int x, y;
	bool status;
public:
	//Constructor for Rock
	Rock();
	//Parameterized constructor for rock
	Rock(int a, int b);
	//copy constuctor for rock
	Rock(const Rock& other);
	//Sets a value for x
	void setX(int a);
	//Sets a value for y
	void setY(int b);
	//sets the stauts of the rock
	void setStatus(bool);
	void changeStatus();
	//retrieves the information from x
	int showX();
	//Retrieves the information from y
	int showY();
	//Retrieves the information from status
	bool showStatus();
	//Destructor for Rock
	~Rock();
};

