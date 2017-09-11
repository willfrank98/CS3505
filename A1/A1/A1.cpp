//William Frank
//A1: C++ Starter
//Simulates a population of foxes and rabbits

#include "stdafx.h"
#include <iostream>

using namespace std;

//Calculates the updated population numbers after one iteration
//See line 39 for variable definitions
void updatePopulations(double g, double p, double c, double m, double K, double& numRabbits, double& numFoxes);

//sends a character preceded by spaces number of space characters to cout
void plotCharacter(int spaces, char character);

//Helper function to plot the number of foxes and rabbits in the population
void chartingFunction(double numRabbits, double numFoxes, double scaleFactor);

//increments an integer through pointers
void incrementCounter(int* counter);

int main()
{
	double numRabbits, numFoxes;

	cout << "Please enter an initial rabbit population: ";
	if (!(cin >> numRabbits))
	{
		cout << "Invalid input" << endl;
	}

	cout << "Please enter an initial fox population: ";
	if (!(cin >> numFoxes))
	{
		cout << "Invalid input" << endl;
	}

	double g = 0.2;		//rabbitGrowth
	double p = 0.002;	//predationRate
	double c = 0.6;		//foxPreyConversion
	double m = 0.2;		//foxMortalityRate
	double K = 1000.0;	//carryCapacity
	double scaleFactor = .1;


	int counter = 15;
	while (counter < 500)
	{
		updatePopulations(g, p, c, m, K, numRabbits, numFoxes);

		chartingFunction(numRabbits, numFoxes, scaleFactor);

		if (numRabbits < 1 || numFoxes < 1)
		{
			//end simulation
			return 0;
		}

		incrementCounter(&counter);
	}

	//allows the user to control termination of the program
	char temp;	
	cin >> temp;

    return 0;
}

void updatePopulations(double g, double p, double c, double m, double K, double& numRabbits, double& numFoxes)
{
	double deltaRabbit = ((g * numRabbits) * (1 - (numRabbits / K))) - (p * numRabbits * numFoxes);
	double deltaFoxes = (c * p * numRabbits * numFoxes) - (m * numFoxes);

	numRabbits += deltaRabbit;
	numFoxes += deltaFoxes;
}

void plotCharacter(int spaces, char character)
{
	//string whiteSpace = "";

	for (int i = 0; i < spaces; i++)
	{
		//TODO: change '-' to ' '
		cout << ' ';
	}

	cout << character;
}

void chartingFunction(double numRabbits, double numFoxes, double scaleFactor)
{
	//cast to ints
	int adjustedFoxes = numFoxes * scaleFactor;
	int adjustedRabbits = numRabbits * scaleFactor;

	if (adjustedFoxes == adjustedRabbits)
	{
		plotCharacter(adjustedFoxes, '*');
		cout << endl;
	}
	else if (adjustedFoxes > adjustedRabbits)
	{
		plotCharacter(adjustedRabbits, 'r');
		plotCharacter((adjustedFoxes - adjustedRabbits), 'F');
		cout << endl;
	}
	else
	{
		plotCharacter(adjustedFoxes, 'F');
		plotCharacter((adjustedRabbits - adjustedFoxes), 'r');
		cout << endl;
	}
}

void incrementCounter(int* counter)
{
	(*counter)++;
}
