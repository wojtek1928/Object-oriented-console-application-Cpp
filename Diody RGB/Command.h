#ifndef COMMAND_H_
#include <vector>
#include<string>

using namespace std;

void command(vector<Tmodel*>* models,vector<Ttechnology*>* technologies) {
    string command;//zmienna przechwująca komendę pobraną z konsoli
    while (command != "EXIT") {
        cout << "Podaj nazwę modelu lub technologię aby wyświetlić informacje(wpisz EXIT aby zakończyć program)" << endl;
        cin >> command;
        bool found = false;
        for (auto model : *models) {
            if (model->get_name() == command) {
                model->info();
                found = true;
            }

        }
        for (auto technology : *technologies) {
            if (technology->get_name() == command) {
                technology->info();
                found = true;
            }
        }
        if (!found and command != "EXIT")cout << "\nNie znaleziono takiego elementu!\n" << endl;

    }
}
#endif // !COMMAND_H_

