#pragma once
#include "stdafx.h"

class Error {
protected:
	int code;
	string massage;
public:

	Error(int code, string message)
	{
		SetCode(code);
		SetMassage(message);
	}

	int GetCode()
	{
		return code;
	}

	string GetMassage()
	{
		return massage;
	}
	void SetCode(int code)
	{
		this->code = code;
	}
	void SetMassage(string massage)
	{
		this->massage = massage;
	}
	virtual void Print()
	{
		cout << "code: " << this->code << "\nmassage: " << massage.c_str() << endl;
	}
};


class ErrorNullPointer : public Error{
	string name;
public:
	ErrorNullPointer(int code, string message, string name):Error(code, message){
		SetName(name);
	}

	string GetName(){
		return name;
	}

	void SetName(string name){
		this->name = name;
	}

	void Print(){
		Error::Print();
		cout << "className: " << name.c_str() << endl;
	}
};

class ErrorArrayIndex : public Error{
	int index;
public:

	ErrorArrayIndex(int code, string message, int index) :Error(code, message)
	{
		SetIndex(index);
	}

	int GetIndex()
	{
		return index;
	}
	void SetIndex(int index)
	{
		this->index = index;
	}
	void Print()
	{
		Error::Print();
		cout << "index: " << this->index;
	}
};


class ErrorArraySize : public Error{
	int size;
public:

	ErrorArraySize(int code, string message, int size) :Error(code, message)
	{
		SetSize(size);
	}

	int GetSize()
	{
		return size;
	}
	void SetSize(int size)
	{
		this->size = size;
	}
	void Print()
	{
		Error::Print();
		cout << "size: " << this->size;
	}
};



class ErrorNegativeItem : public Error{
	double item;
public:

	ErrorNegativeItem(int code, string message, int item) :Error(code, message)
	{
		SetItem(item);
	}

	int GetItem()
	{
		return item;
	}

	void SetItem(int item)
	{
		this->item = item;
	}

	void Print()
	{
		Error::Print();
		cout << "item: " << this->item <<  endl;
	}
};