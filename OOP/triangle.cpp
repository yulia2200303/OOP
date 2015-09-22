#include "stdafx.h"

Triangle::Triangle()
{
	cout << "конструктор без параметров" << endl;
}

Triangle::Triangle(Point a, Point b, Point c)
{
	this->a_ = a;
	this->b_ = b;
	this->c_ = c;
	cout << "конструктор с параметрами" << endl;
}

Triangle::Triangle(const Triangle &tr)
{
	this->a_ = tr.a_;
	this->b_ = tr.b_;
	this->c_ = tr.c_;
	cout << "конструктор копирования" << endl;
}

Triangle::~Triangle()
{
	cout << "деструктор" << endl;
}

void Triangle::Print()
{
	cout << "A (" << this->a_.x << ", " << this->a_.y << ");" << endl;
	cout << "В (" << this->b_.x << ", " << this->b_.y << ");" << endl;
	cout << "С (" << this->c_.x << ", " << this->c_.y << ");" << endl;
}

Point Triangle::GetPointA()
{
	return this->a_;
}

Point Triangle::GetPointB()
{
	return this->b_;
}

Point Triangle::GetPointC()
{
	return this->c_;
}

Point Triangle::GetPoint(int i)
{
	int q = abs(i) % 3;
	if (q == 1)
		return GetPointA();
	else if (q == 2)
		return GetPointB();
	else return GetPointC();
}

void Triangle::SetPointA(Point point)
{
	this->a_ = point;
}

void Triangle::SetPointB(Point point)
{
	this->b_ = point;
}

void Triangle::SetPointC(Point point)
{
	this->c_ = point;
}

void Triangle::SetPoint(int i, Point point)
{
	int q = abs(i) % 3;
	if (q == 1)
		return SetPointA(point);
	else if (q == 2)
		return SetPointB(point);
	else return SetPointC(point);
}

double Triangle::GetSide(Point a, Point b)
{
	return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

bool Triangle::IsIsosceles()
{
	double ab = GetSide(GetPointA(), GetPointB()), bc = GetSide(GetPointB(), GetPointC()), ac = GetSide(GetPointA(), GetPointC());
	return abs(ab - bc) < 0.00001 || abs(ab - ac) < 0.00001 || abs(bc - ac) < 0.00001;
}

bool Triangle::IsRectangular()
{
	double ab = GetSide(GetPointA(), GetPointB()), bc = GetSide(GetPointB(), GetPointC()), ac = GetSide(GetPointA(), GetPointC());
	return abs(pow(ab, 2) + pow(ac, 2) - pow(bc, 2)) < 0.00001 || abs(pow(ab, 2) + pow(bc, 2) - pow(ac, 2)) < 0.00001 || abs(pow(ac, 2) + pow(bc, 2) - pow(ab, 2)) < 0.00001;
}

bool Triangle::IsEquilateral()
{
	double ab = GetSide(GetPointA(), GetPointB()), bc = GetSide(GetPointB(), GetPointC()), ac = GetSide(GetPointA(), GetPointC());
	return abs(ab - bc) < 0.00001 && abs(ab - ac) < 0.00001 && abs(bc - ac) < 0.00001;
}

bool Triangle::IsArbitrary(){
	return !(IsIsosceles() || IsEquilateral() || IsRectangular());
}

double Triangle::GetPerimeter()
{
	return GetSide(GetPointA(), GetPointB()) + GetSide(GetPointB(), GetPointC()) + GetSide(GetPointA(), GetPointC());
}

void DisplayType(Triangle *arr, int size)
{
	int isoscelesCount = 0, rectangularCount = 0, equilateralCount = 0, arbitraryCount = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].IsEquilateral()) 
			equilateralCount++;
		if (arr[i].IsIsosceles())
			isoscelesCount++;
		if (arr[i].IsRectangular())
			rectangularCount++;
		if (arr[i].IsArbitrary())
			arbitraryCount++;
	}
	cout << "Количество равносторонних - " << equilateralCount << "\nКоличество равнобедренных -  " << isoscelesCount << "\nКоличество прямоугольных - " << rectangularCount << "\nКоличество разнообразных - " << arbitraryCount << endl;
}

void DisplayMinMaxPerimeter(Triangle *arr, int size)
{
	double isoscelesMin = DBL_MAX, rectangularMin = DBL_MAX, equilateralMin = DBL_MAX, arbitraryMin = DBL_MAX, isoscelesMax = DBL_MIN, rectangularMax = DBL_MIN, equilateralMax = DBL_MIN, arbitraryMax = DBL_MIN;
	for (int i = 0; i < size; i++)
	{
		double perimeter = arr[i].GetPerimeter();
		if (arr[i].IsEquilateral()){
			if (perimeter < equilateralMin)
				equilateralMin = perimeter;
			if (perimeter > equilateralMax)
				equilateralMax = perimeter;
		}
		if (arr[i].IsIsosceles())
		{
			if (perimeter < isoscelesMin)
				isoscelesMin = perimeter;
			if (perimeter > isoscelesMax)
				isoscelesMax = perimeter;
		}
		if (arr[i].IsRectangular())
		{
			if (perimeter < rectangularMin)
				rectangularMin = perimeter;
			if (perimeter > rectangularMax)
				rectangularMax = perimeter;
		}
		if (arr[i].IsArbitrary())
		{
			if (perimeter < arbitraryMin)
				arbitraryMin = perimeter;
			if (perimeter > arbitraryMax)
				arbitraryMax = perimeter;
		}
	}
	cout << "Минимальный периметр равностороннего треугольника - " << equilateralMin << "\nМаксимальный периметр равностороннего треугольника - " << equilateralMax << endl;
	cout << "Минимальный периметр равнобедренного треугольника - " << isoscelesMin << "\nМаксимальный периметр равнобедренного треугольника - " << isoscelesMax << endl;
	cout << "Минимальный периметр прямоугольного треугольника - " << rectangularMin << "\nМаксимальный периметр прямоугольного треугольника - " << rectangularMax << endl;
	cout << "Минимальный периметр разностороннего треугольника - " << arbitraryMin << "\nМаксимальный периметр разностороннего треугольника - " << arbitraryMax << endl;
}
