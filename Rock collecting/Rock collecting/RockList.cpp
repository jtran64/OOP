//Johnny Tran
//RockList.cpp
//Defines the RockList functions
#include "RockList.h"

//Constructor that creates an empty dynamic list
RockList::RockList()
{
	size = MAXSIZE;
	rockList = new Rock[size];
	counter = -1;
	length = 0;
}

//checks if the list is full
bool RockList::isFull()
{
	return(counter == size-1);
}

//checks if the list is empty
bool RockList::isEmpty()
{
	return(counter == -1);
}

//Gets the values of a specific rock in the list and copies it to another rock
void RockList::showRock(int count, Rock &r)
{
	r.setX(rockList[count].showX());
	r.setY(rockList[count].showY());
	r.setStatus(rockList[count].showStatus());
}

//Changes the status of the rock
void RockList::changeRock(int count)
{
	rockList[count].changeStatus();

}

//adds a rock to the list
void RockList::addRock(Rock &rock)
{
	if (!isFull())
	{
		counter++;
		length++;
		rockList[counter].setX(rock.showX());
		rockList[counter].setY(rock.showY());
	}
}

//gives the length of the list
int RockList::provideLength()
{
	return length;
}

//Destructor for RockList
RockList::~RockList()
{
	delete[] rockList;
}
