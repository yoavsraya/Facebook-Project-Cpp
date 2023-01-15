#pragma once

#include <iostream>
#include "Status.h"
#include <vector>
#include<array>
#include <string>
#include "Exceptions.h"
#include "Object.h"
#pragma warning(disable: 4996)
class page;

using namespace std;
const int FULL = -1;

class member : public object
{
public:
	member(const string name, const string birthDate); //c'tor
	member() {}; //empty c'tor
	virtual object& operator+=(object& _object);
	virtual void setBirth(const char* birth); // update birth
	virtual void updatelastStatuses(status* _status); //update last 10 statuses
	void print10lastStatuses(); //print last 10 status
	string getDate() { return m_dateOfBirth;}

private:

	string m_dateOfBirth;
	int m_logSize10Statuses = 9;
	array<status*, 10> m_last10statuses;
};


