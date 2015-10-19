#pragma once
#include "stdafx.h"
#include "sea.h"

Sea::Sea(){
	this->square = 0;
	this->name = "";
}

Sea::Sea(double square, string name){
	this->square = square;
	this->name = name;
}

Sea::Sea(const Sea& sea){
	this->square = sea.square;
	this->name = sea.name;
}

double Sea::GetSquare(){
	return this->square;
}

string Sea::GetName(){
	return this->name;
}

void Sea::SetSquare(double square){
	this->square = square;
}

void Sea::SetName(string name){
	this->name = name;
}

void Sea::Print(){
	cout << "Площадь: " << this->square << endl;
	cout << "Название моря: " << this->name.c_str() << endl;
}