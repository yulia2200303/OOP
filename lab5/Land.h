#pragma once
#include "stdafx.h"

class Land{
protected:
	double square;
	int population;

	

public:

	virtual double GetSquare()=0;
	virtual void SetSquare( double square)=0;
	virtual int GetPopulation() = 0;
	virtual void SetPopulation(int population) = 0;
	virtual void Print()=0;

	virtual ~Land() {}

};

