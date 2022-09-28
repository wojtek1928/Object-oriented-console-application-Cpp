#include <iostream>
#include <locale.h>
#include <vector>
#include<stdio.h>

#include"Tmodel.h"
#include"Ttechnology.h"
#include"Command.h"

using namespace std;
//deklaracja vectorów do przechowywania wskaźników modeli i technologii - są one potrzebne do działania funkcji wyszukiwania w konsoli
vector <Tmodel*> models;
vector <Ttechnology*> technologies;

int main()
{
    //stworzenie obiektów modeli
    Tmodel mod1("Model1", &models);
    mod1.add_description("Model1 - wydruk 3D buta");
    models[0]->set_LED_id(0);//można edytować model z posiomu vectora wskźników models
    mod1.add_sponsor("WIMiR");
    mod1.add_sponsor("Adidas");

    Tmodel mod2("Model2", &models);
    mod2.add_description("Model2 - wydruk 3D piłki");
    mod2.set_LED_id(1);
    mod2.add_sponsor("Nike");
    mod2.add_sponsor("Puma");

    Tmodel mod3("Model3", &models);
    mod3.add_description("Model3 - wydruk do badania");
    mod3.set_LED_id(2);
    mod3.add_sponsor("Grzegorz Brzęczyszczykiewicz");
    mod3.add_sponsor("AGH");;

    Tmodel mod4("Model4", &models);
    mod4.add_description("Model4 - wydruk samolotu na tek elektrownii");
    mod4.set_LED_id(3);
    mod4.add_sponsor("LOT");
    mod4.add_sponsor("Tauron");

    Tmodel mod5("Model5", &models);
    mod5.add_description("Model5 - wydruk 3D autobusu");
    mod5.set_LED_id(4);
    mod5.add_sponsor("PKS");
    mod5.add_sponsor("MPK");

    Tmodel mod6("Model6", &models);
    mod6.add_description("Model6 - wydruk 3D kopalni odkrywkowej");
    mod6.set_LED_id(4);
    mod6.add_sponsor("KGHM");
    mod6.add_sponsor("Elektrownia Bełchatów");

    Tmodel mod7("Model7", &models);
    mod7.add_description("Model7 - wydruk 3D ciągnika rolniczego");
    mod7.set_LED_id(4);
    mod7.add_sponsor("URSUS");
    mod7.add_sponsor("FENDT");

    //stworzenie obiektów technologii
    Ttechnology tech1("FDM", &technologies);
    tech1.set_RGB(0xd564e3);
    tech1.set_label("Części budowane są na skutek osadzania kolejnych warstw stopionego tworzywa termoplastycznego. Za twórcę technologii FDM uznawana jest firma Stratasys®, która od początku lat 90-tych inwestuje w jej rozwój. W związku z ogromnym zainteresowaniem technologią FDM oraz możliwością budowy własnych urządzeń bazujących na produkcie firmy Stratasys®, wprowadzono nową alternatywną nazwę FFF (Fused Filament Fabrication). Technologia FDM wykorzystywana była początkowo do budowy relatywnie tanich prototypów oraz modeli poglądowych. Obecnie stosowana jest do wytwarzania wysokiej jakości prototypów funkcjonalnych oraz modeli koncepcyjnych z szerokiej gamy materiałów termoplastycznych, takich jak: ABS, ASA, PC, PC-ABS oraz ULTEM. Aktualnie technologia FDM jest najczęściej wykorzystywaną spośród wszystkich metod przyrostowych na świecie. Świadczy o tym ilość zainstalowanych i wykorzystywanych systemów FDM.");

    Ttechnology tech2("SLA", &technologies);
    tech2.set_RGB(0xFF00000);
    tech2.set_label("Stereolitografia należy do grupy technik druku 3D, które wykorzystują proces fotopolimeryzacji (podobnie jak technologia DLP (ang. Direct Light Processing), z którą ma wiele wspólnych cech). Budowany obiekt powstaje wskutek selektywnego utwardzania żywicy fotopolimerowej światłem lasera.");

    Ttechnology tech3("SLS", &technologies);
    tech3.set_RGB(0x11FF00);
    tech3.set_label("Wykorzystywany w metodzie laser spieka cząsteczki sproszkowanego termoplastycznego polimeru, łącząc go następnie w kolejne warstwy. Technologia SLS znajduje szerokie zastosowanie, zarówno w prototypowaniu, jak i również w małoseryjnej produkcji funkcjonalnych części z tworzyw sztucznych o dobrych właściwościach mechanicznych.Obecnie spośród wszystkich dostępnych technologii druku 3D jest najczęściej wykorzystywaną z metod w małoseryjnej produkcji części finalnych maszyn i urządzeń technicznych.Duża swoboda projektowania, wysoka dokładność wykonanych elementów oraz produkcja części o dobrych właściwościach mechanicznych sprawiają, iż technologia SLS zyskuje na coraz większym znaczeniu ze strony przemysłu.");

    Ttechnology tech4("PolyJET", &technologies);
    tech4.set_RGB(0x11FFFF);
    tech4.set_label("Zasada jej działania jest bardzo podoba do pracy standardowych drukarek 2D. Podobnie jak w przypadku tradycyjnych drukarek atramentowych, piezoelektryczne głowice drukujące natryskują na platformę roboczą kolejne warstwy ciekłego światłoutwardzalnego fotopolimeru, który następnie pod wpływem światła ultrafioletowego (UV) ulega utwardzeniu. Proces ten, który wykorzystywany jest również w technologii SLA, nosi nazwę fotopolimeryzacji. Technologia PolyJet została opracowana przez firmę Objet (obecnie Stratasys), która nieustannie dąży do rozwoju wykorzystywanych w metodzie fotopolimerów oraz ich właściwości mechanicznych. Obecnie w wersji Triple-Jet uważana jest za jedną z najbardziej zawansowanych oraz multimateriałowych technologii przetwarzających fotopolimery. Elementy wydrukowane w technologii PolyJet charakteryzują się wysoką dokładnością, przy jednoczesnym uzyskaniu dużej gładkości powierzchni.Dodatkową zaletą jest możliwość budowania modeli z szerokiej gamy materiałów twardych(podobnych do ABS), elastycznych(gumopodobnych) oraz transparentnych.");

    //przypisanie poszczególnych modeli do wybranych technologii
    for (int i = 0; i < models.size(); i++) {
        if (i < 1)tech1.add_model(models[i]);
        else if (i < 3)tech2.add_model(models[i]);
        else if (i < 5)tech3.add_model(models[i]);
        else if (i < 7)tech4.add_model(models[i]);
    }
    //uruchomienie funkcji odpowidzialnej za wyszukiwanie i wyświetalnie danych przy pomocy konsoli
    command(&models, &technologies);

    return 0;
}