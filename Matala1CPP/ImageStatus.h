#pragma once
#include "Status.h"
const int IMAGE = 2;

class ImageStastus : public status
{
	string ImageFileName = "start ";
public:
	void printImageStatus()const;
	ImageStastus() { setIndex(IMAGE); }
	ImageStastus(string content, string dataName);
	virtual string getDataFileName();
};
