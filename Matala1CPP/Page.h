#pragma once
#include "Status.h"
#include <vector>
#pragma warning(disable: 4996)

class member;

class page
{
	char m_name[30];
	vector <member*> m_ListOFfollowers;
	vector <status*> m_board;

public:
	page(const char* name, const char* status1, const char* status2);
	page() {};
	page(const char* name);
	int findFollowerInd(member* const follower)const;
	void addFollower(member* const follower);
	void removeFollower(member* follower);
	void createStatus(char* const text);
	void printAllStatus();
	void set(char* const name);
	void printPage()const;
	void printFollowers()const;	
};

