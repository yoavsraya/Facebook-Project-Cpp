#pragma once
#include <iostream>
#include <time.h>
#include <string>
#pragma warning(disable: 4996)
using namespace std;

class status
{
public:
	void getContent(const char* content);
	void printStatus() const;
	status(const char* content);
	status(const status& other);
	bool operator==(const status& other)const;
	bool operator!=(const status& other)const;
	status(){};

private:
	time_t dateAndtimeOfStatus;
	string m_content;

};