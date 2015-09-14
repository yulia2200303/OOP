// OOP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "russian");
	Triangle *tr1 = new Triangle();
	tr1->Print();
	Triangle *tr2 = new Triangle(Point(1, 2), Point{ 2, 6 }, Point{ 0, 0 });
	tr2->Print();
	tr2->GetPoint(-4);
	tr2->Print();
	cout << "периметр" << tr2->GetPerimeter()<<endl;
	cout << "длина стороны АВ" << Triangle::GetSide(tr2->GetPointA(), tr2->GetPointB()) << endl;
	Triangle *tr3 = new Triangle(*tr2);
	tr3->Print();
	Triangle *tr4 = new Triangle(Point(0, 0), Point{ 3, 3 }, Point{ 6, 0 });
	cout <<"равнобедренный? "<<tr4->IsIsosceles() << endl;
	Triangle *tr5 = new Triangle(Point(0, 0), Point{ 0, 3 }, Point{ 100, 1 });
	cout <<"прямоугольный? "<< tr5->IsRectangular() << endl;
	Triangle *tr6 = new Triangle(Point(0, 0), Point{ 0.5, sqrt(3) / 2 }, Point{ 1, 0 });
	cout <<"равносторонний? "<< tr6->IsEquilateral() << endl;
	Triangle *tr7 = new Triangle(Point(0, 0), Point{ 0.5, 0.6 }, Point{ 1, 0.5 });
	cout <<"произвольный? "<< tr7->IsArbitrary() << endl;

	delete tr1;
	delete tr2;
	delete tr3;

	const int size = 10;
	Triangle *arr = new Triangle[size]{
			*(new Triangle(Point(0, 8), Point(3, 5), Point(6, 2))),
			*(new Triangle(Point(1, 8), Point(3, 4), Point(6, 2))),
			*(new Triangle(Point(0, 0), Point(0.5, sqrt(3) / 2), Point(1,0))),
			*(new Triangle(Point(0, 8), Point(3, 5), Point(6, 2))),
			*(new Triangle(Point(0, 0), Point(0.5, 0.6), Point(1, 0.5))),
			*(new Triangle(Point(10,10), Point(20, 20), Point(30, 10))),
			*(new Triangle(Point(10, 8), Point(6, 5), Point(6, 0))),
			*(new Triangle(Point(4, 8), Point(2, 2), Point(7, 4))),
			*(new Triangle(Point(7, 8), Point(3, 3), Point(0, 2))),
			*(new Triangle(Point(4, 0), Point(6, 3), Point(8, 0)))
	};
	DisplayType(arr, size);
	DisplayMinMaxPerimeter(arr, size);
	delete[] arr;
	return 0;
}

