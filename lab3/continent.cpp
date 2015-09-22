#include "stdafx.h"
#include "sea.h"
#include "land.h"
#include "continent.h"


Continent::Continent(){
	this->name = "";
	this->lenght = 0;
	this->seas = NULL;
}

Continent::Continent(Sea *seas, int lenght, string name){
	this->lenght = lenght;
	this->name = name;
	this->seas = new Sea[lenght];
	for (int i = 0; i < lenght; i++)
	{
		this->seas[i] = seas[i];
	}
}

Continent::Continent(const Continent& continent) :Land(continent.square, continent.population){
	this->lenght = continent.lenght;
	this->name = continent.name;
	this->seas = new Sea[continent.lenght];
	for (int i = 0; i < continent.lenght; i++)
	{
		this->seas[i] = continent.seas[i];
	}
}

Continent::Continent(Sea *seas, int lenght, string name, int population, double square) :Land(square, population){
	this->lenght = lenght;
	this->name = name;
	this->seas = new Sea[lenght];
	for (int i = 0; i < lenght; i++)
	{
		this->seas[i] = seas[i];
	}
}

string Continent::GetName(){
	return this->name;
}

Sea* Continent::GetSeas(){
	return this->seas;
}

int Continent::GetLenght(){
	return this->lenght;
}

void Continent::SetName(string name){
	this->name=name;
}

void Continent::PrintSeas(){
	for (int i = 0; i < lenght; i++)
	{
		seas[i].Print();
	}
}

void Continent::Print(){
	cout << "Континент: " << this->name.c_str() << endl;
	Land::Print();
	this->PrintSeas();
}

