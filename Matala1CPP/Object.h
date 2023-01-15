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
	virtual void RemoveObjectFromList(object* _object); //remove friend or page from member list 
	int findFollowerInd(const object* follower)const; //return member index
	void addFollower(object* const object); //add new follower/friend
	virtual void createStatus(const string text); //create status from string
	virtual void updatelastStatuses(status* _status) = 0;
	void printMyStatuses() const; //print all this statuses
	virtual void printMydetails(); //print object
	virtual void PrintMyMemberList(); // print my member list
	bool operator>(const object& _object)const;
	virtual object& operator+=(object& _object) = 0; // relevant only to member
	bool isObjectExistInMyList(const object* _member)const; //check if the parmater is a friend of this
	void PrintPagesThatImFollowing(); // only for memebr :: print pages that member follow
	void setName(const string name) { m_name = name; } //set name
	virtual void setBirth(const char* birth) = 0; //only for memebr :: set birth
	virtual void updatelastStatuses(status* _status) = 0; // only for memebr :: /update last 10 statuses
	virtual void print10lastStatuses() const = 0; //print last 10 status
	string getName(); //get object name
	void printMyFriendLastStatuses()const; //only for memebr ::print last 10 statuses of my friends
	object* friendIndex(int index)const; //return pointer to member by index

};
