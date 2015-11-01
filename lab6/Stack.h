#pragma once
#include "stdafx.h"

class Stack{
	int *stack_;
	int capacity_;
	int size_;

public:

	Stack(int capacity = 25)
	{
		this->capacity_ = capacity;
		this->size_ = 0;
		this->stack_ = new int[capacity];
		for (int i = 0; i < capacity; i++)
			this->stack_[i] = NULL;
	};

	Stack(Stack& S)
	{
		this->capacity_ = S.capacity_;
		this->size_ = S.size_;
		this->stack_ = new int[this->capacity_];
		for (int i = 0; i < this->capacity_; i++)
		{
			this->stack_[i] = S.stack_[i];
		}
	}

	int GetSize(){
		return this->size_;
	}

	int Top(){
		if (!this->IsEmpty())
			return this->stack_[this->size_ - 1];
		throw "Excaption: в стеке нет элементов";
	}

	int Pop(){
		if (!this->IsEmpty()){
			int element = this->Top();
			this->stack_[this->size_ - 1] = NULL;
			this->size_--;
			return element;
		}
		throw "Excaption: в стеке нет элементов";
	}

	bool IsEmpty(){
		return this->size_ == 0;
	}

	void Push(int element){
		if (this->size_ < this->capacity_)
			this->stack_[this->size_++] = element;
		else
			throw "Excaption: стек заполнен";
	}

	void Print(){
		for (int i = this->size_ - 1; i >= 0; i--)
		{
			cout << this->stack_[i] << " ";
		}
		cout << endl;
	}

	Stack & operator +(int element){
		this->Push(element);
		return *this;
	}

	int operator --(int element){
		return this->Pop();
	}

	bool operator ()(){
		return this->IsEmpty();
	}

	Stack & operator <(Stack &S){
		Stack *newStack = new Stack(this->GetSize() + S.GetSize());
		int *arr = new int[this->GetSize() + S.GetSize()];
		int arrSize = 0;
		while (!this->IsEmpty())
		{
			arr[arrSize++] = this->Pop();
		}
		while (!S.IsEmpty())
		{
			arr[arrSize++] = S.Pop();
		}
		for (int j = 0; j < arrSize - 1; j++) {
			for (int i = 0; i < arrSize - j - 1; i++) {
				if (arr[i] > arr[i + 1]) {
					int b = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = b;
				}
			}
		}
		for (int i = 0; i < arrSize; i++)
		{
			newStack->Push(arr[i]);
		}
		return *newStack;
	}
};

