// lab10.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>     
#include <iterator> 
#include <time.h>
#include <algorithm>
#include <iostream>
#include <set>
#include "Stack.h"

inline Stack Random()
{
	Stack * st = new Stack();
	for (int i = 0; i < 10; i++){
		st->Push(rand() % 10);
	}
	return *st;
}


int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");

	std::list<Stack> list;
	for (int i = 0; i < 8; i++)
		list.push_back(Random());

	std::cout << "Список: ";
	for (std::list<Stack>::iterator i = list.begin(); i != list.end(); i++)
	{
		std::cout << *i << " ";
	}

	std::list<Stack>::iterator it = list.begin();
	for (int i = 0; i < 3; i++){
		it = list.erase(it);
	}

	std::cout << "\nСписок после удаления: ";
	for (std::list<Stack>::iterator i = list.begin(); i != list.end(); i++)
	{
		std::cout << *i << " ";
	}

	Stack a = Random();
	Stack b(17);
	list.push_back(a);
	list.push_front(Random());
	list.insert(it, Random());
	it = list.begin();
	list.remove(Random());

	/*std::replace(list.begin(), list.end(), a, b);*/

	std::cout << "\nСписок после изменения: ";
	for (std::list<Stack>::iterator i = list.begin(); i != list.end(); i++)
	{
		std::cout << *i << " ";
	}


	std::set<Stack> set;
	for (int i = 0; i < 5; i++) {
		set.insert(Random());
	}

	Stack a1 = Random();
	Stack b1(16);
	set.insert(a1);
	set.insert(b1);

	std::cout << "\nМножество: ";
	for (std::set<Stack>::iterator i = set.begin(); i != set.end(); i++)
	{
		std::cout << *i << " ";
	}

	int index = list.size() / 2;
	it = list.begin();
	while (it != list.end() && index > 0){
		it = list.erase(it);
		index--;
	}


	for (std::set<Stack>::iterator i = set.begin(); i != set.end(); i++)
	{
		list.push_back(*i);
	}

	std::cout << "\nСписок после удаления и объединения: ";
	for (std::list<Stack>::iterator i = list.begin(); i != list.end(); i++)
	{
		std::cout << *i << " ";
	}

	return 0;
}

