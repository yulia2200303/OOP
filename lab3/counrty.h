#include "stdafx.h"

class Country : public Island, public Continent{
	string name;
	string nationalLanguage;
public:
	Country();
	Country(string name, string nationalLanguage);
	Country(const Country& country);
	Country(string name, string nationalLanguage, Island island);
	Country(string name, string nationalLanguage, Continent continent);
	string GetName();
	string GetNationalLanguage();
	void SetName(string name);
	void SetNationalLanguage(string nationalLanguage);
	void Print();

};