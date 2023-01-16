#pragma once

#include "Status.h"
const int VIDEO = 1;

class  VideoStatus: public status
{
	string VideoFileName = "start ";
public:
	void printVideoStatus() const;
	VideoStatus() { setIndex(VIDEO);}
	VideoStatus(string content, string dataName);
	virtual string getDataFileName();
};
