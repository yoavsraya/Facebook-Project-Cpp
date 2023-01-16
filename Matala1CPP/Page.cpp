#include "page.h"
#include "Member.h"
#include "Exceptions.h"

int page::NumOfPages = 0;


page::~page()
{
	for (int i = 0; i < m_board.size(); i++)
	{
		delete m_board.at(i);
	}
	NumOfPages--;
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

void page::createStatus(const string content, int index, string dataName) //create new status
{
	status* newStatus;
	if (index == TEXT)
		newStatus = new status(content);
	else if (index == VIDEO)
		newStatus = new VideoStatus(content, dataName);
	else
		newStatus = new ImageStastus(content, dataName);
	if (!newStatus)
		throw badAlloc();
	m_board.push_back(newStatus);

}

void page::printAllStatus()const // print all statuses
{
	if (m_board.size() == EMPTY)
		throw emptyStatusesList();
	cout << "your status are:" << endl;
	for (int i = 0; i < m_board.size(); i++)
	{
		m_board[i]->printContent();
	}
}

void page::printPage()const //print page
{
	cout << m_name << endl;
}

page::page(string name)
{
	if (name.size() == EMPTY)
		throw emptyName();
	index = NumOfPages;
	NumOfPages++;
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
	if (m_ListOFfollowers.size() == EMPTY)
		throw emptyFollowerList();

	cout << "the page " << this->m_name << " follwers are:" << endl;
	for (int i = 0; i < m_ListOFfollowers.size(); i++)
	{
		cout << "# " << i + 1 << endl;
		m_ListOFfollowers[i]->printMyDetails();
	}
}

void page::writeToFile(fstream& file)
{
	int type;
	file << index << endl;
	file << m_ListOFfollowers.size() << endl;
	for (int i = 0; i < m_ListOFfollowers.size(); i++)
	{
		file << m_ListOFfollowers.at(i)->getIndex() << " " << m_ListOFfollowers.at(i)->getName() << endl;
	}
	file << m_board.size() << endl;
	for (int i = 0; i < m_board.size(); i++)
	{
		type = m_board.at(i)->getTypeIndex();
		file << m_board.at(i)->getTypeIndex() << endl;
		file << m_board.at(i)->getContent() << endl;
		file << m_board.at(i)->getTime() << endl;
		if (type != 0)
			file << m_board.at(i)->getDataFileName() << endl;
	}


}

void page::createStatusFromFile(string content, time_t time, int type, string datatype)
{
	status* newStatus;
	if (type == TEXT)
		newStatus = new status(content);
	else if (type == VIDEO)
		newStatus = new VideoStatus(content,datatype);
	else
		newStatus = new ImageStastus(content, datatype);
	if (!newStatus)
		throw badAlloc();

	newStatus->setTime(time);
	m_board.push_back(newStatus);
}

