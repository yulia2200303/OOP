// lab4.cpp : Defines the entry point for the console application.
//

#pragma once
#include "stdafx.h"
#include "Land.h"
#include "continent.h"
#include "sea.h"
#include "island.h"

Land* Land::head = NULL;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	const int seaSize = 3;
	Sea *seas = new Sea[seaSize]{
		*(new Sea(204.5, "Nover")),
		*(new Sea(25.67, "Poir")),
		*(new Sea(123.5, "Molbi"))
	};

	Land *L = new Continent(seas, seaSize, "ERdfns", 1234, 325.5 );

	Land *L2 = new Island(seas[1], 345.6, "hyu", 43, 567.7);

	Land::Show();
	return 0;
}

