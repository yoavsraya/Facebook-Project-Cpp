#pragma once

class page;
#include <iostream>
#include "Status.h"
#include <vector>
#include<array>
#include <string>
#pragma warning(disable: 4996)

using namespace std;

class member
{
public:
	//member(const char* name, const char* birthDate,const char* status1,const char* status2);
	member(const string name, const string birthDate);
	member(const member& other);
	member() {};
	member& operator+=(member& _member);
	member& operator+=(page& _page);
	bool operator>( const member& _member) const;
	bool operator>( const page& _page) const;
	bool isFriendExist(const member* _member)const;
	void printMyFriendFriendList(int const ind) const;
	bool isPageExist(const page* _page)const;
	int findFriendIndex(const char* wanted)const;
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
	void print10lastStatuses() const;
	int myNumOfFriends()const ; //return my number of friends
	int myNumOfPagesFollow()const; // return mt number of pages I following
	void printMyFriendLastStatuses()const;

private:
	void updateFriend(member* _member);
	string m_name;
	string m_dateOfBirth;
	int m_logSize10Statuses = 9;
	vector<member*> m_friendsList;
	vector<page*> m_pages;
	vector<status*> m_mySatuses;
	array<status*, 10> m_last10statuses;
};

class memberException : public exception
{
public:
	virtual const char* what() const override
	{
		return ""
	}
};
