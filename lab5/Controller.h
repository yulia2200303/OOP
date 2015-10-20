#pragma once
#include "stdafx.h"
#include "Entry.h"

class Controller {
	Entry *entry;
public: 
	Controller(int size);
	Controller(Entry* entry);
	void PrintAllCountries();
	void PrintCountOfSeas();
	void PrintIsland();
};