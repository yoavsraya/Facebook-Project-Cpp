#include "page.h"
#include "Member.h"

page::page(const char* name, const char* status1, const char* status2) //ct'or
{
	strcpy(m_name, name);
	m_board.reserve(2);
	m_board[0]->getContent(status1);
	m_board[1]->getContent(status2);
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
	tmp->getContent(text);
	m_board.push_back(tmp);
	
}

void page::printAllStatus() // print all statuses
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
	strcpy_s(m_name, name);
}

page::page(const char* name)
{
	strcpy(m_name, name);
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
