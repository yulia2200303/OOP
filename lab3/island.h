#include "stdafx.h"


class Island: public Land{
	Sea sea;
	double remoteness;
protected:
	string name;
public:
	Island();
	Island(Sea sea, double remoteness, string name);
	Island(const Island& island);
	Island(Sea sea, double remoteness, string name, int population, double square);
	Sea GetSea();
	double GetRemoteness();
	string GetName();
	void SetSea(Sea sea);
	void SetRemoteness(double remoteness);
	void SetName(string name);
	void Print();
};