#pragma once
#include <iostream> 
using namespace std;

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