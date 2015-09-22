#include "stdafx.h"
#include "sea.h"
#include "land.h"
#include "continent.h"
#include "island.h"
#include "counrty.h"

Country::Country(){
	this->name = "";
	this->nationalLanguage = "";
}

Country::Country(string name, string nationalLanguage){
	this->name = name;
	this->nationalLanguage = nationalLanguage;
}

Country::Country(const Country& country){
	this->name = country.name;
	this->nationalLanguage = country.nationalLanguage;
}

Country::Country(string name, string nationalLanguage, Island island) :Island(island.GetSea(), island.GetRemoteness(), island.GetName()){
	this->name = name;
	this->nationalLanguage = nationalLanguage;
}

Country::Country(string name, string nationalLanguage, Continent continent) : Continent(continent.GetSeas(), continent.GetLenght(), continent.GetName()){
	this->name = name;
	this->nationalLanguage = nationalLanguage;
}

string Country::GetName(){
	return this->name;
}

string Country::GetNationalLanguage(){
	return this->nationalLanguage;
}

void Country::SetName(string name){
	this->name=name;
}

void Country::SetNationalLanguage(string nationalLanguage){
	this->nationalLanguage=nationalLanguage;
}

void Country::Print(){

	cout << "Название страны: " << this->name.c_str() << endl;
	cout << "Национальный язык: " << this->nationalLanguage.c_str() << endl;

	Island::Print();
	Continent::Print();

}
