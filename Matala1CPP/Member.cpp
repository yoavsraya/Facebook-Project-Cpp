#include "Member.h"
#include "Page.h"

bool member::isPageExist(const page* _page)const // check if page is already exsist at his pages
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

member::~member()
{
	for (int i = 0; i < m_mySatuses.size(); i++)
	{
		delete m_mySatuses.at(i);
	}
}

object& member::operator+=(object& _object)
{
	this->addFollower(&_object);
	_object.addFollower(this);
	return *this;
}


bool member::isFriendExist(const member* _member)const //check if friend is already at friend with this
{
	bool exist = false;
	for (int i = 0; i < m_friendsList.size(); i++)
	{
		if (m_friendsList.at(i)->m_name == _member->m_name)
		{
			exist = true;
			return exist;
		}
	}
	return exist;
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


void member::removeFriend(const member* friendToRemove) // remove friend from friend list
{
	int i = 0;
	bool found = false;
	if (m_friendsList.size() == EMPTY)
		throw emptyFriendList();

	while (i < m_friendsList.size() && found == false)
	{
		if (m_friendsList.at(i) == friendToRemove)
			found = true;
		else
			i++;
	}

	if (found == false)
		throw wrongInput();

	vector<member*>::iterator itr = m_friendsList.begin() + i;
	m_friendsList.erase(itr);
}

void member::removePage(const int indOfRemove) //remove follow from page
{
	if (m_pages.size() == EMPTY)
		throw emptyPageList();
	m_pages.at(indOfRemove)->removeFollower(this);
	vector<page*>::iterator itr = m_pages.begin() + indOfRemove;
	m_pages.erase(itr);
}

void member::printPages()const // print the pages that i follow 
{
	if (m_pages.size() == EMPTY)
		throw emptyPageList();
	cout << "List of the Pages I follow:" << endl;
	for (int i = 0; i < m_pages.size(); i++)
	{
		cout << "#" << i + 1 << endl;
		m_pages.at(i)->printPage();
	}
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


