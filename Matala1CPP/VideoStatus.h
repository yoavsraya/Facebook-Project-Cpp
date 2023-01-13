#pragma once

#include "Status.h"

class  VideoStatus: public status
{

public:
	virtual void printStatus() const noexcept(false) override; //print image status contant

};
