// A1.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

void updatePopulations(double g, double p, double c, double m, double K, double& numRabbits, double& numFoxes);
void plotCharacter(int spaces, char character);
void chartingFunction(/*implement*/);

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


    return 0;
}

void updatePopulations(double g, double p, double c, double m, double K, double& numRabbits, double& numFoxes)
{

}

void plotCharacter(int spaces, char character)
{
}

void chartingFunction()
{
}
