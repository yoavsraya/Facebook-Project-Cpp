#include "data.h"
#include "Exceptions.h"

Facebook::Facebook()
{
	m_members.reserve(3);
	m_pages.reserve(3);
}

Facebook::~Facebook() //free program
{
	for (int i = 0; i < m_members.size(); i++)
	{
		
		delete m_members.at(i);
	}

	for (int i = 0; i < m_pages.size(); i++)
	{
		delete m_pages.at(i);
	}
} 

void Facebook::addMember(member* const _member) //add new member to facebook
{
	
	//member* temp = new member;
	m_members.push_back(_member);
} 

void Facebook::removeMember(const int index) // remove friend from facebook
{
	delete m_members.at(index);
	vector <member*>::iterator itor = m_members.begin() + index;
	m_members.erase(itor);
}

void Facebook::printMembers()const //print all members at facebook 
{
	for (int i = 0; i < m_members.size(); i++)
	{
		cout << "#" << i + 1 << endl;
		m_members.at(i)->printMyDetails();
	}
}

void Facebook::addPage(page* _page) //add new page to facebook
{
	m_pages.push_back(_page);
}

void Facebook::removePage(const int index) //remove page from facebook
{
	delete m_pages.at(index);
	vector <page*>::iterator itor = m_pages.begin() + index;
	m_pages.erase(itor);
}

void Facebook::printPages()const // print all pages on facebook
{
	for (int i = 0; i < m_pages.size(); i++)
	{
		cout << "#" << i + 1 << " ";
		m_pages.at(i)->printPage();
	}
}

void Facebook::starterFunc() //start the facebook with 3 members, 3 page, and 2 statuses each
{
	member* starterUser1 = new member("Uzi Harush", "06/09/1988");
	member* starterUser2 = new member("Boaz Cohen", "04/05/1973");
	member* starterUser3 = new member("Barak Kendell", "24/05/1981");
	
	m_members.push_back(starterUser1);
	m_members.push_back(starterUser2);
	m_members.push_back(starterUser3);

	page* starterPage1 = new page("golf Lovers", "tonight! tiger woods challenging the world championship", "what is your favorite club?");
	page* starterPage2 = new page("math for doctors", "google just found the next number in phi!!", "Leonhard Euler is the best");
	page* starterPage3 = new page("weather news", "big storm coming to us this weekend!", "this is a butiful day today!");

	m_pages.push_back(starterPage1);
	m_pages.push_back(starterPage2);
	m_pages.push_back(starterPage3);

	m_members.at(0)->addPage(m_pages.at(2));
	*m_members.at(1) += *m_members.at(2);
	m_members.at(2)->addPage(m_pages.at(0));

	m_members.at(0)->createStatus("hi im uzi");
	m_members.at(0)->createStatus("i teach calculus 1");
	m_members.at(1)->createStatus("hi im boaz");
	m_members.at(1)->createStatus("i teach calculus 2");
	m_members.at(2)->createStatus("hi im barak");
	m_members.at(2)->createStatus("i teach probability");

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
			watch_MyFriend_List();
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
		default:
			cout << "Wrong choice, choose again..." << endl;
			break;
		}
	}
	cout << "Thanks you for using our FaceBook! hope to see you soon again :)" << endl;
}

void Facebook::printMenu()const //print manu option
{
	cout << "\nwhat would you like to do? (insert number from 1-12):" << endl;
	cout << "1 - Add New Member\n2 - Add New Page\n3 - Write New Status\n4 - See All My Status\n5 - What is My friend friends latest Status\n6 - Add friend\n7 - Remove Friend\n8 - Like New Page\n9 - Unlike Page\n10 - print All FaceBook Members And Pages\n11 - Watch My Friend List\n12 - Exit" << endl << endl;
}

int Facebook::whoAreYou() // return the user index 
{
	int ind;
	cout << "who Are you? choose number: " << endl;
	cout << "--------------" << endl;
	for (int i = 1; i <= m_members.size(); i++)
	{
		cout << "#" << i << endl;
		m_members.at(i - 1)->printMyDetails();
		cout << "----------------------------" << endl;
	}
	cin >> ind;
	if (ind < 1 || ind >m_members.size())
		throw wrongInput();

	return ind - 1;
}

