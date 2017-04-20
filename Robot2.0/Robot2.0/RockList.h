//Johnny Tran
//RockList.h
//.h file for RockList class. A rock list is an dynamic array of rocks

#include "Rock.h"
#include<fstream>
using namespace std;
#pragma once

//This constant is for the max size of the RockList
const int MAXSIZE = 100;

class RockList
{
public:
	//Constructor for RockList
	RockList();

	//Checks to see if the list is full
	bool isFull();

	//Checks to see if the list is empty
	bool isEmpty();

	//Places the value of the rock at the position into another rock
	void showRock(int counter, Rock&);

	//changes the values of a rock
	void changeRock(int);

	//adds a rock to the list
	void addRock(Rock &rock);

	//shows the length of the list
	int provideLength();

	//Retrieves all the rocks in the list
	Rock removeRock();

	//Reads in rock values from a file
	void readRocks(RockList &r, ifstream &);

	//Destructor for RockList
	~RockList();
private:
	Rock * rockList;
	int counter, size, length;
};

