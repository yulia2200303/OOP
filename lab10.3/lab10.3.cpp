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
	const int size = 5;
	Stack * st = new Stack(size);
	for (int i = 0; i < size; i++){
		st->Push(rand() % 10);
	}
	return *st;
}

bool IsContainZero(Stack st){
	Stack copy = st;
	while (!copy.IsEmpty())
	{
		if (copy.Pop() == 0) return true;
	}
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");

	std::list<Stack> list;
	for (int i = 0; i < 8; i++)
		list.push_back(Random());

	std::cout << "������: ";
	for (std::list<Stack>::iterator i = list.begin(); i != list.end(); i++)
	{
		std::cout << *i << " ";
	}

	list.sort();
	std::cout << "������������� �� ����� ��������� �����: " << "\n";
	for (std::list<Stack>::iterator i = list.begin(); i != list.end(); i++)
	{
		std::cout << *i << " ";
	}

	list.reverse();
	std::cout << "������������� �� ����� ��������� ����� (� �������� �������): " << "\n";
	for (std::list<Stack>::iterator i = list.begin(); i != list.end(); i++)
	{
		std::cout << *i << " ";
	}

	std::list<Stack>::iterator findedIt = std::find_if(list.begin(), list.end(), IsContainZero);

	std::cout << "���� � ������� ���� ������� �������: ";
	if (findedIt != list.end()){
		std::cout << *findedIt;
	}
	else{
		std::cout << "������� �� ������";
	}


	std::set<Stack> set;
	std::copy_if(list.begin(), list.end(), std::inserter(set, set.begin()), IsContainZero);
	std::cout << "\n����������� �� ������ � ��������� ���� ������, � ������ ���� ������� 0: ";
	for (std::set<Stack>::iterator i = set.begin(); i != set.end(); i++)
	{
		std::cout << *i << " ";
	}

	std::set<Stack> set2;
	for (int i = 0; i < 5; i++)
		set2.insert(Random());

	std::cout << "�������� ������� ���������: ";
	for (std::set<Stack>::iterator i = set2.begin(); i != set2.end(); i++)
	{
		std::cout << *i << " ";
	}

	list.sort();
	std::set<Stack> set3;
	std::merge(list.begin(), list.end(), set2.begin(), set2.end(), std::inserter(set2, set2.begin()));
	std::cout << "��������� ������� ������� ������ � ������� ���������: ";
	for (std::set<Stack>::iterator i = set2.begin(); i != set2.end(); i++)
	{
		std::cout << *i << " ";
	}

	std::cout << "���������� ������ � ���������, ����������� 0 �������: ";
	std::cout << std::count_if(set2.begin(), set2.end(), IsContainZero) << "\n\n";

	return 0;
}

