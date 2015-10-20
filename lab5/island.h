#pragma once
#include "stdafx.h"
#include "Land.h"
#include "sea.h"


class Island: public Land{
	Sea sea;
	double remoteness;
protected:
	string name;
public:
	Island();
	Island(Sea sea, double remoteness, string name);
	Island(Island& island);
	Island(Sea sea, double remoteness, string name, int population, double square);
	Sea GetSea();
	double GetRemoteness();
	string GetName();
	void SetSea(Sea sea);
	void SetRemoteness(double remoteness);
	void SetName(string name);
	double GetSquare();
	void SetSquare(double square);
	int GetPopulation();
	void SetPopulation(int population);
	void Print();
	void PrintSea();
};