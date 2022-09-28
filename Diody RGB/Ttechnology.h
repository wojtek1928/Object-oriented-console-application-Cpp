#ifndef TTECHNOLOGY_H_
#define TTECHNOLOGY_H_

#include<string>
#include <vector>

#include "Tmodel.h"


class Ttechnology {
private:	
	std::string name, label;
	std::vector<Tmodel*> models;//wektor przechowujący wskaźniki modeli wykonanych w tej technologii
	int RGB;
public:
	Ttechnology(std::string name, std::vector<Ttechnology*>* technologies);
	void set_new_name(std::string name);
	std::string get_name() { return name; }
	void set_label(std::string label);
	void set_RGB(int rgb);
	void add_model(Tmodel*);
	void info();

};

#endif
