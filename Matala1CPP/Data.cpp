#include "data.h"

Facebook::Facebook()
{
	m_members = new member*[3];
	m_pages = new page*[3];
	m_physSizeMembers = 3;
	m_physSizePages = 3;
}

Facebook::~Facebook() //free program
{
	for (int i = 0; i < m_logSizeMembers; i++)
	{
		
		delete m_members[i];
	}
	delete[]m_members;

	for (int i = 0; i < m_logSizePages; i++)
	{
		delete m_pages[i];
	}
	delete[]m_pages;
} 

void Facebook::addMember(member* _member) //add new member to facebook
{
	if (m_logSizeMembers == m_physSizeMembers)
	{
		m_physSizeMembers++;
		m_members = ourRealloc(m_logSizeMembers, m_physSizeMembers, m_members);
	}
	m_members[m_logSizeMembers] = new member;
	m_members[m_logSizeMembers] = _member;
	m_logSizeMembers++;
} 

void Facebook::removeMember(const int index) // remove friend from facebook
{
	delete m_members[index];
	for (int i = index; i < m_logSizeMembers; i++)
	{
		m_members[i] = m_members[i + 1];
	}
	m_members[m_logSizeMembers - 1] = nullptr;

	m_members = ourRealloc(m_logSizeMembers, m_logSizeMembers - 1, m_members);
}

void Facebook::printMembers() //print all members at facebook 
{
	for (int i = 0; i < m_logSizeMembers; i++)
	{
		cout << "#" << i + 1 << endl;
		m_members[i]->printMyDetails();
	}
}

void Facebook::addPage(page* _page) //add new page to facebook
{
	if (m_logSizePages == m_physSizePages)
	{
		m_physSizePages++;
		m_pages = ourRealloc(m_logSizePages, m_physSizePages, m_pages);
	}
	m_pages[m_logSizePages] = new page;
	m_pages[m_logSizePages] = _page;
	m_logSizePages++;
}

void Facebook::removePage(const int index) //remove page from facebook
{
	for (int i = index; i < m_logSizePages; i++)
	{
		m_pages[i] = m_pages[i + 1];
	}
	m_pages[m_logSizePages - 1] = nullptr;
	m_pages = ourRealloc(m_logSizePages, m_logSizePages - 1, m_pages);
}

void Facebook::printPages() // print all pages on facebook
{
	for (int i = 0; i < m_logSizePages; i++)
	{
		cout << "#" << i + 1 << " ";
		m_pages[i]->printPage();
	}
}

void Facebook::starterFunc() //start the facebook with 3 members, 3 page, and 2 statuses each
{
	member* starterUser1 = new member("Uzi Harush", "06/09/1988");
	member* starterUser2 = new member("Boaz Cohen", "04/05/1973");
	member* starterUser3 = new member("Barak Kendell", "24/05/1981");
	
	m_members[0] = starterUser1;
	m_members[1] = starterUser2;
	m_members[2] = starterUser3;
	m_logSizeMembers = 3;

	page* starterPage1 = new page("golf Lovers", "tonight! tiger woods challenging the world championship", "what is your favorite club?");
	page* starterPage2 = new page("math for doctors", "google just found the next number in phi!!", "Leonhard Euler is the best");
	page* starterPage3 = new page("weather news", "big storm coming to us this weekend!", "this is a butiful day today!");

	m_pages[0] = starterPage1;
	m_pages[1] = starterPage2;
	m_pages[2] = starterPage3;
	m_logSizePages = 3;
	
	m_members[0]->addPage(m_pages[2]);
	m_members[1]->addFriend(m_members[2]);
	m_members[2]->addPage(m_pages[0]);

	m_members[0]->createStatus("hi im uzi");
	m_members[0]->createStatus("i teach calculus 1");
	m_members[1]->createStatus("hi im boaz");
	m_members[1]->createStatus("i teach calculus 2");
	m_members[2]->createStatus("hi im barak");
	m_members[2]->createStatus("i teach probability");

}

