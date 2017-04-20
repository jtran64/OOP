//Johnny Tran
//RockCollecting.cpp
//This program reads coordinates from an input file and gives those
//coordinates to rocks and places them into a list. Then a robot will 
//find the closest rock and pick it up. Finally, the program will
//print out all of the information.

#include "Robot.h"
#include "Rock.h"
#include "RockList.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

//displays a introduction message for the user
void introMessage(int &, int &, int&, ifstream&, ofstream&);
//opens files named by the user
void openFiles(ifstream&, ofstream&);
//reads rock positions from a file and puts them into a list
void readRocks(RockList &, ifstream&);
//Finds distance between a rock and the robot
double calculateDistance(Rock&, int , int);
//finds the closest rock
void closestRock(RockList&, int&, int&, Rock&, int &);
//prints the list of rocks
void printList(RockList &, int, int, int, ofstream&);

int main()
{
	Robot robot;
	Rock rock1;
	int counter1 = 0, amount, amount2;
	int robotX = 0, robotY = 0, initialX, initialY;
	RockList rocklist, rocklist2;
	ofstream outfile;
	ifstream infile;
	
	introMessage(robotX, robotY, amount,infile, outfile);
	amount2 = amount;
	initialX = robotX;
	initialY = robotY;
	readRocks(rocklist,infile);
	robot.changeStatus();
	while (amount > 0)
	{
		closestRock(rocklist, robotX, robotY, rock1, counter1);
		rocklist2.addRock(rock1);
		robotX = rock1.showX();
		robotY = rock1.showY();
		rocklist.changeRock(counter1);
		amount--;
	}
	robot.changeStatus();
	printList(rocklist2, initialX, initialY,amount2,outfile);
	
	system("pause");
	return 0;
}

//Reads in the x and y position from an input file gives it to a rock
//and places it into a list
void readRocks(RockList &l,ifstream& infile)
{
	int x, y;
	while (infile >> x >> y)
	{
		Rock rock(x, y);
		l.addRock(rock);
	}
}

//Finds the closest rock and passes a index by reference
void closestRock(RockList &l, int &x, int &y, Rock& r, int &count1)
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
			minDist = calculateDistance(tempRock, x, y);
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
			dist = calculateDistance(tempRock, x, y);
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
	r.setX(closestRock.showX());
	r.setY(closestRock.showY());
}

//This function calculates the distance between a rock and the robots 
//coordinates
double calculateDistance(Rock & r1, int a, int b)
{
	double d;
	int x, y;
	x = (r1.showX() - a);
	x = abs(x);
	y = (r1.showY() - b);
	y = abs(y);
	d = sqrt((x*x) + (y*y));
	return d;
}

//Displays an intro message and prompts the user for information
void introMessage(int &a, int &b, int &num,ifstream& infile,ofstream& outfile)
{
	char answer;
	cout << "Welcome to the NASA2 rock collecting program." << endl;
	openFiles(infile, outfile);
	cout << "Do you want to use the default position for the robot or ";
	cout << "manually enter the" << endl;
	cout << "inital position for the robot?(y/n): ";
	cin >> answer;
	if (answer == 'y')
	{
		cout << "Please enter the x coordinate for the robot: ";
		cin >> a;
		cout << endl << "Please enter the y coordinate for the robot: ";
		cin >> b;
		cout << endl;
	}
	cout << "Please enter the number of rocks you want to pick up: ";
	cin >> num;
}

//Opens files that are named by the user
void openFiles(ifstream& infile, ofstream& outfile)
{
	string inFileName;
	string outFileName;

	cout << "Enter the input file name: ";
	cin >> inFileName;
	infile.open(inFileName);  

	cout << "Enter the output file name: ";
	cin >> outFileName;
	outfile.open(outFileName);
}

//Prints a list of rocks and calculates the distances traveled by the robot
//and finds the total distance
void printList(RockList &l, int x, int y, int a, ofstream& outfile)
{
	int count = 0;
	double totalDist = 0;
	Rock tempRock;
	cout << "Number of Rocks Collected: " << a << endl << endl;
	cout << "Position" << setw(25) << "Distance(in miles)" << endl;
	cout << "(  " << x << "  ,   " << y << ")" << setw(14) << "0.00" << endl;
	cout << fixed << setprecision(2);
	outfile << "Number of Rocks Collected: " << a << endl << endl;
	outfile << "Position" << setw(25) << "Distance(in miles)" << endl;
	outfile << "(  " << x << "  ,  " << y << ")" << setw(14) << "0.00";
	outfile << endl;
	outfile << fixed << setprecision(2);
	while (count < l.provideLength())
	{
		l.showRock(count, tempRock);
		cout << "(" << right << setw(3) << tempRock.showX() << setw(3) << ",";
		cout << right << setw(4) << tempRock.showY() << ")";
		cout << setw(14);
		cout << calculateDistance(tempRock, x, y) << endl;
		outfile << "(" << right << setw(3) << tempRock.showX() << setw(2);
		outfile << "," << right << setw(4) << tempRock.showY() << ")";
		outfile << setw(14);
		outfile << calculateDistance(tempRock, x, y) << endl;
		totalDist = totalDist + calculateDistance(tempRock, x, y);
		x = tempRock.showX();
		y = tempRock.showY();
		count++;
	}
	cout << "Total Distance: " << totalDist << endl;
	outfile << "Total Distance: " << totalDist << " Miles" << endl;
}

