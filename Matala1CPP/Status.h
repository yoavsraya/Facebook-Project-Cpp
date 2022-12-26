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
	status& operator=(const status& other);
	status(){};

private:
	time_t dateAndtimeOfStatus;
	string m_content;

};