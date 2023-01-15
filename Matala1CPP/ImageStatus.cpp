#include "ImageStatus.h"

void ImageStastus::printImageStatus() const
{
	printContent();
	const char* fileName = ImageFileName.c_str();
	system(fileName);
	cout << endl;
}
