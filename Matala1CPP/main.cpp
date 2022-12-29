#include "Data.h"
#include <iostream>

using namespace std;

int main()
{
	Facebook program; // main class
	try
	{
	program.starterFunc(); // set 3 friends and pages
	}
	catch (wrongInput& e)
	{
		cout << e.what();
	}
	catch (badAlloc& e)
	{
		cout << e.what();
	}
	program.runMenu(); // run facebook menu
	return 0;
}