#pragma once
#include "Status.h"
#include "generalFun.h"
#pragma warning(disable: 4996)

class member;

class page
{
	char m_name[30];
	member** m_ListOFfollowers = nullptr;
	status** m_board = nullptr;
	bool m_isFirstStatus = true;
	int m_phySizeFollowers = 1;
	int m_logSizeFollowers = 0;

	int m_phySizeBoard = 1;
	int m_logSizeBoard = 0;

public:
	page(const char* name, const char* status1, const char* status2);
	page() {};
	~page();
	page(const char* name);
	int findFollowerInd(member* follower);
	void addFollower(member* follower);
	void removeFollower(member* follower);
	void createStatus(char* text);
	void printAllStatus();
	void set(char* name);
	void printPage();
	void printFollowers();	
};

