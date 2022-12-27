#include "page.h"
#include "Member.h"
#include "Exceptions.h"

page::page(const char* name, const char* status1, const char* status2) noexcept(false)
{
	if (strlen(name) == 0)
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
		delete firststatus;
		throw badAlloc();
	}
	*secstatus = status2;
	m_board.push_back(secstatus);
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


int page::myNumOfFollowers()const
{
	return m_ListOFfollowers.size();
}

void page::addFollower(member* follower) // add foolower to a page
{
	m_ListOFfollowers.push_back(follower);
}

void page::removeFollower(member* follower) //remove follower from page
{
	int followeInd = findFollowerInd(follower);
	vector<member*>::iterator itr = m_ListOFfollowers.begin() + followeInd;
	m_ListOFfollowers.erase(itr);
}

void page::createStatus(char* const text) //create new status
{
	status* tmp = new status;
	try
	{
		tmp = new status;
	}
	catch (std::bad_alloc& e)
	{
		throw badAlloc();
	}
	*tmp = text;
	m_board.push_back(tmp);
	
}

void page::printAllStatus()const // print all statuses
{
	cout << "your status are:" << endl;
	for (int i = 0; i < m_board.size(); i++)
	{
		m_board[i]->printStatus();
	}
}

void page::printPage()const //print page
{
	cout << m_name << endl;
}

void page::set(char* const name)
{
	if (strlen(name) == 0)
		throw "invalid name";
	m_name = name;
}

page::page(const char* name)
{
	if (strlen(name) == 0)
		throw "invalid name";
	m_name = name;
}

int page::findFollowerInd(member* const follower)const//find follower index
{
	for (int i = 0; i < m_ListOFfollowers.size(); i++)
	{
		if (m_ListOFfollowers[i] == follower)
			return i;
	}
	return -1;
}

void page::printFollowers()const //print followers of a page
{
	cout << "the page " << this->m_name << " follwers are:" << endl;
	for (int i = 0; i < m_ListOFfollowers.size(); i++)
	{
		cout << "# " << i + 1 << endl;
		m_ListOFfollowers[i]->printMyDetails();
	}
}

