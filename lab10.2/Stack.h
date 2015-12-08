#pragma once
#include "stdafx.h"
#include <iostream>

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

	Stack(const Stack& S)
	{
		this->capacity_ = S.capacity_;
		this->size_ = S.size_;
		this->stack_ = new int[this->capacity_];
		for (int i = 0; i < this->capacity_; i++)
		{
			this->stack_[i] = S.stack_[i];
		}
	}

	const int GetSize(){
		return this->size_;
	}

	int Top(){
		if (!this->IsEmpty())
			return this->stack_[this->size_ - 1];
		throw "Excaption: в стеке нет элементов";
	}

	const int Pop(){
		if (!this->IsEmpty()){
			int element = this->Top();
			this->stack_[this->size_ - 1] = NULL;
			this->size_--;
			return element;
		}
		throw "Excaption: в стеке нет элементов";
	}

	const bool IsEmpty(){
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
			std::cout << this->stack_[i] << " ";
		}
		std::cout << std::endl;
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

	bool operator ==(const Stack& st1){
		if (this->size_ != st1.size_) return false;

		for (int i = 0; i < this->size_; i++)
		{
			if (this->stack_[i] != st1.stack_[i]) return false;
		}

		return true;
	}

	bool operator< (const Stack &right) const
	{
		if (this->size_ < right.size_) return true;

		int sum1 = 0; 
		int sum2 = 0;
		for (int i = 0; i < size_; i++)
		{
			sum1 += stack_[i];
			sum2 += right.stack_[i];
		}

		return sum1 < sum2;
	}


	friend std::ostream& operator<<(std::ostream& os, const Stack& st)
	{
		for (int i = st.size_ - 1; i >= 0; i--)
		{
			os << st.stack_[i] << " ";
		}
		os << "\n";
		return os;
	}
};

