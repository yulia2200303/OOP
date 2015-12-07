// lab7.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include "Stack.h"
#include "triangle.h"
#include "error.h"

template <class Z> static  int GetCount(Z element, Stack<Z> &stack){
	int count = 0;
	Stack<Z> *newStack = new Stack<Z>(stack);
	while (!newStack->IsEmpty())
	{

		if (newStack->Pop() > element)
			count++;
	}
	return count;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	try{

		Stack <int> *stack1 = new Stack <int>(17);
		stack1->Push(3);
		stack1->Push(56);
		stack1->Push(15);
		stack1->Print();
		cout << "Количество элементов больше 10: " << GetCount<int>(10, *stack1) << endl;
		Stack <double> *stack2 = new Stack <double>(40);
		*stack2 + 11.6;
		*stack2 + 10.33;
		*stack2 + -109.56;
		*stack2 + -9.56;
		stack2->Print();
		cout << (*stack2)-- << endl;
		cout << ((*stack2)() == 0 ? "False" : "True") << endl;
		//ErrorArrayIndex
		//double x = stack1->operator[](-100);
		//--------------
		cout << "Количество элементов больше 10.0: " << GetCount<int>(10.0, *stack1) << endl;


		//ErrorArraySize
	/*	Stack<int> *st4 = new Stack<int>(2);
		*st4 + 1;
		*st4 + 2;
		*st4 + 3;*/
		//---------------



		Stack <Triangle> *stack3 = new Stack <Triangle>(5);
		//ErrorNullPointer
		/*Triangle *a = NULL;
		stack3->Push(*a);*/
		//------------------
		//ErrorNegative
		/*stack3->Push(*(new Triangle(Point(-9999, 8), Point(3, 4), Point(6, 2))));*/
		//-----------------
		stack3->Push(*(new Triangle(Point(1, 8), Point(3, 4), Point(6, 2))));
		stack3->Push(*(new Triangle(Point(0, 0), Point(0.5, sqrt(3) / 2), Point(1, 0))));
		stack3->Print();
		cout << "Количество элементов большe (0;0): " << GetCount<Triangle>(Triangle(Point(0, 0), Point(0, 0), Point(0, 0)), *stack3) << endl;
		Triangle t = stack3->Top();
		cout << t.GetPerimeter() << endl;

		//Error
		throw Error(001, "Просто случайная ошибка");
		//-------------------------------------------
	}
	catch (ErrorNullPointer err){
		err.Print();
	}
	catch (ErrorArraySize err){
		err.Print();
	}
	catch (ErrorArrayIndex err){
		err.Print();
	}
	catch (ErrorNegativeItem err){
		err.Print();
	}
	catch (Error err)
	{
		err.Print();
	}
	return 0;
}

