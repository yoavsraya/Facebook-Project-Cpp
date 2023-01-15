#pragma once

#include "Status.h"

class  VideoStatus: public status
{
	string VideoFileName = "start ";
public:
	void printVideoStatus() const;
};
