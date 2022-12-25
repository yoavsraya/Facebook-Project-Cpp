#include "generalFun.h"
using namespace std;

//realloc

member** ourRealloc(const int oldSize, const int newSize, member** arr)
{
	member** newArr = new member * [newSize];

	for (int i = 0; i < oldSize; i++)
	{
		 newArr[i] = arr[i];
	}

	delete []arr;

	return newArr;
}

page** ourRealloc(const int oldSize, const int newSize, page** arr)
{
	page** newArr = new page * [newSize];

	for (int i = 0; i < oldSize; i++)
	{
		newArr[i] = arr[i];
	}

	delete[] arr;

	return newArr;
}

status** ourRealloc(const int oldSize, const int newSize, status** arr)
{
	status** newArr = new status*[newSize];

	for (int i = 0; i < oldSize; i++)
	{
		newArr[i] = arr[i];
	}

	delete[] arr;

	return newArr;
}

page* ourRealloc(const int oldSize, const int newSize, page* arr)
{
	page* newArr = new page[newSize];

	for (int i = 0; i < oldSize; i++)
	{
		newArr[i] = arr[i];
	}

	delete[] arr;

	return newArr;
}

member* ourRealloc(const int oldSize, const int newSize, member* arr)
{
	member* newArr = new member[newSize];

	for (int i = 0; i < oldSize; i++)
	{
		newArr[i] = arr[i];
	}

	delete[] arr;

	return newArr;
}