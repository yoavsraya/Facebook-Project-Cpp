#include "ImageStatus.h"

ImageStastus::ImageStastus(string content, string dataName)
{
	setIndex(IMAGE);
	setName(content);
	ImageFileName = "start ";
	ImageFileName += dataName += ".jpg";
	setTime();
}

string ImageStastus::getDataFileName()
{
	return ImageFileName;
}

void ImageStastus::printContent() const
{
	cout << getContent() << endl;
	cout << "upload time and date: " << getTime() << endl;
	system(ImageFileName.c_str());
	cout << "------------------------------" << endl;
}
