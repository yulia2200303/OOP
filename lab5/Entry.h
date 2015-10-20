#pragma once
#include "Land.h"

class Entry {
	Land** array;
	int lenght;
	int size;
public:
	Entry();
	Entry(int lenght);
	Entry(Entry& entry);
	void Add(Land* land);
	void Insert(int index, Land* land);
	Land* GetByIndex(int index);//вернуть элемент по индексу
	void RemoveByIndex(int index);//удаление элемента из списка и сд
	void Show();
	int GetSize();
};