/* William Frank
* CS3505
* A2: Classes and Facades
*/

#include "HaruPDF.h"
#include "Spiral.h"
#include <string.h>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char **argv)
{
	if (!(strlen(argv[1]) > 0))
	{
		cout << "invalid input text";
		return 0;
	}

	HaruPDF pdf(argv[0]);

	Spiral s(0, 0, 10, 0);

	for (int i = 0; i < strlen(argv[1]); i++)
	{
		float x = s.getTextX();
		float y = s.getTextY();
		float rad1 = s.getSpiralAngle();
		//float rad2 = s.getTextAngle();

		pdf.writeText(argv[1][i], cos(rad1), sin(rad1), -sin(rad1), cos(rad1), x, y);

		s++;
	}


}