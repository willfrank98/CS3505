// A1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

using namespace std;

//Calculates the updated population numbers after one iteration
void updatePopulations(double g, double p, double c, double m, double K, double& numRabbits, double& numFoxes);

//
void plotCharacter(int spaces, char character);
void chartingFunction(double numRabbits, double numFoxes, double scaleFactor);
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


	for (int i = 0; i < 500; i++)
	{
		updatePopulations(g, p, c, m, K, numRabbits, numFoxes);

		if (numRabbits < 1 || numFoxes < 1)
		{
			//end simulation
		}
	}


    return 0;
}

/**
	
*/
void updatePopulations(double g, double p, double c, double m, double K, double& numRabbits, double& numFoxes)
{
	double deltaRabbit = ((g * numRabbits) * (1 - (numRabbits / K))) - (p * numRabbits * numFoxes);
	double deltaFoxes = (c * p * numRabbits * numFoxes) - (m * numFoxes);

	numRabbits += deltaRabbit;
	numFoxes += deltaFoxes;
}

void plotCharacter(int spaces, char character)
{
	string whiteSpace = "";

	for (int i = 0; i < spaces; i++)
	{
		whiteSpace += " ";
	}

	whiteSpace += character;

	cout << whiteSpace << endl;
}

void chartingFunction(double numRabbits, double numFoxes, double scaleFactor)
{
	//cast to ints
	int adjustedFoxes = numFoxes * scaleFactor;
	int adjustedRabbits = numRabbits * scaleFactor;

	if (adjustedFoxes == adjustedRabbits)
	{
		
	}
}

void incrementCounter(int* counter)
{
	counter++;
}
