#pragma once
#include "Status.h"
const int IMAGE = 2;

class ImageStastus : public status
{
	string ImageFileName;
public:
	virtual void printContent() const override; //print status content
	ImageStastus() { setIndex(IMAGE); } // ct'or
	ImageStastus(string content, string dataName); // ct'or
	virtual string getDataFileName(); // read data from file ro status
};
