#include "stdafx.h"
#include <iostream> 
#include "LinkList.h"

using namespace std;

int main()
{
	list myList;
	add(&myList, 10);
	add(&myList, 15);
	add(&myList, 20);
	add(&myList, 25);
	//print(&myList);
	add(&myList, 7,0);
	add(&myList, 9, 4);
	//print(&myList);
	remove(&myList, 1);
	print(&myList);
	//cout << search(&myList, 10);
	system("pause");
    return 0;
}

