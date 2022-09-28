#ifndef TMODEL_H_
#define TMODEL_H_

#include<string>
#include<vector>

static int next_model_id;//zmienna globalna odpowiedzielna służąca do nadawania kolejnych identyfikatrów dla modeli

class Tmodel {
private:
	int next_model_id = 0;
	std::string name, label, technology;
	std::vector<std::string> sponsors;
	int LED_id, model_id;//model_id - służy do przechowania pozycji wskaźnika danego obiektu w vectorze models 
	
public:
	Tmodel(std::string name, std::vector<Tmodel*>* models);
	void change_name(std::string name);
	void add_description(std::string label);
	void set_technology(std::string name);
	void set_LED_id(int id);
	void add_sponsor(std::string sponsor);
	std::string get_name() { return name; };
	void info();

};

#endif // !1
