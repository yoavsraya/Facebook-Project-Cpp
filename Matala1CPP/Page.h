#pragma once
#include "Status.h"
#include <vector>
#include <string>
#include "Object.h"
#pragma warning(disable: 4996)
class member;

class page : public object
{
	
public:
	page(const char* name, const char* status1, const char* status2) noexcept(false); //ct'or
	page() {}; //empty ct'or
	page(const string name); //ct'or
	~page(); //d'tor
};


