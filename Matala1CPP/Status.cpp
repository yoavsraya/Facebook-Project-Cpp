#include "Status.h"


status::status(const char* content)
{
	m_content = _strdup(content);
	time(&dateAndtimeOfStatus);
}

status::status(const status& other)
{
	m_content = other.m_content;
	time_t dateAndtimeOfStatus = other.dateAndtimeOfStatus;
}

void status::getContent(const char* content) //get contant to status
{
	m_content = strdup(content);
	time(&dateAndtimeOfStatus);
}


void status::printStatus()const //print status
{
	cout << m_content << endl;
	cout << "upload time and date: " << ctime(&dateAndtimeOfStatus) << endl;
	cout << "------------------------------" << endl;
}