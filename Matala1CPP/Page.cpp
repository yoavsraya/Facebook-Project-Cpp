#include "page.h"
#include "Member.h"
#include "Exceptions.h"

page::page(const char* name, const char* status1, const char* status2) noexcept(false)
{
	if (strlen(name) == EMPTY)
		throw wrongInput();
	m_name = name;
	m_board.reserve(2);
	status* firststatus;
	try
	{
		firststatus = new status;
	}
	catch (bad_alloc& e)
	{
		throw badAlloc();
	}
	*firststatus = status1;
	m_board.push_back(firststatus);
	status* secstatus = new status;
	try
	{
		firststatus = new status;
	}
	catch (bad_alloc& e)
	{
		throw badAlloc();
	}
	*secstatus = status2;
	m_board.push_back(secstatus);
}

page::~page()
{
	for (int i = 0; i < m_board.size(); i++)
	{
		delete m_board.at(i);
	}
}

bool page::operator>(const page& _page) const
{
	if (m_ListOFfollowers.size() > _page.m_ListOFfollowers.size())
		return true;
	return false;
}

bool page::operator>(const member& _member) const
{
	if (m_ListOFfollowers.size() > _member.myNumOfFriends())
		return true;
	return false;
}

page::page(string name)
{
	if (name.size() == EMPTY)
		throw emptyName();
	m_name = name;
}




