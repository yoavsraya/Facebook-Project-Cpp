#pragma once
#include <iostream>
#include <time.h>
#include <string>
#include "Exceptions.h"
#pragma warning(disable: 4996)
using namespace std;
const int EMPTY = 0;

class status
{
public:
	void printContent() const noexcept(false); //print status contant
	status(const string content) noexcept(false); //ct'or
	status(const status& other); //copy ct'or
	bool operator==(const status& other)const; //opartor == Q2
	bool operator!=(const status& other)const; //opartor != Q2
	status& operator=(const string str); // oprator = for string
	status& operator=(const char* str); // oprator = for char*
	status(){};
	
private:
	time_t dateAndtimeOfStatus;
	string m_content;
};