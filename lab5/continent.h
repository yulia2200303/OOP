#pragma once
#include "stdafx.h"
#include "sea.h"
#include "counrty.h"


class Continent: public Land{
	Sea *seas;
	int seaLenght;
	Country *countries;
	int countryLenght;
	
protected:
	string name;
public:
	Continent();
	Continent(Sea *seas, int sealenght, string name, Country *countries, int countryLenght);
	Continent(Continent& continent);
	Continent(Sea *seas, int sealenght, string name, int population, double square, Country *countries, int countryLenght);
	string GetName();
	Sea* GetSeas();
	Country* GetCountries();
	int GetLenght();
	void SetName(string name);
	void PrintSeas();
	void PrintCountries();
	double GetSquare();
	void SetSquare(double square);
	int GetPopulation();
	void SetPopulation(int population);
	int GetSeaLenght();
	int GetCountryLenght();
	void Print();

};