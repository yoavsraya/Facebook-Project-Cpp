#pragma once

class page;
#include <iostream>
#include "Status.h"
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
	~member();
	bool isFriendExist(member* _member);
	void printMyFriendFriendList(int ind);
	bool isPageExist(page* _member);
	int findFriendIndex(char* wanted);
	void addFriend(member* _member); //add friend to friend list
	void removeFriend(int indOfRemove); //remove friend from friend list
	void addPage(page* currPage);
	void removePage(int indOfRemove);
	void printFriends();
	void printPages();
	void createStatus(const char* status);
	void printMyStatuses();
	void printMyDetails();
	void setName(char* name);
	void setBirth(char* birth);
	void printMyFriendStatuses();
	void updatelastStatuses(status* _status);
	void print10lastStatuses(int index);
	int myNumOfFriends(); //return my number of friends
	int myNumOfPagesFollow(); // return mt number of pages I following

private:
	void updateFriend(member* _member);
	char m_name[MAX_NAME_LEN];
	char m_dateOfBirth[DATE_LEN];
	int m_logSizeFriendList = 0;
	int m_physSizeFriendList = 0;
	int m_logSizePageList = 0;
	int m_physSizePageList = 0;
	int m_logSizeStatusList = 0;
	int m_physSizeStatusList = 0;
	int m_logSize10Statuses = 9;
	bool m_isFirstStatus = true;
	bool m_isFirstFriend = true;
	bool m_isFirstPage = true;
	member** m_friendsList = nullptr;
	page** m_pages = nullptr;
	status** m_mySatuses = nullptr;
	status* m_last10statuses[10];
};
