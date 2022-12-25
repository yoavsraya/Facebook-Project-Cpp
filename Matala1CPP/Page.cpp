#include "page.h"
#include "Member.h"

page::page(const char* name, const char* status1, const char* status2) //ct'or
{
	strcpy(m_name, name);
	if (m_isFirstStatus == true)
	{
	m_board = new status*[3];
	m_isFirstStatus = false;
	}
	m_logSizeBoard = 2;
	m_phySizeBoard = 3;
	m_board[0] = new status;
	m_board[1] = new status;
	m_board[0]->getContent(status1);
	m_board[1]->getContent(status2);
}

void page::addFollower(member* follower) // add foolower to a page
{
	bool isFirst = true;
	if (isFirst == true)
	{
		m_ListOFfollowers = new member*;
	}
	if (m_logSizeFollowers == m_phySizeFollowers)
	{
		m_phySizeFollowers++;
		m_ListOFfollowers = ourRealloc(m_logSizeFollowers, m_phySizeFollowers, m_ListOFfollowers);
	}
	m_ListOFfollowers[m_logSizeFollowers] = follower;
	m_logSizeFollowers++;
}

void page::removeFollower(member* follower) //remove follower from page
{
	int followeInd = findFollowerInd(follower);
	for (int i = followeInd; i < m_logSizeFollowers; i++)
	{
		m_ListOFfollowers[i] = m_ListOFfollowers[i + 1];
	}

	m_ListOFfollowers = ourRealloc(m_logSizeFollowers, m_logSizeFollowers - 1, m_ListOFfollowers);
}

void page::createStatus(char* text) //create new status
{
	if (m_isFirstStatus == true)
	{
		m_board = new status*;
		m_isFirstStatus = false;
	}
	if (m_logSizeBoard == m_phySizeBoard)
	{
		m_phySizeBoard++;
		m_board = ourRealloc(m_logSizeBoard, m_phySizeBoard, m_board);
	}
	m_board[m_logSizeBoard] = new status;
	m_board[m_logSizeBoard]->getContent(text);
	m_logSizeBoard++;
}

void page::printAllStatus() // print all statuses
{
	cout << "your status are:" << endl;
	for (int i = 0; i < m_logSizeBoard; i++)
	{
		m_board[i]->printStatus();
	}
}

void page::printPage() //print page
{
	cout << m_name << endl;
}

void page::set(char* name)
{
	strcpy_s(m_name, name);
}

page::~page() //dt'or
{
	if (m_logSizeFollowers != 0)
	{
		delete[] m_ListOFfollowers;
	}
	
	if (m_logSizeBoard != 0)
	{
		for (int i = 0; i < m_logSizeBoard; i++)
		{
			delete m_board[i];
		}
		m_logSizeBoard = 0;
		delete[]m_board;
	}

}

page::page(const char* name)
{
	strcpy(m_name, name);
}

int page::findFollowerInd(member* follower) //find follower index
{
	for (int i = 0; i < m_logSizeFollowers; i++)
	{
		if (m_ListOFfollowers[i] == follower)
			return i;
	}
	return -1;
}

void page::printFollowers() //print followers of a page
{
	cout << "the page " << this->m_name << " follwers are:" << endl;
	for (int i = 0; i < m_logSizeFollowers; i++)
	{
		cout << "# " << i + 1 << endl;
		m_ListOFfollowers[i]->printMyDetails();
	}
}
