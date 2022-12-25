#pragma once
#include <iostream>
#include "Member.h"
#include "Page.h"
#pragma warning(disable: 4996)
using namespace std;

member** ourRealloc(const int oldSize, const int newSize, member** arr);
page** ourRealloc(const int oldSize, const int newSize, page** arr);
status** ourRealloc(const int oldSize, const int newSize, status** arr);
page* ourRealloc(const int oldSize, const int newSize, page* arr);
member* ourRealloc(const int oldSize, const int newSize, member* arr);