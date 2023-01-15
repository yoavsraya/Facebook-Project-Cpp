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
	member(const member& other); //ct'or
	member() {}; //empty c'tor
	~member();
	member& operator+=(member& _member); //op +=
	member& operator+=(page& _page); //op +=
	bool operator>( const member& _member) const; //op >
	bool operator>( const page& _page) const;// op >
	virtual bool isPageExistInMyList(const page* _page)const; //check if page is exsist
	void setName(const char* name); //update name
	void setBirth(const char* birth); // update birth
	void updatelastStatuses(status* _status); //update last 10 statuses
	void print10lastStatuses() const; //print last 10 status
	int myNumOfPagesFollow()const; // return mt number of pages I following
	void printMyFriendLastStatuses()const; //print last 10 statuses of my friends
	member* friendIndex(int index)const; //return pointer to member by index
	string getName(); //get name
	string getDate() { return m_dateOfBirth;}

private:

	string m_dateOfBirth;
	int m_logSize10Statuses = 9;
	vector<page*> m_pages;
	array<status*, 10> m_last10statuses;
};


