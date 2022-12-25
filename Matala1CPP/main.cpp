#include "Data.h"
#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

int main()
{
	Facebook program; // main class
	program.starterFunc(); // set 3 friends and pages
	program.runMenu(); // run facebook menu
	/*program.~Facebook();
	cout << _CrtDumpMemoryLeaks();*/
	return 0;
}