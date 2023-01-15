#pragma once

#include <string>
#include <vector>
#include "Status.h"
#include "Member.h"
#include "Page.h"

class object
{
	string m_name;
	vector<object*> m_MemberList;
	vector<status*> m_mySatuses;

public:

	int myNumOfMembers() const; // return num of follwers
	virtual void RemoveObjectFromList(const object* _object); //remove friend or page from member list 
	int findFollowerInd(const object* follower)const; //return member index
	void addFollower(object* const object); //add new follower/friend
	virtual void createStatus(const string text); //create status from string
	virtual void updatelastStatuses(status* _status) = 0;
	void printMyStatuses() const; //print all this statuses
	virtual void printMydetails(); //print object
	virtual void PrintMyMemberList(); // print my member list
	virtual bool isFriendExist(const object* _member)const; //check if the parmater is a friend of this
	virtual bool isPageExistInMyList(const page* _page)const = 0; // only for memebr :: check if page is already exsist at his pages
	void PrintPagesThatImFollowing(); // only for memebr :: print pages that member follow


};
