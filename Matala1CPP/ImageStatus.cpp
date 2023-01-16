#include "ImageStatus.h"

void ImageStastus::printImageStatus() const
{
	printContent();
	const char* fileName = ImageFileName.c_str();
	system(fileName);
	cout << endl;
}

ImageStastus::ImageStastus(string content, string dataName)
{
	setIndex(IMAGE);
	setName(content);
	ImageFileName = dataName;
}

string ImageStastus::getDataFileName()
{
	return ImageFileName;
}


