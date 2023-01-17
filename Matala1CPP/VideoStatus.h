#pragma once

#include "Status.h"
const int VIDEO = 1;

class  VideoStatus: public status
{
	string VideoFileName;
public:
	virtual void printContent() const override; //print status content 
	VideoStatus() { setIndex(VIDEO);} //ct'or
	VideoStatus(string content, string dataName); //ct'or
	virtual string getDataFileName(); //get data file name 
};
