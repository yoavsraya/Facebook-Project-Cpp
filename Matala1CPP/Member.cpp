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

void member::printMyFriendFriendList(int const ind) const //print one of the friend friend list
{
	m_friendsList.at(ind)->printFriends();
}

member::member(const member& other) //ct'or
{
	m_name = other.m_name;
	m_dateOfBirth = other.m_dateOfBirth;
	m_friendsList = other.m_friendsList;
	m_mySatuses = other.m_mySatuses;
	m_pages = other.m_pages;
}

member::member(const string name, const string birthDate) //ct'or
{
	m_name = name;
	m_dateOfBirth = birthDate;
}

void member::updateFriend(member* _member) // update frien at friend list
{
	m_friendsList.push_back(_member);
}

void member::addFriend(member* _member) // add friend 
{
	if (isFriendExist(_member))
	{
		cout << "You are already friends!" << endl;
		return;
	}
	if (_member == this)
	{
		cout << "you cant add your self!!" << endl;
		return;
	}

	updateFriend(_member);
	_member->updateFriend(this);
}

int member::findFriendIndex(const char* wanted)const // find friend index
{
	int res;
	for (int i = 0; i < m_friendsList.size(); i++)
	{
		if (m_friendsList.at(i)->m_name == wanted)
		{
			res = i;
			return res;
		}
	}
	return -1;
}

void member::removeFriend(const int indOfRemove) // remove friend from friend list
{
	if (m_friendsList.size() == 0)
	{
		cout << "You dont have friends at all!" << endl;
		return;
	}
	vector<member*>::iterator itr = m_friendsList.begin() + indOfRemove;
	m_friendsList.erase(itr);
}

void member::addPage(page* currPage) //add follow to a page
{
	if (isPageExist(currPage))
	{
		cout << "Page already followed" << endl;
		return;
	}
	
	m_pages.push_back(currPage);
	currPage->addFollower(this);
}

void member::removePage(const int indOfRemove) //remove follow from page
{
	if (m_pages.size() == 0)
	{
		cout << "You are not following any pages at all!" << endl;
		return;
	}
	m_pages.at(indOfRemove)->removeFollower(this);
	vector<page*>::iterator itr = m_pages.begin() + indOfRemove;
	m_pages.erase(itr);
}

void member::printMyFriendStatuses()const //print my friend statuses
{
	for (int i = 0; i < m_friendsList.size(); i++)
	{
		m_friendsList.at(i)->printMyStatuses();
	}

}

void member::printFriends()const // print my friend list 
{
	cout << "My friend List is: " << endl;
	for (int i = 0; i < m_friendsList.size(); i++)
	{
		cout << "#" << i + 1 << " ";
		cout << m_friendsList.at(i)->m_name << endl;
	}
}

void member::printPages()const // print the pages that i follow 
{
	cout << "List of the Pages I follow:" << endl;
	for (int i = 0; i < m_pages.size(); i++)
	{
		cout << "#" << i + 1 << endl;
		m_pages.at(i)->printPage();
	}
}

void member::printMyStatuses()const // print my statuses
{
	cout << "My Statuses:" << endl;
	for (int i = 0; i < m_mySatuses.size(); i++)
	{
		m_mySatuses.at(i)->printStatus();
	}
}

void member::createStatus(const char* _status) // create new status
{
	status* newStatus = new status;
	newStatus->getContent(_status);
	m_mySatuses.push_back(newStatus);

	updatelastStatuses(newStatus);
}

void member::updatelastStatuses(status* _status) //update the 10 last statuses
{
	if (m_last10statuses.size() == 0)
	{
		for (int i = 9; i > 0; i--)
		{
			m_last10statuses[i] = m_last10statuses[i - 1];
		}
		m_last10statuses[m_logSize10Statuses] = _status;
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