void Facebook::runMenu() //run the facebook manu until exit
{
	bool runningProgram = true;
	int select;

	while (runningProgram == true)
	{
		printMenu();
		cin >> select;
		switch (select)
		{
		case (12):
			runningProgram = false;
			break;
		case(11):
			watch_MyFriend_Friend_List();
			break;
		case(10):
			print_All_FaceBook_Members_And_Pages();
			break;
		case(9):
			UnlikePage();
			break;
		case(8):
			LikeNewPage();
			break;
		case(7):
			RemoveFriend();
			break;
		case(6):
			AddFriend();
			break;
		case(5):
			WhatIsMyfriend_Friends_Latest_Status();
			break;
		case(4):
			SeeAllMyStatus();
			break;
		case(3):
			WriteNewStatus();
			break;
		case(2):
			AddNewPage();
			break;
		case(1):
			AddNewMember();
			break;
		}
	}
	cout << "Thanks you for using our FaceBook! hope to see you soon again :)" << endl;
}

void Facebook::printMenu() //print manu option
{
	cout << "\nwhat would you like to do? (insert number from 1-12):" << endl;
	cout << "1 - Add New Member\n2 - Add New Page\n3 - Write New Status\n4 - See All My Status\n5 - What is My friend friends latest Status\n6 - Add friend\n7 - Remove Friend\n8 - Like New Page\n9 - Unlike Page\n10 - print All FaceBook Members And Pages\n11 - Watch My Friend List Friends\n12 - Exit" << endl << endl;
}

int Facebook::whoAreYou() // return the user index 
{
	int ind;
	cout << "who Are you? choose number: " << endl;
	cout << "--------------" << endl;
	for (int i = 1; i <= m_logSizeMembers; i++)
	{
		cout << "#" << i << endl;
		m_members[i - 1]->printMyDetails();
		cout << "----------------------------" << endl;
	}
	cin >> ind;
	while (ind < 1 || ind >m_logSizeMembers)
	{
		cout << "Invalid choice! Please choose again:" << endl;
		cin >> ind;
	}
	return ind - 1;
}

int Facebook::whichPage() //return page index
{
	int ind;
	cout << "who Are you? choose number: " << endl;
	cout << "--------------" << endl;
	for (int i = 1; i <= m_logSizePages; i++)
	{
		cout << "#" << i << endl;
		m_pages[i - 1]->printPage();
		cout << "----------------------------" << endl;
	}
	cin >> ind;
	while (ind < 1 || ind > m_logSizePages)
	{
		cout << "Invalid choice! Please choose again:" << endl;
		cin >> ind;
	}
	return ind - 1;
}

int Facebook::whichOne() //ask the user to choose one 
{
	cout << "choose One:" << endl;
	int res;
	cin >> res;
	return res - 1;
}

//////////////////////All the menu functions 1-11

void Facebook::watch_MyFriend_Friend_List() //11
{
	int indMe = whoAreYou(); //who is the user 
	int chose;
	int index;
	cout << "what would you like to do? (choose the number)" << endl;
	cout << "----------------------------" << endl;
	cout << "1. watch one of my friend friends list" << endl;
	cout << "2. watch one of the pages followers" << endl;
	cin >> chose;
	while (chose != 1 && chose != 2)
	{
		cout << "Invalid choice! Please choose again:" << endl;
		cin >> chose;
	}
	if (chose == 1)
	{
		m_members[indMe]->printFriends(); // the user friends list
		index = whichOne(); // the user choose friend
		m_members[indMe]->printMyFriendFriendList(index);
	}
	else if (chose == 2)
	{
		printPages();
		index = whichOne(); // the user choose friend
		m_pages[index]->printFollowers();

	}
}

void  Facebook::print_All_FaceBook_Members_And_Pages() //10
{
	cout << "All Facebook users: " << endl;
	for (int i = 0; i < m_logSizeMembers; i++)
	{
		m_members[i]->printMyDetails();
		cout << endl;
	}
	cout << "----------------------------" << endl;
	cout << endl;
	cout << "All Pages in Facebook: " << endl;
	for (int i = 0; i < m_logSizePages; i++)
	{
		m_pages[i]->printPage();
	}
}

void Facebook::UnlikePage() //9
{
	int indMe = whoAreYou();
	if (m_members[indMe]->myNumOfPagesFollow() == 0)
	{
		cout << " you dont follow after any page" << endl;
		return;
	}
	m_members[indMe]->printPages();
	int pageInd = whichOne();
	while (pageInd < 0 && pageInd > m_members[indMe]->myNumOfPagesFollow())
	{
		cout << "Invalid choice! Please choose again:" << endl;
		pageInd = whichOne();
	}
	m_members[indMe]->removePage(pageInd);
}