int Facebook::whichPage() //return page index
{
	int ind;
	cout << "who Are you? choose number: " << endl;
	cout << "--------------" << endl;
	for (int i = 1; i <= m_pages.size(); i++)
	{
		cout << "#" << i << endl;
		m_pages.at(i - 1)->printPage();
		cout << "----------------------------" << endl;
	}
	cin >> ind;
	if (ind < 1 || ind > m_pages.size())
		throw wrongInput();

	return ind - 1;
}

void Facebook::WhoisBigger()
{
	int choose1;
	int choose2;
	int indme;
	int indcompre;
	bool res;

	cout << "are you page or member? enter 1 for member, 2 for page" << endl;
	cin >> choose1;
	if (choose1 == 1)
		 indme = whoAreYou();
	else if (choose1 == 2)
		 indme = whichPage();
	cout << "what do you want to compre with? choose 1 for member, 2 for page" << endl;
	cin >> choose2;
	if (choose2 == 1)
		 indcompre = whichOne();
	else if (choose2 == 2)
		 indcompre = whichPage();

	if (choose1 == choose2 == 1)
	{
		if (*m_members[indme] > *m_members[indcompre])
		{
			m_members[indme]->printMyDetails();
			cout << "have more friend then ";
			m_members[indcompre]->printMyDetails();
		}
		else
		{
			m_members[indme]->printMyDetails();
			cout << "have less friend then ";
			m_members[indcompre]->printMyDetails();
		}
	}

	else if (choose1 == choose2 == 2)
	{
		if (*m_pages[indme] > *m_pages[indcompre])
		{
			m_pages[indme]->printPage();
			cout << "have more followers then ";
			m_pages[indcompre]->printPage();
		}
		else
		{
			m_pages[indme]->printPage();
			cout << "have less followers then ";
			m_pages[indcompre]->printPage();
		}
	}
	
	else if (choose1 == 1 && choose2 == 2)
	{
		if (*m_members[indme] > *m_pages[indcompre])
			cout << "the member have more";
		else
			cout << "the page have more";
	}

	else if (choose1 == 2 && choose2 == 1)
	{
		if (*m_pages[indme] > *m_members[indcompre])
			cout << "the page have more";
		else
			cout << "the member have more";
	}

		
	

}

bool Facebook::isExsist(string name)
{
	for (int i = 0; i < m_members.size(); i++)
	{
		if (m_members.at(i)->getName() == name)
			return false;
	}
	return true;
}

int Facebook::whichOne() //ask the user to choose one 
{
	cout << "choose One:" << endl;
	int res;
	cin >> res;
	return res - 1;
}

//////////////////////All the menu functions 1-11

void Facebook::watch_MyFriend_List()noexcept(false) //11
{
	int choose;
	cout << "are you a member or a page?" << endl;
	cout << "1. i'm member" << endl;
	cout << "2. i'm page" << endl;
	cin >> choose;
	if (choose != 1 || choose != 2)
		throw wrongInput();

	if (choose == 1)
	{
		int indMe = whoAreYou(); //who is the user 
		m_members.at(indMe)->printFriends();
	}
	else
	{
		int indMe = whichPage(); //who is the page
		m_pages.at(indMe)->printFollowers();
	}

}

void  Facebook::print_All_FaceBook_Members_And_Pages()const noexcept(false)//10
{
	cout << "All Facebook users: " << endl;
	for (int i = 0; i < m_members.size(); i++)
	{
		m_members.at(i)->printMyDetails();
		cout << endl;
	}
	cout << "----------------------------" << endl;
	cout << endl;
	cout << "All Pages in Facebook: " << endl;
	for (int i = 0; i < m_pages.size(); i++)
	{
		m_pages.at(i)->printPage();
	}
}

void Facebook::UnlikePage()noexcept(false) //9
{
	int indMe = whoAreYou();
	if (m_members.at(indMe)->myNumOfPagesFollow() == 0)
	{
		cout << " you dont follow after any page" << endl;
		return;
	}
	m_members.at(indMe)->printPages();
	int pageInd = whichOne();
	if (pageInd < 0 && pageInd > m_members.at(indMe)->myNumOfPagesFollow())
		throw wrongInput();

	m_members.at(indMe)->removePage(pageInd);
}

