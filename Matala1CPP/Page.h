#pragma once
#include "Status.h"
#include <vector>
#include <string>
#pragma warning(disable: 4996)

class member;

class page
{
	string m_name;
	vector <member*> m_ListOFfollowers;
	vector <status*> m_board;

public:
	page(const char* name, const char* status1, const char* status2) noexcept(false);
	page() {};
	page(const char* name);
	bool operator>(const page& _page)const;
	bool operator>(const member& _member)const;
	int findFollowerInd(member* const follower)const;
	int myNumOfFollowers() const;
	void addFollower(member* const follower);
	void removeFollower(member* follower);
	void createStatus(char* const text);
	void printAllStatus()const;
	void set(char* const name);
	void printPage()const;
	void printFollowers()const;	
};

class pageException : public std::exception
{
public:
	virtual const char* what() const override
	{
		return "Faild create page\n";
	}
};

