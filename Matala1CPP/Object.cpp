#include "Object.h"

int object::myNumOfMembers() const // return num of friend
{
	return m_MemberList.size();
}

void object::RemoveObjectFromList(const object* _object) //remove follower from page
{
	int Ind = 0;
	member* Pm = dynamic_cast<member*>(this);
	if (Pm) //if im member
	{
		if (m_MemberList.size() == EMPTY)
			throw emptyFriendList();
		bool found = false;
		if (m_MemberList.size() == EMPTY)
			throw emptyFriendList();

		while (Ind < m_MemberList.size() && found == false)
		{
			if (m_MemberList.at(Ind) == _object)
				found = true;
			else
				Ind++;
		}

		if (found == false)
			throw memberdontFriendWithYou();

	}
	else //im a page 
	{
		if (m_MemberList.size() == EMPTY)
			throw emptyFollowerList();
		Ind = findFollowerInd(_object);
		if (Ind == -1)
			throw memberdontFollowYou();
	}
		
	vector<object*>::iterator itr = m_MemberList.begin() + Ind;
	m_MemberList.erase(itr);
}

int object::findFollowerInd(const object* follower) const
{
	for (int i = 0; i < m_MemberList.size(); i++)
	{
		if (m_MemberList[i] == follower)
			return i;
	}
	return -1;
}

void object::addFollower(object* const object)
{
	m_MemberList.push_back(object);
}

void object::createStatus(const string text)
{
	status* tmp;
	//change to image or video !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	try
	{
		//tmp = new status;
	}
	catch (std::bad_alloc& e)
	{
		throw badAlloc();
	}
	*tmp = text;
	m_mySatuses.push_back(tmp);

	member* Pm = dynamic_cast<member*>(this);
	if (Pm != nullptr)
	{
		updatelastStatuses(tmp);
	}
		
}

void object::printMyStatuses() const
{
	if (m_mySatuses.size() == EMPTY)
		throw emptyStatusesList();
	cout << "My Statuses:" << endl;
	for (int i = 0; i < m_mySatuses.size(); i++)
	{
		m_mySatuses.at(i)->printStatus();
	}
}

void object::printMydetails()
{
	cout << m_name << endl;
	member* Pm = dynamic_cast<member*>(this);
	if (Pm)
	{
		cout << "Born in: " << Pm->getDate() << endl;
	}
}

void object::PrintMyMemberList()
{
	if (m_MemberList.size() == EMPTY)
		throw emptyFriendList();
	member* Pm = dynamic_cast<member*>(this);
	if(Pm) //if im member
	cout << "My friend List is: " << endl;
	else // im page
	cout << "the page " << this->m_name << " follwers are:" << endl;

	for (int i = 0; i < m_MemberList.size(); i++)
	{
		cout << "#" << i + 1 << " ";
		cout << m_MemberList.at(i)->m_name << endl;
	}

}

bool object::isFriendExist(const object* _member) const
{
	bool exist = false;
	for (int i = 0; i < m_MemberList.size() && exist == false; i++)
	{
		if (m_MemberList.at(i)->m_name == _member->m_name)
		{
			exist = true;
			
		}
	}

	return exist;
}

void object::PrintPagesThatImFollowing()
{
	int i = m_MemberList.size() - 1;
	page* Pp = dynamic_cast<page*>(m_MemberList.at(i));

	while (Pp) // im a page
	{
		m_MemberList.at(i)->printMydetails();
		i--;
		Pp = dynamic_cast<page*>(m_MemberList.at(i));
	}
}