void Facebook::LikeNewPage()noexcept(false) //8
{
	int ind = whoAreYou();
	cout << "choose a page you want to follow:" << endl;
	printPages();
	int pageInd = whichOne();
	if (pageInd < 0 && pageInd > m_pages.size())
		throw wrongInput();
	*m_members.at(ind) += *m_pages.at(pageInd);
}

void Facebook::RemoveFriend()noexcept(false) //7
{
	
	int indMe = whoAreYou();
	if (m_members.at(indMe)->myNumOfFriends() == 0)
		throw emptyFriendList();

	cout << "choose a friend to remove" << endl;
	m_members.at(indMe)->printFriends();
	int friendInd = whichOne();
	if (friendInd < 0 && friendInd > m_members.at(friendInd)->myNumOfFriends())
		throw wrongInput();

	m_members.at(indMe)->removeFriend(friendInd);
}

void Facebook::AddFriend()noexcept(false) //6
{
	int indMe = whoAreYou();
	cout << "choose a friend you want to add" << endl;
	printMembers();
	int friendToAdd = whichOne();
	if (friendToAdd < 0 && friendToAdd > m_members.size())
		throw wrongInput();
	
	*m_members.at(indMe) += *m_members.at(friendToAdd);
}

void Facebook::WhatIsMyfriend_Friends_Latest_Status() //5
{
	int member_index = whoAreYou();
	if (m_members.at(member_index)->myNumOfFriends() == 0)
		throw emptyFriendList();
	
	m_members.at(member_index)->printMyFriendLastStatuses();
}

void Facebook::SeeAllMyStatus()noexcept(false) //4
{
	int choose;
	int index;
	cout << "are you a page or a member? (choose 1 or 2)" << endl;
	cout << "1. I'm A page" << endl;
	cout << "2. I'm A member" << endl;

	cin >> choose;
	if (choose != 1 && choose != 2)
		throw wrongInput();

	if (choose == 1)
	{
		index = whichPage();
		m_pages.at(index)->printAllStatus();
	}

	else if (choose == 2)
	{
		index = whoAreYou();
		m_members.at(index)->printMyStatuses();
	}
}

void  Facebook::WriteNewStatus()noexcept(false) //3
{
	int choose;
	int index;
	char contant[MAX_STATUS_LENGTH];

	cout << "are you a page or a member? (choose 1 or 2)" << endl;
	cout << "1. I'm A page" << endl;
	cout << "2. I'm A member" << endl;
	cin >> choose;
	if (choose != 1 && choose != 2)
		throw wrongInput();
	
	if (choose == 2)
	{
		index = whoAreYou();
		cout << "what is on your mind? (no more then 1,000 letters)" << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.getline(contant, 1000);
		m_members.at(index)->createStatus(contant);
	}
	
	else if (choose == 1)
	{
		index = whichPage();
		cout << "what is on your mind? (no more then 1,000 letters)" << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.getline(contant, 1000);
		m_pages.at(index)->createStatus(contant);
	}
}

void Facebook::AddNewPage()noexcept(false) //2
{
	char name[MAX_NAME_LENGTH];
	cout << "What is the page name?" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.getline(name, MAX_NAME_LENGTH);
	page* newPage = new page(name);
	if (!newPage)
		throw badAlloc();
	addPage(newPage);
}

void Facebook::AddNewMember()noexcept(false) //1
{
	string name;
	char buffer[2];
	string date;

	int day, month, year;

	cout << "What is your name?" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, name);
	if (name.size() == 0)
		throw wrongInput();
	else if (isExsist(name) == false)
		throw friendExist();
	cout << "When have you burn? insert day:" << endl;
	cin >> day;
	if (day < 1 || day >30)
		throw wrongInput();
	cout << "insert month:" << endl;
	cin >> month;
	if (month < 1 || month >12)
		throw wrongInput();
	cout << "insert year:" << endl;
	cin >> year;
	if (year < 1)
		throw wrongInput();
	date += itoa(day, buffer, 10);
	date.push_back('/');
	date += itoa(month, buffer, 10);
	date.push_back('/');
	date += itoa(year, buffer, 10);
	member* newMember = new member(name, date);
	addMember(newMember);
}