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

status& status::operator=(const char* str)
{
	m_content = str;
	time(&dateAndtimeOfStatus);
	return *this;
}

void status::printStatus()const //print status
{
	cout << m_content << endl;
	cout << "upload time and date: " << ctime(&dateAndtimeOfStatus) << endl;
	cout << "------------------------------" << endl;
}