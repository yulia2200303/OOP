// lab6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"

int _tmain(int argc, _TCHAR* argv[])
{
	try{

		Stack *stack1 = new Stack(17);
		stack1->Push(3);
		stack1->Push(56);
		stack1->Push(15);
		stack1->Print();
		Stack *stack2 = new Stack(40);
		*stack2 + 11;
		*stack2 + 10;
		*stack2 + -109;
		stack2->Print();
		cout <<(*stack2 )--<< endl;
		cout << ((*stack2)() == 0 ? "False" : "True") << endl;
		stack2->Print();

		Stack st = *stack1 < *stack2;
		st.Print();
	}
	catch (char* message)
	{
		cout << message << endl;
	}
	return 0;
}

