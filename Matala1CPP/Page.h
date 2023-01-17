#pragma once
#include "Status.h"
#include <vector>
#include <string>
#pragma warning(disable: 4996)
class member;

class page
{
	string m_name;
	vector <member*> m_ListOFfollowers;
	vector <status*> m_board;
	int index;
	static int NumOfPages;

public:
	page() {index = NumOfPages; NumOfPages++;} //empty ct'or
	page(const string name); //ct'or
	~page(); //d'tor
	bool operator>(const page& _page)const; //oprator > Q2
	bool operator>(const member& _member)const; //oprator > Q2
	int findFollowerInd(member* const follower)const; //return member index
	int myNumOfFollowers() const; // return num of follwers
	void addFollower(member* const follower); //add new follower
	void removeFollower(member* follower); //remove follower
	void createStatus(const string content, int index, string dataName); //create status from string
	void printAllStatus()const; //print all statuses of page
	void printPage()const; //print page
	void printFollowers()const;	// print follower
	int getPageindex() { return index; } //get page index 
	string getName() { return m_name; } // get name
	void writeToFile(fstream& file); //write page to file 
	void createStatusFromFile(string contant, time_t time, int type, string datatype); // create new status 
};


