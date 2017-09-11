/* William Frank
* CS3505
* A2: Classes and Facades
*/

#define _USE_MATH_DEFINES

#include <math.h>
#include <iostream>
#include <cmath>
#include "Spiral.h"

using namespace std;

//double x_;
//double y_;
double centerX_;
double centerY_;
double radius_;
double angle_;

Spiral::Spiral(double centerX, double centerY, double radius, double angle)
{
	angle_ = angle + 90;
	//x_ = centerX + radius;
	//y_ = centerY + radius;
	centerX_ = centerX;
	centerY_ = centerY;
	radius_ = radius;
}

double Spiral::getTextX()
{
	double rad = angle_ / 180 * M_PI;
	double x = centerX_ + (radius_ * cos(rad));
	return x;
}

double Spiral::getTextY()
{
	double rad = angle_ / 180 * M_PI;
	double y = centerY_ + (radius_ * sin(rad));
	return y;
}

double Spiral::getSpiralAngle()
{
	return angle_;
}

double Spiral::getTextAngle()
{
	return angle_ + 90;
}

//prefix
Spiral& Spiral::operator++()
{
	radius_ += .1;
	angle_ -= 5;
}

//postfix
Spiral Spiral::operator++(int n)
{
	Spiral temp = *this;
	++*this;
	return temp;
}

ostream& operator<<(ostream& output, Spiral s)
{
	output << "Radius: " << radius_ << "\nAngle: " << angle_;
	return output;
}