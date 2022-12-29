#pragma once

class page;
#include <iostream>
#include "Status.h"
#include <vector>
#include<array>
#include <string>
#include "Exceptions.h"
#pragma warning(disable: 4996)

using namespace std;
const int FULL = -1;

class member
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
	bool isFriendExist(const member* _member)const; //check if the parmater is a friend of this
	bool isPageExist(const page* _page)const; //check if page is exsist
	void removeFriend(const member* friendToRemove); //remove friend from friend list
	void removePage(const int indOfRemove); //remove follow from a page
	void printFriends() const; //print this friends
	void printPages() const; //print pages i follow
	void createStatus(const string status); //create new status
	void printMyStatuses() const; //print all this statuses
	void printMyDetails() const; //print details
	void setName(const char* name); //update name
	void setBirth(const char* birth); // update birth
	void updatelastStatuses(status* _status); //update last 10 statuses
	void print10lastStatuses() const; //print last 10 status
	int myNumOfFriends()const ; //return my number of friends
	int myNumOfPagesFollow()const; // return mt number of pages I following
	void printMyFriendLastStatuses()const; //print last 10 statuses of my friends
	member* friendIndex(int index)const; //return pointer to member by index
	string getName(); //get name

private:
	string m_name;
	string m_dateOfBirth;
	int m_logSize10Statuses = 9;
	vector<member*> m_friendsList;
	vector<page*> m_pages;
	vector<status*> m_mySatuses;
	array<status*, 10> m_last10statuses;
};


