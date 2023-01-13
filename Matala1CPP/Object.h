#pragma once

#include <string>
#include <vector>
#include "Member.h"
#include "Page.h"
#include "Status.h"

class object
{
	string m_name;
	vector<member*> m_MemberList;
	vector<status*> m_mySatuses;

public:

	int myNumOfMembers() const; // return num of follwers
	void RemoveFollower(const member* _member);
	int findFollowerInd(const member* follower)const; //return member index
	void addFollower(member* const follower); //add new follower
	virtual void createStatus(const string text); //create status from string
	virtual void updatelastStatuses(status* _status) = 0;
	void printMyStatuses() const; //print all this statuses
	virtual void printMydetails(); //print object
	void PrintMyObjectsList() const; // to do


};
