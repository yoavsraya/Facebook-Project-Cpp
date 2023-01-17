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
	status(){}; // empty cto'r
	virtual string getDataFileName() { return "\0"; } // get data file name
	string getContent()const { return m_content; } // get status content
	time_t getTime()const { return dateAndtimeOfStatus; } //get time 
	int getTypeIndex() { return TypeIndex; } // get type index of status
	void setIndex(int _index) { TypeIndex = _index; } //set index for status
	void setName(string content) { m_content = content; } //set name
	void copyTime(time_t time) { dateAndtimeOfStatus = time; } //copy time from file
	void setTime() { time(&dateAndtimeOfStatus); } // set time for corrent

	
private:
	time_t dateAndtimeOfStatus;
	string m_content;
	int TypeIndex =0;
};