#pragma once
#include <iostream>
#include <time.h>
#pragma warning(disable: 4996)
using namespace std;

class status
{
public:
	void getContent(const char* content);
	void printStatus();
	status(const char* content);
	status(const status& other);
	status& operator=(const status& other);
	status(){};
	~status();

private:
	time_t dateAndtimeOfStatus;
	char* m_content;

};