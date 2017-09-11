/* William Frank
* CS3505
* A2: Classes and Facades
*/

#ifndef SPIRAL_H
#define SPIRAL_H


#include <iostream>

class Spiral
{
private:
	double centerX_;
	double centerY_;
	double radius_;
	double angle_;
public:
	Spiral(double centerX, double centerY, double radius, double angle);

	//prefix
	Spiral& operator++();

	//postfix
	Spiral operator++(int);

	//ostream
	friend std::ostream& operator<<(std::ostream& output, Spiral s);

	double getTextX();

	double getTextY();

	double getSpiralAngle();

	double getTextAngle();
};

#endif