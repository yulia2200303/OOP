#pragma once
#include "stdafx.h"
#include "Entry.h"
#include "Controller.h"
#include "continent.h"
#include "island.h"

Controller::Controller(int size){
	this->entry = new Entry(size);
}

Controller::Controller(Entry* entry){
	this->entry = entry;
}

void Controller::PrintAllCountries(){
	for (int i = 0; i <= entry->GetSize(); i++)
	{
		Land* l = entry->GetByIndex(i);
		if (l == NULL)
		{
			continue;
		}
		Continent *c = dynamic_cast<Continent*>(l);
		if (c){
			c->PrintCountries();
		}
	}
}

void Controller::PrintCountOfSeas()
{
	int seasCount = 0;
	for (int i = 0; i <= entry->GetSize(); i++)
	{
		Land *l = entry->GetByIndex(i);
		if (l == NULL) continue;

		Continent *c = dynamic_cast<Continent*>(l);
		if (c)
		{
			seasCount += c->GetSeaLenght();
		}
		else{
			Island *is = dynamic_cast<Island*>(l);
			if (is)
			{
				seasCount++;
			}
		}
	}

	cout << "Count of Seas: " << seasCount << endl;
}


void Controller::PrintIsland()
{
	Island **arr = new Island*[100];
	int size = 0;

	for (int i = 0; i <= entry->GetSize(); i++)
	{
		Land *l = entry->GetByIndex(i);
		if (l == NULL) continue;
		Island *is = dynamic_cast<Island*>(l);
		if (is)
		{
			arr[size++] = is;
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (strcmp(arr[j]->GetName().c_str(), arr[j + 1]->GetName().c_str()) > 0)
			{
				Island* tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < size; i++)
		arr[i]->Print();
}