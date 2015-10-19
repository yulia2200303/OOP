#pragma once
#include "stdafx.h"

class Land{
protected:
	double square;
	int population;
	static Land *head;
	

public:
	virtual void add() = 0;
	virtual double GetSquare()=0;
	virtual void SetSquare( double square)=0;
	virtual int GetPopulation() = 0;
	virtual void SetPopulation(int population) = 0;
	virtual void Print()=0;
	Land *next;
	virtual ~Land() {}

	static void Show()
	{
		int i = 1;
		Land *p = head;
		while (p)
		{
			std::cout<<"\n"<< i << " элемент списка: \n";
			p->Print();
			p = p->next;
			i++;
		}
	}
};

