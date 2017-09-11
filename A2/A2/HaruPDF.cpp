/* William Frank
* CS3505
* A2: Classes and Facades
*/

#include "HaruPDF.h"	
#include <string>

using namespace std;


HPDF_Doc  pdf;
HPDF_Page page;
HPDF_Font font;

char fname[256];

HaruPDF::HaruPDF(string fileName)
{
	strcpy(fname, fileName.c_str);
	strcat(fname, ".pdf");

	pdf = HPDF_New(NULL, NULL);
	/* add a new page object. */
	page = HPDF_AddPage(pdf);
	HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
	//    print_grid  (pdf, page);
	font = HPDF_GetFont(pdf, "Helvetica", NULL);
	HPDF_Page_SetTextLeading(page, 20);
	HPDF_Page_SetGrayStroke(page, 0);
}

void HaruPDF::writeText(char letter, float a, float b, float c, float d, float x, float y)
{
	HPDF_Page_SetTextMatrix(page, a, b, c, d, x, y);

	char buf[2];
	buf[0] = letter; // The character to display
	buf[1] = 0;
	HPDF_Page_ShowText(page, buf);
}

void HaruPDF::save()
{
	HPDF_SaveToFile(pdf, fname);
}

void HaruPDF::saveAndFinish()
{
	HPDF_Page_EndText(page);

	HPDF_SaveToFile(pdf, fname);

	HPDF_Free(pdf);
}