// lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "land.h"
#include "sea.h"
#include "continent.h"
#include "island.h"
#include "counrty.h"


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "russian");
	cout << "Клвсс суша" << endl;
	Land *land1 = new Land(23.45, 2000);
	land1->SetPopulation(3000);
	land1->Print();

	const int seaSize = 3;
	Sea *seas = new Sea[seaSize]{
		*(new Sea(204.5, "Nover")),
		*(new Sea(25.67, "Poir")),
		*(new Sea(123.5, "Molbi"))
	};
	
	cout << "\nКласс континент: Land()" << endl;
	Continent *continent1 = new Continent(seas, seaSize, "Europe");
	continent1->Print();

	cout << "\nКласс континент: Land(square, population)" << endl;
	Continent *continent2 = new Continent(seas, seaSize, "America S", 123, 345.6);
	continent2->Print();

	cout << "\nКласс остров: Land()" << endl;
	Island *island1 = new Island(seas[1], 123.45, "Moimar");
	island1->Print();

	cout << "\nКласс остров: Land(square, population)" << endl;
	Island *island2 = new Island(seas[1], 123.45, "Rjof", 345, 12.456);
	island2->Print();

	cout << "\nКласс государство: Continent(), Island()  " << endl;
	Country *country1 = new Country("Belarus", "russian");
	country1->Print();

	cout << "\nКласс государство: Continent(), Island(square, population) " << endl;
	Country *country2 = new Country("Nor", "english", *island2);
	country2->Print();

	cout << "\nКласс государство: Continent(seas, square, name), Island()" << endl;
	Country *country3 = new Country("Mornom", "belarussian", *continent2);
	country3->Print();
	return 0;
}

