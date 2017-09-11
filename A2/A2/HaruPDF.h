/* William Frank
* CS3505
* A2: Classes and Facades
*/

#ifndef HARU_H
#define HARU_H

#include "hpdf.h"
#include <string>

class HaruPDF
{
private:
	HPDF_Doc  pdf;
	HPDF_Page page;
	char fname[256];
	HPDF_Font font;
public:
	//creates a pdf fileName.pdf
	HaruPDF(std::string);

	//writes the next character
	void writeText(char letter, float a, float b, float c, float d, float x, float y);

	void save();

	void saveAndFinish();

};

#endif