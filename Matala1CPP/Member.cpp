#include "Member.h"
#include "Page.h"

bool member::isPageExistInMyList(const page* _page)const // check if page is already exsist at his pages
{
	bool exist = false;
	for (int i = 0; i < m_pages.size(); i++)
	{
		if (m_pages.at(i) == _page)
		{
			exist = true;
			return exist;
		}
	}
	return exist;
}

bool member::operator>(const page& _page) const
{
	if (m_friendsList.size() > _page.myNumOfFollowers())
		return true;
	return false;
}

member::~member()
{
	for (int i = 0; i < m_mySatuses.size(); i++)
	{
		delete m_mySatuses.at(i);
	}
}

member& member::operator+=(member& _member)
{
	m_friendsList.push_back(&_member);
	_member.m_friendsList.push_back(this);
	return *this;
}

member& member::operator+=(page& _page)
{
	m_pages.push_back(&_page);
	_page.addFollower(this);
	return *this;
}


bool member::operator>(const member& _member) const
{
	if (m_friendsList.size() > _member.m_friendsList.size())
		return true;
	return false;
}

member::member(const member& other) //copy ct'or
{
	m_name = other.m_name;
	m_dateOfBirth = other.m_dateOfBirth;
	m_friendsList = other.m_friendsList;
	m_mySatuses = other.m_mySatuses;
	m_pages = other.m_pages;
}

member::member(const string name, const string birthDate) //ct'or
{
	if (name.size() == EMPTY)
		throw wrongInput();
	m_name = name;
	m_dateOfBirth = birthDate;
}

void member::updatelastStatuses(status* _status) //update the 10 last statuses
{
	if (m_logSize10Statuses == FULL)
	{
		for (int i = 9; i > EMPTY; i--)
		{
			m_last10statuses[i] = m_last10statuses[i - 1];
		}
		m_last10statuses[0] = _status;
	}
	else
	{
		m_last10statuses[m_logSize10Statuses] = _status;
		m_logSize10Statuses--;
	}
}

void member::print10lastStatuses()const // print last 10 statuses
{
	cout << "the last 10 statuses of " << m_name << " is:" << endl;
	for (int i = 9; i > m_logSize10Statuses; i--)
	{
		m_last10statuses[i]->printStatus();
	}
}

void member::setName(const char* name) 
{
	m_name = name;
}

void member::setBirth(const char* birth)
{
	m_dateOfBirth = birth;
}

int member::myNumOfPagesFollow()const // return num of pages i'm follow
{
	return m_pages.size();
}

void member::printMyFriendLastStatuses() const
{
	for (int i = 0; i < m_friendsList.size(); i++)
	{
		m_friendsList.at(i)->print10lastStatuses();
	}
}

member* member::friendIndex(int index) const
{
	return m_friendsList.at(index);
}



string member::getName()
{
	return m_name;
}


