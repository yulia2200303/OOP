#pragma once
#include "stdafx.h"
#include "sea.h"
#include "land.h"
#include "continent.h"
#include "counrty.h"

Continent::Continent(){
	this->name = "";
	this->seaLenght = 0;
	this->seas = NULL;
	this->countryLenght = 0;
	this->countries = NULL;

}

Continent::Continent(Sea *seas, int seaLenght, string name, Country *countries, int countryLenght) :Continent(){
	this->seaLenght = seaLenght;
	this->name = name;
	this->seas = new Sea[seaLenght];
	for (int i = 0; i < seaLenght; i++)
	{
		this->seas[i] = seas[i];
	}
}

Continent::Continent(Continent& continent) :Continent(){
	this->seaLenght = continent.seaLenght;
	this->name = continent.name;
	this->seas = new Sea[continent.seaLenght];

	this->countryLenght = continent.countryLenght;
	this->countries = new Country[continent.countryLenght];

	this->SetPopulation(continent.GetPopulation());
	this->SetSquare(continent.GetSquare());
	for (int i = 0; i < continent.seaLenght; i++)
	{
		this->seas[i] = continent.seas[i];
	}
	for (int i = 0; i < continent.countryLenght; i++)
	{
		this->countries[i] = continent.countries[i];
	}
}

Continent::Continent(Sea *seas, int sealenght, string name, int population, double square, Country *countries, int countryLenght) :Continent(){
	this->seaLenght = sealenght;
	this->countryLenght = countryLenght;
	this->name = name;
	this->seas = new Sea[seaLenght];
	this->SetPopulation(population);
	this->SetSquare(square);
	for (int i = 0; i < seaLenght; i++)
	{
		this->seas[i] = seas[i];
	}
	this->countries = new Country[countryLenght];
	for (int i = 0; i < countryLenght; i++)
	{
		this->countries[i] = countries[i];
	}
}

string Continent::GetName(){
	return this->name;
}

Sea* Continent::GetSeas(){
	return this->seas;
}

int Continent::GetSeaLenght(){
	return this->seaLenght;
}

int Continent::GetCountryLenght(){
	return this->countryLenght;
}

void Continent::SetName(string name){
	this->name=name;
}

void Continent::PrintSeas(){
	for (int i = 0; i < seaLenght; i++)
	{
		seas[i].Print();
	}
}

void Continent::PrintCountries(){
	for (int i = 0; i < countryLenght; i++)
	{
		countries[i].Print();
	}
}

void Continent::Print(){
	cout << "Континент: " << this->name.c_str() << endl;
	cout << "Площадь континента " << this->GetSquare() << endl;
	cout << "Численность населения " << this->GetPopulation() << endl;
	this->PrintSeas();
	this->PrintCountries();
}

int Continent::GetPopulation(){
	return this->population;
}

double Continent::GetSquare(){
	return this->square;
}

void Continent::SetPopulation(int population){
	this->population = population;
}

void Continent::SetSquare(double square){
	this->square = square;
}


