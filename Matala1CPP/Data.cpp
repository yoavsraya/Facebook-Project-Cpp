#include "data.h"

Facebook::Facebook()
{}

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
		cout << endl;
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

void Facebook::runMenu() //run the facebook manu until exit
{
	bool runningProgram = true;
	int select;
	while (runningProgram == true)
	{
		try
		{
			printMenu();
			cin >> select;
			switch (select)
			{
			case (12):
				runningProgram = false;
				WriteTofile();
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
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Wrong choice, choose again..." << endl;
				break;
			}
		}
		catch (wrongInput& e)
		{
			cout << e.what() << endl;
		}
		catch (userExist& e)
		{
			cout << e.what() << endl;
		}
		catch (badAlloc& e)
		{
			cout << e.what() << endl;
			runningProgram = false;
		}
		catch (friendExist& e)
		{
			cout << e.what() << endl;
		}
		catch (emptyFriendList& e)
		{
			cout << e.what() << endl;
		}
		catch (emptyFollowerList& e)
		{
			cout << e.what() << endl;
		}
		catch (emptyPageList& e)
		{
			cout << e.what() << endl;
		}
		catch (invalidDate& e)
		{
			cout << e.what() << endl;
		}
		catch (emptyName& e)
		{
			cout << e.what() << endl;
		}
		catch (emptyStatus& e)
		{
			cout << e.what() << endl;
		}
		catch (emptyStatusesList& e)
		{
			cout << e.what() << endl;
		}
		catch (alreadyFriends& e)
		{
			cout << e.what() << endl;
		}
		catch (AddYourSelf& e)
		{
			cout << e.what() << endl;
		}
		catch (alreadyfollow& e)
		{
			cout << e.what() << endl;
		}
	}
	cout << "Thanks you for using our FaceBook! hope to see you soon again :)" << endl;
}

void Facebook::printMenu()const //print manu option
{
	cout << "\nwhat would you like to do? (insert number from 1-12):" << endl;
	cout << "1 - Add New Member\n2 - Add New Page\n3 - Write New Status\n4 - See All My Status\n5 - What is My friend friends latest Status\n6 - Add friend\n7 - Remove Friend\n8 - Like New Page\n9 - Unlike Page\n10 - print All FaceBook Members And Pages\n11 - Watch My Friend/followers List\n12 - Exit" << endl << endl;
}

