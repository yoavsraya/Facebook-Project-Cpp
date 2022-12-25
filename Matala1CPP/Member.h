#pragma once

class page;
#include <iostream>
#include "Status.h"
#include <vector>
#include<array>
#pragma warning(disable: 4996)

using namespace std;
const int MAX_NAME_LEN = 30;
const int DATE_LEN = 11;


class member
{
public:
	//member(const char* name, const char* birthDate,const char* status1,const char* status2);
	member(const char* name, const char* birthDate);
	member(const member& other);
	member() {};
	bool isFriendExist(const member* _member)const;
	void printMyFriendFriendList(int const ind) const;
	bool isPageExist(const page* _page)const;
	int findFriendIndex(const char* wanted)const;
	void addFriend(member* _member); //add friend to friend list
	void removeFriend(const int indOfRemove); //remove friend from friend list
	void addPage(page* currPage);
	void removePage(const int indOfRemove);
	void printFriends() const;
	void printPages() const;
	void createStatus(const char* status);
	void printMyStatuses() const;
	void printMyDetails() const;
	void setName(const char* name);
	void setBirth(const char* birth);
	void printMyFriendStatuses() const;
	void updatelastStatuses(status* _status);
	void print10lastStatuses(const int index) const;
	int myNumOfFriends()const ; //return my number of friends
	int myNumOfPagesFollow()const; // return mt number of pages I following

private:
	void updateFriend(member* _member);
	char m_name[MAX_NAME_LEN];
	char m_dateOfBirth[DATE_LEN];
	int m_logSize10Statuses = 9;
	vector<member*> m_friendsList;
	vector<page*> m_pages;
	vector<status*> m_mySatuses;
	array<status*, 10> m_last10statuses;
};
