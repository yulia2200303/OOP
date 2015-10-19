#pragma once
#include "stdafx.h"
#include "sea.h"
#include "land.h"
#include "continent.h"

Continent::Continent(){
	this->name = "";
	this->lenght = 0;
	this->seas = NULL;
	this->add();
}

Continent::Continent(Sea *seas, int lenght, string name) :Continent(){
	this->lenght = lenght;
	this->name = name;
	this->seas = new Sea[lenght];
	for (int i = 0; i < lenght; i++)
	{
		this->seas[i] = seas[i];
	}
}

Continent::Continent(Continent& continent) :Continent(){
	this->lenght = continent.lenght;
	this->name = continent.name;
	this->seas = new Sea[continent.lenght];

	this->SetPopulation(continent.GetPopulation());
	this->SetSquare(continent.GetSquare());
	for (int i = 0; i < continent.lenght; i++)
	{
		this->seas[i] = continent.seas[i];
	}

}

Continent::Continent(Sea *seas, int lenght, string name, int population, double square) :Continent(){
	this->lenght = lenght;
	this->name = name;
	this->seas = new Sea[lenght];
	this->SetPopulation(population);
	this->SetSquare(square);
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
	cout << "Площадь континента " << this->GetSquare() << endl;
	cout << "Численность населения " << this->GetPopulation() << endl;
	this->PrintSeas();
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


void Continent::add()
{
	if (!this->head)
	{
		this->head = this;
		this->next = NULL;
	}
	else
	{
		Land *q = this->head;
		if (q->next == NULL)
		{
			q->next = this;
			this->next = NULL;
		}
		else
		{
			while (q->next != NULL)
			{
				q = q->next;
			};
			q->next = this;
			this->next = NULL;
		};

	};
};