int Facebook::whoAreYou() // return the user index 
{
	int ind;
	if (m_members.size() == 0)
		throw Nomembers();
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

	cout << "are you page or member? enter 1 for member, 2 for page" << endl;
	cin >> choose1;
	if (choose1 == 1)
		indme = whoAreYou();
	else if (choose1 == 2)
		indme = whichPage();
	cout << "what do you want to compre with? choose 1 for member, 2 for page" << endl;
	cin >> choose2;
	if (choose2 == 1)
		indcompre = whichOne(m_members.size());
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

void Facebook::WriteTofile()
{
	fstream Data_file("Facbook_Data.txt",ios_base::app | ios_base::in);
	Data_file << m_members.size()<< endl;
	for (int i = 0; i < m_members.size(); i++)
	{
		Data_file << m_members.at(i)->getName() << endl;
		Data_file << m_members.at(i)->getDate() << endl;
	}
	Data_file << m_pages.size() << endl;
	for (int i = 0; i < m_pages.size(); i++)
	{
		Data_file << m_pages.at(i)->getName() << endl;
	}
	for (int i = 0; i < m_members.size(); i++)
	{
		m_members.at(i)->writeToFile(Data_file);
	}
	for (int i = 0; i < m_pages.size(); i++)
	{
		m_pages.at(i)->writeToFile(Data_file);
	}

	Data_file.close();
}

void Facebook::ReadFromFile()
{
	int numOfMember;
	int numOfPages;
	int numOfFriends;
	int friendIndex;
	int numOfPagefollow;
	int pageIndex;
	int numOfStatuses;
	int datatype;
	int index;
	char name[MAX_NAME_LENGTH];
	char DateOfBirth[SIZE_OF_DATE];
	char statustext[MAX_TEXT_LENGTH];
	char dataTypeName[MAX_NAME_LENGTH];
	time_t statustime;
	string Name;
	string Date;

	fstream Data_file("Facbook_Data.txt", ios_base::app | ios_base::in);
	if (Data_file.peek() == std::ifstream::traits_type::eof())
	{
		return;
	}

	Data_file >> numOfMember;
	m_members.reserve(numOfMember);

	Data_file.get();
	for (int i = 0; i < numOfMember; i++)
	{
		Data_file.getline(name, MAX_NAME_LENGTH);
		Data_file.getline(DateOfBirth, SIZE_OF_DATE);
		Name = name;
		Date = DateOfBirth;
		createMemberFromFile(Name, Date);
	}
	Data_file >> numOfPages;
	m_pages.reserve(numOfPages);

	Data_file.get();
	for (int i = 0; i < numOfPages; i++)
	{
		Data_file.getline(name, MAX_NAME_LENGTH);
		createPageFromFile(name);
	}
	
	for (int i = 0; i < numOfMember; i++)
	{
		Data_file >> index;
		Data_file >> numOfFriends;
		for (int j = 0; j < numOfFriends; j++)
		{
			Data_file >> friendIndex;
			*m_members.at(index) += *m_members.at(friendIndex);
		}

		Data_file >> numOfPagefollow;
		for (int j = 0; j < numOfPagefollow; j++)
		{
			Data_file >> pageIndex;
			*m_members.at(i) += *m_pages.at(pageIndex);
		}

		Data_file >> numOfStatuses;
		for (int j = 0; j < numOfStatuses; j++)
		{
			Data_file >> datatype;
			Data_file.get();
			Data_file.getline(statustext, MAX_TEXT_LENGTH);
			Data_file >> statustime;
			if (datatype != 0)
			{
				Data_file.get();
				Data_file.getline(dataTypeName, MAX_NAME_LENGTH);
				m_members.at(i)->createStatusFromFile(statustext, statustime, datatype, dataTypeName);
			}
			m_members.at(i)->createStatusFromFile(statustext, statustime, datatype, dataTypeName);
		}
	}
	for (int i = 0; i < numOfPages; i++)
	{
		Data_file >> index;
		Data_file >> numOfFriends;
		for (int j = 0; j < numOfFriends; j++)
		{
			Data_file >> friendIndex;
			m_pages.at(index)->addFollower(m_members.at(friendIndex));
		}
		Data_file >> numOfStatuses;

		for (int j = 0; j < numOfStatuses; j++)
		{
			Data_file >> datatype;
			Data_file.get();
			Data_file.getline(statustext, MAX_TEXT_LENGTH);
			Data_file >> statustime;
			if (datatype != 0)
			{
				Data_file.get();
				Data_file.getline(dataTypeName, MAX_NAME_LENGTH);
				m_pages.at(i)->createStatusFromFile(statustext, statustime, datatype, dataTypeName);
			}
			m_pages.at(i)->createStatusFromFile(statustext, statustime, datatype, dataTypeName);
		}

	}
	Data_file.close();
}

void Facebook::createMemberFromFile(string name, string date)
{
	member* newMember;
		try
		{
			newMember = new member(name, date);
		}
		catch (bad_alloc& e)
		{
			throw badAlloc();
		}
		addMember(newMember);
}

void Facebook::createPageFromFile(char* name)
{
	page* newPage;
	try
	{
		newPage = new page(name);
	}

	catch (bad_alloc& e)
	{
		throw badAlloc();
	}
	addPage(newPage);
}

int Facebook::whichOne(int size) //ask the user to choose one 
{
	cout << "choose One:" << endl;
	int res;
	cin >> res;
	if (res<1 || res>size)
		throw wrongInput();
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
	if (choose != 1 && choose != 2)
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
	int pageInd = whichOne(m_members.at(indMe)->myNumOfPagesFollow());
	if (pageInd < 0 || pageInd > m_members.at(indMe)->myNumOfPagesFollow())
		throw wrongInput();

	m_members.at(indMe)->removePage(pageInd);
}

void Facebook::LikeNewPage()noexcept(false) //8
{
	int ind = whoAreYou();
	cout << "choose a page you want to follow:" << endl;
	printPages();
	int pageInd = whichOne(m_pages.size());
	if (pageInd < 0 && pageInd > m_pages.size())
		throw wrongInput();
	if (m_members.at(ind)->isPageExist(m_pages.at(pageInd)) == true);
	throw alreadyfollow();
	*m_members.at(ind) += *m_pages.at(pageInd);
}

void Facebook::RemoveFriend()noexcept(false) //7
{

	int indMe = whoAreYou();
	if (m_members.at(indMe)->myNumOfFriends() == 0)
		throw emptyFriendList();
	if (indMe < 1 || indMe > m_members.size())
		throw wrongInput();
	cout << "choose a friend to remove" << endl;
	m_members.at(indMe)->printFriends();
	int friendInd = whichOne(m_members.at(indMe)->myNumOfFriends());
	if (friendInd < 0 || friendInd > m_members.at(indMe)->myNumOfFriends())
		throw wrongInput();
	member* Friend = m_members.at(indMe)->friendIndex(friendInd);
	m_members.at(indMe)->removeFriend(Friend);
	Friend->removeFriend(m_members.at(indMe));
}

void Facebook::AddFriend()noexcept(false) //6
{
	int indMe = whoAreYou();
	cout << "choose a friend you want to add" << endl;
	printMembers();
	int friendToAdd = whichOne(m_members.size());
	if (indMe == friendToAdd)
	{
		throw AddYourSelf();
	}
	if (m_members.at(indMe)->isFriendExist(m_members.at(friendToAdd)) == true)
	{
		throw alreadyFriends();
	}

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
	string contant;
	int StatusType;
	string DataName;

	cout << "are you a page or a member? (choose 1 or 2)" << endl;
	cout << "1. I'm A page" << endl;
	cout << "2. I'm A member" << endl;
	cin >> choose;
	if (choose != 1 && choose != 2)
		throw wrongInput();

	if (choose == 2)
	{
		index = whoAreYou();
		cout << "which kind of status do you want?" << endl;
		cout << "1. text" << endl << "2. for video" << endl << "3. for image" << endl;
		cin >> StatusType;
		if (StatusType != 1)
		{
			cout << "enter video/image name: (no more then 50 characters)" << endl;
			clearBuffer();
			getline(cin, DataName);
		}
		cout << "what is on your mind? (no more then 1,000 letters)" << endl;
		clearBuffer();
		getline(cin, contant);
		if (contant.size() == 0)
			throw emptyStatus();
		m_members.at(index)->createStatus(contant,StatusType,DataName);
	}

	else if (choose == 1)
	{
		index = whichPage();
		cout << "which kind of status do you want?" << endl;
		cout << "1. text" << endl << "2. for video" << endl << "3. for image" << endl;
		cin >> StatusType;
		if (StatusType != 1)
		{
			cout << "enter video/image name: (no more then 50 characters)" << endl;
			clearBuffer();
			getline(cin, DataName);
		}
		cout << "what is on your mind? (no more then 1,000 letters)" << endl;
		clearBuffer();
		getline(cin, contant);
		if (contant.size() == 0)
			throw emptyStatus();
		m_pages.at(index)->createStatus(contant,StatusType,DataName);
	}
}

void Facebook::AddNewPage()noexcept(false) //2
{
	string name;
	page* newPage;
	cout << "What is the page name?" << endl;
	clearBuffer();
	getline(cin, name);
	if (name.size() == 0)
		throw emptyName();
	try
	{
		newPage = new page(name);
	}

	catch (bad_alloc& e)
	{
		throw badAlloc();
	}
	addPage(newPage);
}

void Facebook::AddNewMember()noexcept(false) //1
{
	string name;
	char buffer[33];
	string date;

	int day, month, year;

	cout << "What is your name?" << endl;
	clearBuffer();
	getline(cin, name);
	if (name.size() == 0)
		throw emptyName();
	else if (isExsist(name) == false)
		throw userExist();
	cout << "When have you burn? insert day:" << endl;
	cin >> day;
	if (day < MIN_DAY_IN_MONTH || day > MAX_DAY_IN_MONTH)
		throw invalidDate();
	cout << "insert month:" << endl;
	cin >> month;
	if (month < MIN_MONTH_IN_YEAR || month > MAX_MONTH_IN_YEAR)
		throw invalidDate();
	cout << "insert year:" << endl;
	cin >> year;
	if (year < THE_YEAR_JESUS_BORN)
		throw invalidDate();
	date += itoa(day, buffer, DECIMAL);
	date.push_back('/');
	date += itoa(month, buffer, DECIMAL);
	date.push_back('/');
	date += itoa(year, buffer, DECIMAL);
	member* newMember;
	try
	{
		newMember = new member(name, date);
	}
	catch (bad_alloc& e)
	{
		throw badAlloc();
	}
	addMember(newMember);
}