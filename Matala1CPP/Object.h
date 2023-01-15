#pragma once

#include <string>
#include <vector>
#include "Status.h"
#include "Member.h"

class member;

class object
{
	string m_name;
	vector<object*> m_MemberList;
	vector<status*> m_mySatuses;

public:

	int myNumOfMembers() const; // return num of follwers
	void RemoveFollower(const object* _member);
	int findFollowerInd(const object* follower)const; //return member index
	void addFollower(object* const follower); //add new follower
	virtual void createStatus(const string text); //create status from string
	virtual void updatelastStatuses(status* _status) = 0;
	void printMyStatuses() const; //print all this statuses
	virtual void printMydetails(); //print object
	virtual void PrintMyMemberList(); // print my member list


};
