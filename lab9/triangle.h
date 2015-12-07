#pragma once
#include "stdafx.h"
#include "error.h"
struct Point {
	double x;
	double y;

	Point(){
		this->x = 0;
		this->y = 0;
	}

	Point(double x, double y)
	{
		if (x < 0 || y < 0) throw ErrorNegativeItem(2099, "отрицательная координата", x < 0 ? x : y);
		this->x = x;
		this->y = y;
	}
};


class Triangle {
	Point a_;
	Point b_;
	Point c_;
public:
	Triangle();
	Triangle(Point a, Point b, Point c);
	Triangle(Triangle&);
	~Triangle();
	void Print();
	Point GetPointA();
	Point GetPointB();
	Point GetPointC();
	Point GetPoint(int i);
	void SetPointA(Point point);
	void SetPointB(Point point);
	void SetPointC(Point point);
	void SetPoint(int i, Point point);
	static double GetSide(Point a, Point b);
	bool IsIsosceles();
	bool IsEquilateral();
	bool IsRectangular();
	bool IsArbitrary();
	double GetPerimeter();
	friend ostream& operator<<(ostream& os, const Triangle& dt);
	bool operator>(Triangle &E){
		if (this->GetPointA().x > E.GetPointA().x || this->GetPointA().y > E.GetPointA().y)
			return true;
		return false;
	}
	operator int(){
		if (this == NULL) throw ErrorNullPointer(3928, "Объект равен Null", "Class - Triangle");
		return this->a_.x;
	}
};

void DisplayType(Triangle *arr, int size);
void DisplayMinMaxPerimeter(Triangle *arr, int size);