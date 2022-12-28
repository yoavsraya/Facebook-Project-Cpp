#include "Status.h"


status::status(const char* content)
{
	m_content = content;
	if (m_content.size() == 0)
		throw emptyStatus();
	time(&dateAndtimeOfStatus);
}

status::status(const status& other)
{
	m_content = other.m_content;
	time_t dateAndtimeOfStatus = other.dateAndtimeOfStatus;
}

bool status::operator==(const status& other) const
{
	if (m_content == other.m_content)
		return true;
	return false;
}

bool status::operator!=(const status& other) const
{
	if (m_content != other.m_content)
		return true;
	return false;
}

status& status::operator=(const string str)
{
	m_content = str;
	time(&dateAndtimeOfStatus);
	return *this;
}

status& status::operator=(const char* str)
{
	m_content = str;
	time(&dateAndtimeOfStatus);
	return *this;
}

void status::printStatus()const //print status
{
	if (m_content.size() == 0)
		throw "you tried to enter an empty status...";
	cout << m_content << endl;
	cout << "upload time and date: " << ctime(&dateAndtimeOfStatus) << endl;
	cout << "------------------------------" << endl;
}