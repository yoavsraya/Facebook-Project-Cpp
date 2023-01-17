#pragma once
#include <iostream> 
using namespace std;

void clearBuffer();

class badAlloc : public exception // when Alocation failed
{
public:
	virtual const char* what() const override
	{
		return "Alocation failed";
	}
};

class wrongInput : public exception //when Wrong input
{
public:
	virtual const char* what() const override
	{
		clearBuffer();
		return "Wrong input";
	}
};

class userExist : public exception // when adding user that already exist
{
public:
	virtual const char* what() const override
	{
		return "Cannot add user that already exist...";
	}
};

class friendExist : public exception // when aading friend that already exist
{
public:
	virtual const char* what() const override
	{
		return "You are already friends";
	}
};

class emptyFriendList : public exception //when doing something on empty freind list
{
public:
	virtual const char* what() const override
	{
		return "You dont have any friends";
	}
};

class emptyPageList : public exception //when doing something on empty page list
{
public:
	virtual const char* what() const override
	{
		return "You are not following on any pages";
	}
};

class emptyFollowerList : public exception //when doing something on empty follower list
{
public:
	virtual const char* what() const override
	{
		return "Nobody follow this page";
	}
};

class emptyStatusesList : public exception // when doing something on empty Statuses list
{
public:
	virtual const char* what() const override
	{
		return "You dont have any statuses!";
	}
};

class emptyStatus : public exception // cannot add empty status
{
public:
	virtual const char* what() const override
	{
		return "Empty status is not allowed...";
	}
};

class invalidDate : public exception // date is not rational
{
public:
	virtual const char* what() const override
	{
		clearBuffer();
		return "Invalid date...";
	}
};

class emptyName : public exception // cant choose empty name
{
public:
	virtual const char* what() const override
	{
		return "Empty name is not allowed...";
	}
};

class alreadyFriends : public exception //cant add to friend list a friend
{
public:
	virtual const char* what() const override
	{
		return "You Are already friends!!";
	}
};

class alreadyfollow : public exception //cant add to friend list a friend
{
public:
	virtual const char* what() const override
	{
		return "You Are already follow this page!!";
	}
};

class AddYourSelf : public exception //cant add yourself
{
public:
	virtual const char* what() const override
	{
		return "You cant add yourself!";
	}
};

class memberdontFollowYou : public exception //cant add yourself
{
public:
	virtual const char* what() const override
	{
		return "This member dosent follow your page!";
	}
};

class memberdontFriendWithYou : public exception //cant add yourself
{
public:
	virtual const char* what() const override
	{
		return "This member is Not friend Of yours!!!";
	}
};

class Nomembers : public exception //cant add yourself
{
public:
	virtual const char* what() const override
	{
		return "there is no members on facebook!";
	}
};