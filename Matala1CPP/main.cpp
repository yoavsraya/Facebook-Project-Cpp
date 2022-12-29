#include "Data.h"
#include <iostream>
#include <stdlib.h>
#include <crtdbg.h>

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
	//program.WhoisBigger();
	program.~Facebook();
	cout << _CrtDumpMemoryLeaks();
	return 0;
}