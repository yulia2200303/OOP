#pragma once
#include "stdafx.h"
#include "Entry.h"

Entry::Entry(){
	this->lenght = 0;
	this->array = new Land*[lenght];
	this->size = 0;
}

Entry::Entry(int lenght){
	this->lenght = lenght;
	this->array = new Land*[lenght];
	this->size = 0;
	for (int i = 0; i < lenght; i++)
	{
		array[i] = NULL;
	}
}

Entry::Entry(Entry& entry)
{
	this->lenght = entry.lenght;
	this->size = entry.size;
	this->array = new Land*[lenght];
	for (int i = 0; i < size; i++)
	{
		array[i] = entry.array[i];
	}
}

void Entry::Add(Land* land){
	if (size < lenght)
	{
		array[size] = land;
		size++;
	}
}

void Entry::Show(){
	cout << "_______________________\n";
	for (int i = 0; i <= size; i++)
	{
		if (array[i] != NULL)
			array[i]->Print();
	}

}

void Entry::Insert(int index, Land* land){
	if (index < lenght && index >= 0)
	{
		array[index] = land;
		if (index > size)
			size = index;
	}
}

Land * Entry::GetByIndex(int index){
	if (index >= 0 && index <= size)
		return array[index];
	return NULL;
}

void Entry::RemoveByIndex(int index)
{
	if (index >= 0 && index <= size){
		for (int i = index; i <= size - 1; i++)
		{
			array[i] = array[i + 1];
		}
		if (index == size) array[index] = NULL;
	}
}

int Entry::GetSize(){
	return this->size;
}