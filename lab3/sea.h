#include "stdafx.h"

class Sea{
	double square;
	string name;
public:
	Sea();
	Sea(double square, string name);
	Sea(const Sea& sea);
	double GetSquare();
	string GetName();
	void SetSquare(double square);
	void SetName(string name);
	void Print();
};