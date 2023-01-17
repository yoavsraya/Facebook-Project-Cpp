#pragma once

class page;
#include <fstream>
#include "VideoStatus.h"
#include "ImageStatus.h"
#include <vector>
#include<array>
#include <string>
#include "Exceptions.h"
#pragma warning(disable: 4996)

using namespace std;
const int FULL = -1;
const int FULL_CAPACITY_INDEX = 9;
const int ARRAY_SIZE = 10;

class member
{
public:
	member(const string name, const string birthDate); //c'tor
	member(const member& other); //ct'or
	member() { index = NumOfMember; NumOfMember++; }; //empty c'tor
	~member();
	member& operator+=(member& _member); //op +=
	member& operator+=(page& _page); //op +=
	bool operator>(const member& _member) const; //op >
	bool operator>(const page& _page) const;// op >
	bool isFriendExist(const member* _member)const; //check if the parmater is a friend of this
	bool isPageExist(const page* _page)const; //check if page is exsist
	void removeFriend(const member* friendToRemove); //remove friend from friend list
	void removePage(const int indOfRemove); //remove follow from a page
	void printFriends() const; //print this friends
	void printPages() const; //print pages i follow
	void createStatus(const string content, int index, string dataName); //create new status
	void printMyStatuses() const; //print all this statuses
	void printMyDetails() const; //print details
	void setName(const char* name); //update name
	void setBirth(const char* birth); // update birth
	void updatelastStatuses(status* _status); //update last 10 statuses
	void print10lastStatuses() const; //print last 10 status
	int myNumOfFriends()const; //return my number of friends
	int myNumOfPagesFollow()const; // return mt number of pages I following
	void printMyFriendLastStatuses()const; //print last 10 statuses of my friends
	member* friendIndex(int index)const; //return pointer to member by index
	string getName(); //get name
	string getDate() { return m_dateOfBirth; } // get birth day
	void writeToFile(fstream& file); // write member to file 
	int getIndex() { return index; } // get member index
	void createStatusFromFile(string contant, time_t time, int type, string datatype); // create status from file 
	void AddFriendFromFile(member* other) { m_friendsList.push_back(other); } //add friend to friend list from file 

private:
	string m_name;
	string m_dateOfBirth;
	int m_logSize10Statuses = FULL_CAPACITY_INDEX;
	vector<member*> m_friendsList;
	vector<page*> m_pages;
	vector<status*> m_mySatuses;
	array<status*, ARRAY_SIZE> m_last10statuses;
	int index;
	static int NumOfMember;
};


