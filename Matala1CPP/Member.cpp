#include "Member.h"
#include "Page.h"

bool member::isPageExist(page* _page) // check if page is already exsist at his pages
{
	bool exist = false;
	for (int i = 0; i < m_logSizePageList; i++)
	{
		if (m_pages[i] == _page)
		{
			exist = true;
			return exist;
		}
	}
	return exist;
}

member::~member() //dct'or
{
	if (m_isFirstFriend == false)
	{
		delete[] m_friendsList;
	}
	if (m_isFirstPage == false)
	{	
		delete[]m_pages;
	}

	if (m_isFirstStatus == false)
	{
		for (int i = 0; i < m_logSizeStatusList; i++)
		{
			delete m_mySatuses[i];
		}
		delete[]m_mySatuses;
	}
}
	

bool member::isFriendExist(member* _member) //check if friend is already at friend with this
{
	bool exist = false;
	for (int i = 0; i < m_logSizeFriendList; i++)
	{
		if (strcmp(m_friendsList[i]->m_name ,_member->m_name) == 0)
		{
			exist = true;
			return exist;
		}
	}
	return exist;
}

void member::printMyFriendFriendList(int ind) //print one of the friend friend list
{
	m_friendsList[ind]->printFriends();
}

member::member(const member& other) //ct'or
{
	strcpy_s(m_name, other.m_name);
	strcpy_s(m_dateOfBirth, other.m_dateOfBirth);
	m_friendsList = other.m_friendsList;
	m_mySatuses = other.m_mySatuses;
	m_pages = other.m_pages;
}

member::member(const char* name, const char* birthDate) //ct'or
{
	strcpy(m_name, name);
	strcpy(m_dateOfBirth, birthDate);
}

void member::updateFriend(member* _member) // update frien at friend list
{
	if (m_isFirstFriend == true)
	{
		m_friendsList = new member*[2];
		m_isFirstFriend = false;
		m_physSizeFriendList = 2;
	}
	m_friendsList[m_logSizeFriendList] = _member;
	m_logSizeFriendList++;
	//delete m_friendsList;
	cout << _CrtDumpMemoryLeaks();
	if (m_logSizeFriendList == m_physSizeFriendList)
	{
		m_physSizeFriendList *= 2;
		m_friendsList = ourRealloc(m_logSizeFriendList, m_physSizeFriendList, m_friendsList);
	}
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

int member::findFriendIndex(char* wanted) // find friend index
{
	int res;
	for (int i = 0; i < m_logSizeFriendList; i++)
	{
		if (strcmp(m_friendsList[i]->m_name, wanted) == 0)
		{
			res = i;
			return res;
		}
	}
	return -1;
}

void member::removeFriend(int indOfRemove) // remove friend from friend list
{
	if (m_logSizeFriendList == 0)
	{
		cout << "You dont have friends at all!" << endl;
		return;
	}
	for (int i = indOfRemove; i < m_logSizeFriendList; i++)
	{
		m_friendsList[i] = m_friendsList[i + 1];
	}
	m_logSizeFriendList--;
	m_friendsList = ourRealloc(m_physSizeFriendList, m_logSizeFriendList, m_friendsList);
}

void member::addPage(page* currPage) //add follow to a page
{
	if (m_isFirstPage == true)
	{
		m_pages = new page*;
		m_isFirstPage = false;
	}
	if (isPageExist(currPage))
	{
		cout << "Page already followed" << endl;
		return;
	}
	
	m_pages[m_logSizePageList] = currPage;
	m_logSizePageList++;
	if (m_logSizePageList == m_physSizePageList)
	{
		m_physSizePageList *= 2;
		m_pages = ourRealloc(m_logSizePageList, m_physSizePageList, m_pages);
	}
	currPage->addFollower(this);
}

void member::removePage(int indOfRemove) //remove follow from page
{
	if (m_logSizePageList == 0)
	{
		cout << "You are not following any pages at all!" << endl;
		return;
	}
	m_pages[indOfRemove]->removeFollower(this);
	for (int i = indOfRemove; i < m_logSizePageList; i++)
	{
		m_pages[i] = m_pages[i + 1];
	}
	m_logSizePageList--;
	m_pages = ourRealloc(m_physSizePageList, m_logSizePageList, m_pages);

}

void member::printMyFriendStatuses() //print my friend statuses
{
	for (int i = 0; i < m_logSizeFriendList; i++)
	{
		m_friendsList[i]->printMyStatuses();
	}

}

void member::printFriends() // print my friend list 
{
	cout << "My friend List is: " << endl;
	for (int i = 0; i < m_logSizeFriendList; i++)
	{
		cout << "#" << i + 1 << " ";
		cout << m_friendsList[i]->m_name << endl;
	}
}

void member::printPages() // print the pages that i follow 
{
	cout << "List of the Pages I follow:" << endl;
	for (int i = 0; i < m_logSizePageList; i++)
	{
		cout << "#" << i + 1 << endl;
		m_pages[i]->printPage();
	}
}

void member::printMyStatuses() // print my statuses
{
	cout << "My Statuses:" << endl;
	for (int i = 0; i < m_logSizeStatusList; i++)
	{
		m_mySatuses[i]->printStatus();
	}
}

void member::createStatus(const char* _status) // create new status
{
	
	if (m_isFirstStatus == true)
	{
		m_mySatuses = new status*[2];
		m_isFirstStatus = false;
		m_physSizeFriendList = 2;
	}
	m_mySatuses[m_logSizeStatusList] = new status;
	m_mySatuses[m_logSizeStatusList]->getContent(_status);
	m_logSizeStatusList++;
	if (m_logSizeStatusList == m_physSizeStatusList)
	{
		m_physSizeStatusList *= 2;
		m_mySatuses = ourRealloc(m_logSizeStatusList, m_physSizeStatusList, m_mySatuses);
	}

	for (int i = 0; i < m_logSizeFriendList; i++)
	{
		m_friendsList[i]->updatelastStatuses(m_mySatuses[m_logSizeStatusList - 1]);
	}
}

void member::updatelastStatuses(status* _status) //update the 10 last statuses
{
	if (m_logSize10Statuses == 0)
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

void member::print10lastStatuses(int index) // print last 10 statuses
{
	cout << "the last 10 statuses of " << m_friendsList[index]->m_name << " friends is:" << endl;
	for (int i = 9; i > m_logSize10Statuses; i--)
	{
		m_friendsList[index]->m_last10statuses[i]->printStatus();
	}
}

void member::setName(char* name) 
{
	strcpy_s(m_name, name);
}

void member::setBirth(char* birth)
{
	strcpy_s(m_dateOfBirth, birth);
}

void member::printMyDetails() // print my info
{
	cout << "Name: " << m_name << endl;
	cout << "Born in: " << m_dateOfBirth << endl;
}

int member::myNumOfFriends() // return num of friend
{
	return m_logSizeFriendList;
}

int member::myNumOfPagesFollow() // return num of pages i'm follow
{
	return m_logSizePageList;
}
