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
	catch (exception& e)
	{
		cout << e.what();
		return 0;
	}
	program.runMenu(); // run facebook menu
	//program.WhoisBigger();
	program.~Facebook();
	cout << _CrtDumpMemoryLeaks();
	return 0;
}