#pragma once
#include "Status.h"

class ImageStastus : public status
{
	string ImageFileName = "start ";
public:
	void printImageStatus()const;
};
