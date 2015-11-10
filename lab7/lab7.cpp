// lab7.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include "Stack.h"
#include "triangle.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	try{

		Stack <int> *stack1 = new Stack <int>(17);
		stack1->Push(3);
		stack1->Push(56);
		stack1->Push(15);
		stack1->Print();
		Stack <double> *stack2 = new Stack <double>(40);
		*stack2 + 11.6;
		*stack2 + 10.33;
		*stack2 + -109.56;
		stack2->Print();
		cout << (*stack2)-- << endl;
		cout << ((*stack2)() == 0 ? "False" : "True") << endl;
		stack2->Print();

		Stack <Triangle> *stack3 = new Stack <Triangle>(10);
		stack3->Push(*(new Triangle(Point(0, 8), Point(3, 5), Point(6, 2))));
		stack3->Push(*(new Triangle(Point(1, 8), Point(3, 4), Point(6, 2))));
		stack3->Push(*(new Triangle(Point(0, 0), Point(0.5, sqrt(3) / 2), Point(1, 0))));
		stack3->Print();
		Triangle t = stack3->Top();
		cout << t.GetPerimeter() << endl;

	}
	catch (char* message)
	{
		cout << message << endl;
	}
	return 0;
}

