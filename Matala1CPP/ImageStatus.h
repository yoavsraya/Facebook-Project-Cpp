#pragma once
#include "Status.h"
const int IMAGE = 2;

class ImageStastus : public status
{
	string ImageFileName = "start ";
public:
	virtual void printContent() const override;
	ImageStastus() { setIndex(IMAGE); }
	ImageStastus(string content, string dataName);
	virtual string getDataFileName();
};
