#include <iostream>

#include "Ttechnology.h"

using namespace std;


Ttechnology::Ttechnology(string name, vector<Ttechnology*>* technologies)
{
	this->name = name;
	technologies->push_back(this);
}

void Ttechnology::set_new_name(std::string name) {
	this->name = name;
}

void Ttechnology::set_label(string label) {
	this->label = label;
}

void Ttechnology::set_RGB(int rgb) {
	this->RGB = rgb;
}

void Ttechnology::add_model(Tmodel* model) {
	model->set_technology(this->get_name());
	this->models.push_back(model);
}

void Ttechnology::info() {
	cout << "\n+++ Technology +++" << endl;
	cout << "-Nazwa: " << name << endl;
	cout << "-Opis: " << label << endl;
	cout << "-RGB: " << hex << RGB << endl;
	cout << "-Modele wykonane tą metodą: " << endl;
	for (auto model : models)cout << model->get_name() << endl;
	cout << "+++++++++++++++++++\n" << endl;
}