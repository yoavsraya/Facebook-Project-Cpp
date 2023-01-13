#include "Object.h"

int object::myNumOfMembers() const // return num of friend
{
	return m_MemberList.size();
}

void object::RemoveFollower(const member* _member) //remove follower from page
{
		int followeInd = findFollowerInd(_member);
		vector<member*>::iterator itr = m_MemberList.begin() + followeInd;
		m_MemberList.erase(itr);
	
}

int object::findFollowerInd(const member* follower) const
{
	for (int i = 0; i < m_MemberList.size(); i++)
	{
		if (m_MemberList[i] == follower)
			return i;
	}
	return -1;
}

void object::addFollower(member* const follower)
{
	m_MemberList.push_back(follower);
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

