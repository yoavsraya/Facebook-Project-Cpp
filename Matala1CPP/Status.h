#pragma once
#include <iostream>
#include <time.h>
#include <string>
#include "Exceptions.h"
#pragma warning(disable: 4996)
using namespace std;
const int EMPTY = 0;
const int TEXT = 0;

class status
{
public:
	virtual void printContent() const noexcept(false); //print status contant
	status(const string content) noexcept(false); //ct'or
	status(const status& other); //copy ct'or
	bool operator==(const status& other)const; //opartor == Q2
	bool operator!=(const status& other)const; //opartor != Q2
	status& operator=(const string str); // oprator = for string
	status& operator=(const char* str); // oprator = for char*
	status(){};
	virtual string getDataFileName() { return "\0"; }
	string getContent() { return m_content; }
	time_t getTime() { return dateAndtimeOfStatus; }
	int getTypeIndex() { return TypeIndex; }
	void setIndex(int _index) { TypeIndex = _index; }
	void setName(string content) { m_content = content; }
	void setTime(time_t time) { dateAndtimeOfStatus = time; }
	
private:
	time_t dateAndtimeOfStatus;
	string m_content;
	int TypeIndex =0;
};