#include "ImageStatus.h"

ImageStastus::ImageStastus(string content, string dataName)
{
	int i = 0;
	setIndex(IMAGE);
	setName(content);
	ImageFileName.erase();
	ImageFileName += dataName;
	setTime();
}

string ImageStastus::getDataFileName()
{
	return ImageFileName;
}

void ImageStastus::printContent() const
{
	cout << "\033[1;33m";
	cout << getContent() << endl;
	cout << "upload time and date: " << getTime() << endl;
	system(ImageFileName.c_str());
	cout << "------------------------------" << endl;
	cout << "\033[0m";
}
