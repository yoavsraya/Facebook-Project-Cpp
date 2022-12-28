#pragma once
#include "Member.h"
#include "Page.h"
#include "Exceptions.h"
#include <vector>
#pragma warning(disable: 4996)

const int MAX_NAME_LENGTH = 30;
const int MAX_DATE_LENGTH = 11;
const int MAX_STATUS_LENGTH = 1000;

class Facebook
{
public:
	void printMembers()const; //print All members
	void printPages()const; //print All pages
	Facebook();//Ct'or
	~Facebook();//Dt'or
	void addMember(member* const other); // add new member to facebook 
	void removeMember(const int index); // remove facebook friend (not in use for now)
	void addPage(page* other); // add new page to facebook
	void removePage(const int index); //remove page from facebook
	void runMenu(); // run facebook program until exit
	void starterFunc(); // start facebook with 3 users and 3 pages
	void printMenu()const; // print menu
	int whoAreYou(); // return user index
	int whichOne(int size); //return user index
	int whichPage(); //return page
	void WhoisBigger(); //use oprator > (Q2)
	bool isExsist(string name);

private:
	vector <member*> m_members;
	vector <page*> m_pages;
	
public:
	void watch_MyFriend_List()noexcept(false); //11
	void  print_All_FaceBook_Members_And_Pages() const noexcept(false); //10
	void UnlikePage()noexcept(false); //9
	void LikeNewPage()noexcept(false); //8
	void RemoveFriend()noexcept(false); //7
	void AddFriend()noexcept(false); //6
	void WhatIsMyfriend_Friends_Latest_Status()noexcept(false); //5
	void SeeAllMyStatus()noexcept(false); //4
	void  WriteNewStatus()noexcept(false); //3
	void AddNewPage()noexcept(false); //2
	void AddNewMember()noexcept(false); //1
	
};

