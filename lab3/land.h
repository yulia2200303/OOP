#include "stdafx.h"

class Land{
protected:
	double square;
	int population;

public:
	double GetSquare();
	void SetSquare( double square);
	int GetPopulation();
	void SetPopulation(int population);
	virtual void Print(){
		cout << "�������: " << this->square << endl;
		cout << "���������: " << this->population << endl;
	};
	Land();
	Land(double square, int population);
	Land(const Land& land);
};

