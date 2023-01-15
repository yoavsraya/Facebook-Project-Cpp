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

void member::printFriends()const // print my friend list 
{
	if (m_friendsList.size() == EMPTY)
		throw emptyFriendList();
	cout << "My friend List is: " << endl;
	for (int i = 0; i < m_friendsList.size(); i++)
	{
		cout << "#" << i + 1 << " ";
		cout << m_friendsList.at(i)->m_name << endl;
	}
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

void member::printMyStatuses()const // print my statuses
{
	if (m_mySatuses.size() == EMPTY)
		throw emptyStatusesList();
	cout << "My Statuses:" << endl;
	for (int i = 0; i < m_mySatuses.size(); i++)
	{
		m_mySatuses.at(i)->printContent();
	}
}

void member::createStatus(const string _status) // create new status
{
	status* newStatus = new status;
	if (!newStatus)
		throw badAlloc();

	*newStatus = _status;
	m_mySatuses.push_back(newStatus);
	updatelastStatuses(newStatus);
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
		m_last10statuses[i]->printContent();
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

void member::printMyDetails()const // print my info
{
	cout << "Name: " << m_name << endl;
	cout << "Born in: " << m_dateOfBirth << endl;
}

int member::myNumOfFriends()const // return num of friend
{
	return m_friendsList.size();
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


