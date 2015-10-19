#pragma once
#include "stdafx.h"
#include "sea.h"


class Continent: public Land{
	Sea *seas;
	int lenght;
protected:
	string name;
public:
	Continent();
	Continent(Sea *seas, int lenght, string name);
	Continent(Continent& continent);
	Continent(Sea *seas, int lenght, string name, int population, double square);
	string GetName();
	Sea* GetSeas();
	int GetLenght();
	void SetName(string name);
	void PrintSeas();
	double GetSquare();
	void SetSquare(double square);
	int GetPopulation();
	void SetPopulation(int population);
	void Print();
	void add();
};