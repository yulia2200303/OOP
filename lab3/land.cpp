#include "stdafx.h"
#include "land.h"

Land::Land(){
	this->population = 0;
	this->square = 0;
}

Land::Land(double square, int population){
	this->square = square;
	this->population = population;
}

Land::Land(const Land& land){
	this->square = land.square;
	this->population = land.population;
}

int Land::GetPopulation(){
	return this->population;
}

double Land::GetSquare(){
	return this->square;
}

void Land::SetPopulation(int population){
	this->population = population;
}

void Land::SetSquare(double square){
	this->square=square;
}
