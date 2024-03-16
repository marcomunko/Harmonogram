#ifndef HARMONOGRAM_HARMONOGRAM_H
#define HARMONOGRAM_HARMONOGRAM_H

#include "Czas.h"

class Harmonogram {
private:
    Czas *tab;
    int rozmiar;
public:
    Harmonogram();
    Harmonogram(const Harmonogram& h);
    Harmonogram(const Harmonogram& h, int n);
    Harmonogram(const Harmonogram& h, Czas& c);
    ~Harmonogram();

    void dodajZadanie(Czas c);
    void usunZadanie(int index);
// z zadania
    int Wielkość();

    Czas& operator[](int index);

    void Wypisz();
// z zadania
    Czas Sumuj();
};


#endif //HARMONOGRAM_HARMONOGRAM_H
