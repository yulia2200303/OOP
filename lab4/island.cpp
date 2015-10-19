#include "stdafx.h"
#include "sea.h"
#include "land.h"
#include "island.h"

Island::Island(){
	this->remoteness = 0;
	this->name = "";
	this->sea = Sea();
	this->add();
} 

Island::Island(Sea sea, double remoteness, string name):Island(){
	this->remoteness = remoteness;
	this->name = name;
	this->sea = sea;
}

Island::Island(Island& island):Island(){
	this->name = island.name;
	this->sea = island.sea;
	this->remoteness = island.remoteness;
	this->SetPopulation(island.GetPopulation());
	this->SetSquare(island.GetSquare());
}

Island::Island(Sea sea, double remoteness, string name, int population, double square):Island(){
	this->remoteness = remoteness;
	this->name = name;
	this->sea = sea;
	this->SetPopulation(population);
	this->SetSquare(square);
}

string Island::GetName(){
	return this->name;
}

double Island::GetRemoteness(){
	return this->remoteness;
}

Sea Island::GetSea(){
	return this->sea;
}

void Island::SetName(string name){
	this->name=name;
}

void Island::SetRemoteness(double remoteness){
	this->remoteness=remoteness;
}


void Island::Print(){
	cout << "Название острова: " << this->name.c_str() << endl;
	cout << "Удаленность: " << this->remoteness << endl;
	cout << "Площадь  острова" << this->GetSquare() << endl;
	cout << "Численность населения " << this->GetPopulation() << endl;
	this->PrintSea();
}


int Island::GetPopulation(){
	return this->population;
}

double Island::GetSquare(){
	return this->square;
}

void Island::SetPopulation(int population){
	this->population = population;
}

void Island::SetSquare(double square){
	this->square = square;
}

void Island::add()
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

void Island::PrintSea(){
		sea.Print();
}