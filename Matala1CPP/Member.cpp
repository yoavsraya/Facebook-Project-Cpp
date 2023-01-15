#include "Member.h"
#include "Page.h"


object& member::operator+=(object& _object)
{
	this->addFollower(&_object);
	_object.addFollower(this);
	return *this;
}

member::member(const string name, const string birthDate) //ct'or
{
	if (name.size() == EMPTY)
		throw wrongInput();
	setName(name);
	m_dateOfBirth = birthDate;
}

void member::updatelastStatuses(status* _status) //update the 10 last statuses
{
	if (m_logSize10Statuses == FULL)
	{
		for (int i = 9; i > EMPTY; i--)
		{
			m_last10statuses[i] = m_last10statuses[i - 1];
		}
		m_last10statuses[0] = _status;
	}
	else
	{
		m_last10statuses[m_logSize10Statuses] = _status;
		m_logSize10Statuses--;
	}
}

void member::print10lastStatuses() // print last 10 statuses
{
	cout << "the last 10 statuses of " << getName() << " is:" << endl;

	for (int i = 9; i > m_logSize10Statuses; i--)
	{
		m_last10statuses[i]->printContent();
	}
}

void member::setBirth(const char* birth)
{
	m_dateOfBirth = birth;
}




