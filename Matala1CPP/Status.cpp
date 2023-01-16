#include "Status.h"


status::status(const string content) noexcept(false)
{
	m_content = content;
	if (m_content.size() == EMPTY)
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


void status::printContent()const noexcept(false) //print status
{
	if (m_content.size() == EMPTY)
		throw emptyStatus();
	
	cout << m_content << endl;
	cout << "upload time and date: " << ctime(&dateAndtimeOfStatus) << endl;
	cout << "------------------------------" << endl;
}