#include <iostream>
#include "Czas.h"
#include "Harmonogram.h"

using namespace std;
int main() {
    Harmonogram h1;
    Czas czas1(5);
    Czas czas2(10);
    Czas czas3(5);
    (czas1 += czas2).WypiszCzas();
    Czas czas (12,59,120);
    czas.WypiszCzas();
    h1.dodajZadanie(czas1);
    h1.dodajZadanie(czas2);
    h1.dodajZadanie(czas3);
cout << "===========\n";
    h1.Wypisz();
    h1.Sumuj().WypiszCzas();
    return 0;
}
