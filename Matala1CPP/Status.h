#pragma once
#include <iostream>
#include <time.h>
#include <string>
#pragma warning(disable: 4996)
using namespace std;

class status
{
public:
	void printStatus() const;
	status(const char* content) noexcept(false);
	status(const status& other);
	bool operator==(const status& other)const;
	bool operator!=(const status& other)const;
	status& operator=(const char* str);
	status(){};

private:
	time_t dateAndtimeOfStatus;
	string m_content;

};