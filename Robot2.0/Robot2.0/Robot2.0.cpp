//Johnny Tran
//Robot2.0.cpp
//This program uses a robot class from a previous program and creates two
//subclasses that uses the properties of inheritence. The two subclasses
//are a rock robot and a temp robot. The rock robot can calculate the 
//distance to a rock, find the closest rock and pick it up. The Temp
//robot can move to a random location and take a temperature.

#include<iostream>
#include<fstream>
#include"Robot.h"
#include"Rock.h"
#include"RockList.h"
#include"RockRobot.h"
#include"TempRobot.h"
#include<string>
#include<iomanip>
using namespace std;

//displays a introduction message for the user
void introMessage(RockRobot &, TempRobot &,int &, int&);

//opens files named by the user
void openFiles(ifstream&);

int main()
{
	RockRobot robot1;
	TempRobot robot2;
	Rock rock;
	int numRocks, numTemps, counter = 0;
	int x = 0, y = 0;
	double totalDist = 0, tempDist = 0;
	RockList rockList;
	ifstream infile;
	ofstream outfile;

	srand(time(NULL));
	introMessage(robot1, robot2, numRocks, numTemps);
	openFiles(infile);
	rockList.readRocks(rockList, infile);

	cout << "Rock Robot data: " << endl;
	cout << "Position" << setw(25) << "Distance(in miles)" << endl;
	cout << "(  " << robot1.showX() << " ,    " << robot2.showY() << ")";
	cout << setw(15) << "0.00" << endl;
	cout << fixed << setprecision(2);

	robot1.changeStatus();
	while (numRocks > 0)
	{
		robot1.findClosestRock(rockList, robot1, counter);
		rockList.showRock(counter, rock);
		cout << "(" << setw(3) << rock.showX() << " , " << setw(4);
		cout << rock.showY() << ")" << setw(15);
		cout << robot1.calculateDistance(robot1.showX(), robot1.showY(), rock);
		cout << endl;
		tempDist =robot1.calculateDistance(robot1.showX(),robot1.showY(),rock);
		totalDist = totalDist + tempDist;
		robot1.setTotalDist(totalDist);
		robot1.pickupRock();
		robot1.setX(rock.showX());
		robot1.setY(rock.showY());
		rockList.changeRock(counter);
		numRocks--;
	}
	robot1.turnLeft();
	cout << "Direction: " << robot1.showDirection() << endl;
	cout << "Total Distance: "<< robot1.showTotalDist() << " miles" << endl;
	cout << "Number of Rock Collected: " << robot1.showNumRocks();
	cout << endl << endl;
	robot1.changeStatus();

	cout << "Temperature Robot data: " << endl;
	cout << "Position" << setw(30) << "Temperature(in Celcius)" << endl;
	cout << "(  " << robot2.showX() << " ,    " << robot2.showY() << ")";
	cout << setw(15) << "  " << endl;

	robot2.changeStatus();
	while (numTemps > 0)
	{
		robot2.move();
		robot2.takeTemp();
		cout << "(" << setw(3) << robot2.showX() << " , " << setw(4);
		cout << robot2.showY() << ")"<< setw(15) << robot2.showTemp() << endl;
		numTemps--;
	}
	robot2.turnRight();
	cout << "Direction: " << robot2.showDirection() << endl;
	cout << "Number of Temperatures recorded: " << robot2.showNumTemp()<<endl;
	robot2.changeStatus();

	system("pause");
	return 0;
}

//Displays an intro message and prompts the user for information
void introMessage(RockRobot &r, TempRobot &t, int &numRocks, int &numTemp)
{
	char answer;
	int a = 0, b = 0;
	cout << "Welcome to the updated NASA2 robot program." << endl;
	cout << "Do you want to use the default position for the rock robot or ";
	cout << "manually enter theinital position for the robot?(y/n): ";
	cin >> answer;
	if (answer == 'y')
	{
		cout << "Please enter the x coordinate for the robot: ";
		cin >> a;
		cout << endl << "Please enter the y coordinate for the robot: ";
		cin >> b;
		cout << endl;
	}
	r.setX(a);
	r.setY(b);
	cout << "Please enter the number of rocks you want to pick up: ";
	cin >> numRocks;
	cout << endl;

	cout << "Do you want to use the default position for the Temperature ";
	cout << "robot or" << endl;
	cout << "manually enter the inital position for the robot?(y/n): ";
	cin >> answer;
	if (answer == 'y')
	{
		cout << "Please enter the x coordinate for the robot: ";
		cin >> a;
		cout << endl << "Please enter the y coordinate for the robot: ";
		cin >> b;
		cout << endl;
	}
	t.setX(a);
	t.setY(b);
	cout << "Please enter the number of temperatures you want to get: ";
	cin >> numTemp;
	cout << endl;
}

//Opens files that are named by the user
void openFiles(ifstream& infile)
{
	string inFileName;

	cout << "Enter the input file name: ";
	cin >> inFileName;
	infile.open(inFileName);
}