void Facebook::LikeNewPage() //8
{
	int ind = whoAreYou();
	cout << "choose a page you want to follow:" << endl;
	printPages();
	int pageInd = whichOne();
	while (pageInd < 0 && pageInd > m_logSizePages)
	{
		cout << "Invalid choice! Please choose again:" << endl;
		pageInd = whichOne();
	}
	m_members[ind]->addPage(m_pages[pageInd]);
}

void Facebook::RemoveFriend() //7
{
	
	int indMe = whoAreYou();
	if (m_members[indMe]->myNumOfFriends() == 0)
	{
		cout << "you dont have any friends!" << endl;
		return;
	}
	cout << "choose a friend to remove" << endl;
	m_members[indMe]->printFriends();
	int friendInd = whichOne();
	while (friendInd < 0 && friendInd > m_members[friendInd]->myNumOfFriends())
	{
		cout << "Invalid choice! Please choose again:" << endl;
		friendInd = whoAreYou();
	}
	m_members[indMe]->removeFriend(friendInd);
}

void Facebook::AddFriend() //6
{
	int indMe = whoAreYou();
	cout << "choose a friend you want to add" << endl;
	printMembers();
	int friendToAdd = whichOne();
	while (friendToAdd < 0 && friendToAdd > m_logSizeMembers)
	{
		cout << "Invalid choice! Please choose again:" << endl;
		friendToAdd = whoAreYou();
	}
	m_members[indMe]->addFriend(m_members[friendToAdd]);
}

void Facebook::WhatIsMyfriend_Friends_Latest_Status() //5
{
	int member_index = whoAreYou();
	if (m_members[member_index]->myNumOfFriends() == 0)
	{
		cout << "you dont have any friends!" << endl;
		return;
	}
	m_members[member_index]->printFriends();
	int friend_index = whichOne();
	while (friend_index < 0 && friend_index > m_members[member_index]->myNumOfFriends())
	{
		cout << "Invalid choice! Please choose again:" << endl;
		friend_index = whoAreYou();
	}
	m_members[member_index]->print10lastStatuses(friend_index);
}

void Facebook::SeeAllMyStatus() //4
{
	int choose;
	int index;
	cout << "are you a page or a member? (choose 1 or 2)" << endl;
	cout << "1. I'm A page" << endl;
	cout << "2. I'm A member" << endl;

	cin >> choose;
	while (choose != 1 && choose != 2)
	{
		cout << "Invalid choice! Please choose again:" << endl;
		cin >> choose;
	}
	if (choose == 1)
	{
		index = whichPage();
		m_pages[index]->printAllStatus();
	}

	else if (choose == 2)
	{
		index = whoAreYou();
		m_members[index]->printMyStatuses();
	}
}

void  Facebook::WriteNewStatus() //3
{
	int choose;
	int index;
	char contant[MAX_STATUS_LENGTH];

	cout << "are you a page or a member? (choose 1 or 2)" << endl;
	cout << "1. I'm A page" << endl;
	cout << "2. I'm A member" << endl;
	cin >> choose;
	while (choose != 1 && choose != 2)
	{
		cout << "Invalid choice! Please choose again:" << endl;
		cin >> choose;
	}
	if (choose == 2)
	{
		index = whoAreYou();
		cout << "what is on your mind? (no more then 1,000 letters)" << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.getline(contant, 1000);
		m_members[index]->createStatus(contant);
	}
	
	else if (choose == 1)
	{
		index = whichPage();
		cout << "what is on your mind? (no more then 1,000 letters)" << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.getline(contant, 1000);
		m_pages[index]->createStatus(contant);
	}
	else
		cout << "you choose the worng number choose again" << endl;

}

void Facebook::AddNewPage() //2
{
	char name[MAX_NAME_LENGTH];
	cout << "What is the page name?" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.getline(name, MAX_NAME_LENGTH);
	page* newPage = new page(name);
	addPage(newPage);
}

void Facebook::AddNewMember() //1
{
	char name[MAX_NAME_LENGTH];
	char date[MAX_DATE_LENGTH];

	cout << "What is your name?" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.getline(name, MAX_NAME_LENGTH);
	cout << "When have you burn? insert XX/XX/XXXX" << endl;
	cin.getline(date, MAX_DATE_LENGTH);
	member* newMember = new member(name, date);
	addMember(newMember);
}