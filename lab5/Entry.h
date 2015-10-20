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
	Land* GetByIndex(int index);//������� ������� �� �������
	void RemoveByIndex(int index);//�������� �������� �� ������ � ��
	void Show();
	int GetSize();
};