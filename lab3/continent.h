#include "stdafx.h"


class Continent: public Land{
	Sea *seas;
	int lenght;
protected:
	string name;
public:
	Continent();
	Continent(Sea *seas, int lenght, string name);
	Continent(const Continent& continent);
	Continent(Sea *seas, int lenght, string name, int population, double square);
	string GetName();
	Sea* GetSeas();
	int GetLenght();
	void SetName(string name);
	void PrintSeas();
	void Print();
};