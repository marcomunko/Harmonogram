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
    ~Harmonogram();

    void dodajZadanie(Czas c);
    void usunZadanie(int index);

    int Wielkość();

    Czas& operator[](int index);

    void Wypisz();

    Czas Sumuj();
};


#endif //HARMONOGRAM_HARMONOGRAM_H
