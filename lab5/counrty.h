#pragma once
#include "stdafx.h"

class Country {
	string name;
	string nationalLanguage;
public:
	Country();
	Country(string name, string nationalLanguage);
	Country(const Country& country);
	string GetName();
	string GetNationalLanguage();
	void SetName(string name);
	void SetNationalLanguage(string nationalLanguage);
	void Print();

};