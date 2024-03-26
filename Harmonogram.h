#ifndef HARMONOGRAM_HARMONOGRAM_H
#define HARMONOGRAM_HARMONOGRAM_H

#include "Czas.h"

class Harmonogram {
private:
    Czas *tab;
    int rozmiar;
public:
    Harmonogram();
    // konstruktor kopiujący
    Harmonogram(const Harmonogram& h);
    // konstruktor kopiujący daną ilość indeksów w tablicy
    Harmonogram(const Harmonogram& h, int n);
    // konstruktor kopiujący wartości z tablicy, które mieszczą się w czasie c
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
