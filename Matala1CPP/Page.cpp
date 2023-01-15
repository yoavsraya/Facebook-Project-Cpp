#include "page.h"
#include "Member.h"
#include "Exceptions.h"

page::page(string name)
{
	if (name.size() == EMPTY)
		throw emptyName();
	setName(name);
}




