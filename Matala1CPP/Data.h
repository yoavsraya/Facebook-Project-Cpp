#pragma once
#include "Member.h"
#include "Page.h"
#include <vector>
#pragma warning(disable: 4996)

const int MAX_NAME_LENGTH = 30;
const int MAX_DATE_LENGTH = 11;
const int MAX_STATUS_LENGTH = 1000;

class Facebook
{
public:
	void printMembers();
	void printPages();
	Facebook();
	~Facebook();
	void addMember(member* other);
	void removeMember(const int index);
	void addPage(page* other);
	void removePage(const int index);
	void runMenu();
	void starterFunc();
	void printMenu();
	int whoAreYou();
	int whichOne();
	int whichPage();

private:
	vector <member*> m_members;
	vector <page*> m_pages;
	
public:
	void watch_MyFriend_Friend_List(); //11
	void  print_All_FaceBook_Members_And_Pages(); //10
	void UnlikePage(); //9
	void LikeNewPage(); //8
	void RemoveFriend(); //7
	void AddFriend(); //6
	void WhatIsMyfriend_Friends_Latest_Status(); //5
	void SeeAllMyStatus(); //4
	void  WriteNewStatus(); //3
	void AddNewPage(); //2
	void AddNewMember(); //1
};

