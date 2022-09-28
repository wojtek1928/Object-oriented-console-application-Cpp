#include <iostream>  
#include "Tmodel.h"

using namespace std;

Tmodel::Tmodel(string name,vector<Tmodel*>* models)
{
	this->name = name;
	models->push_back(this);
}

void Tmodel::add_description(string label) {
	this->label = label;

}

void Tmodel::set_LED_id(int id) {
	this->LED_id = id;
}

void Tmodel::add_sponsor(string sponsor) {
	this->sponsors.push_back(sponsor);
}

void Tmodel::set_technology(std::string name) {
	this->technology=name;
}

void Tmodel::info() {
	cout << "\n+++++ MODEL +++++++" << endl;
	cout << "-Nazwa: " << name << endl;
	cout << "-Opis: " << label << endl;
	cout << "-LED_id: " << LED_id << endl;
	cout << "-Technologia: " << technology << endl;
	cout << "-Sponsorzy: " << endl;
	for (auto sponsor : sponsors) cout << sponsor << endl;
	cout << "+++++++++++++++++++\n" << endl;
}