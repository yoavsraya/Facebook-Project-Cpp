#pragma once
#include <iostream> 
using namespace std;

void clearBuffer();

class badAlloc : public exception
{
public:
	virtual const char* what() const override
	{
		return "Alocation failed";
	}
};

class wrongInput : public exception
{
public:
	virtual const char* what() const override
	{
		clearBuffer();
		return "Wrong input";
	}
};

class userExist : public exception
{
public:
	virtual const char* what() const override
	{
		return "Cannot add user that already exist...";
	}
};

class friendExist : public exception
{
public:
	virtual const char* what() const override
	{
		return "You are already friends";
	}
};

class emptyFriendList : public exception
{
public:
	virtual const char* what() const override
	{
		return "You dont have any friends";
	}
};

class emptyPageList : public exception
{
public:
	virtual const char* what() const override
	{
		return "You are not following on any pages";
	}
};

class emptyFollowerList : public exception
{
public:
	virtual const char* what() const override
	{
		return "Nobody follow this page";
	}
};

class emptyStatusesList : public exception
{
public:
	virtual const char* what() const override
	{
		return "You dont have any statuses!";
	}
};

class emptyStatus : public exception
{
public:
	virtual const char* what() const override
	{
		return "Empty status is not allowed...";
	}
};

class invalidDate : public exception
{
public:
	virtual const char* what() const override
	{
		clearBuffer();
		return "Invalid date...";
	}
};

class emptyName : public exception
{
public:
	virtual const char* what() const override
	{
		return "Empty name is not allowed...";
	}
};

class alreadyFriends : public exception
{
public:
	virtual const char* what() const override
	{
		return "You Are already friends!!";
	}
};

class AddYourSelf : public exception
{
public:
	virtual const char* what() const override
	{
		return "You cant add yourself!";
	}
};