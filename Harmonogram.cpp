#include "Harmonogram.h"
#include <iostream>


Harmonogram::Harmonogram() {
    this->rozmiar = 0;
    this-> tab = new Czas[0];
}
//konstruktor kopiowania
Harmonogram::Harmonogram(const Harmonogram &h) {
    this->rozmiar = h.rozmiar;
    this->tab = new Czas[this->rozmiar];
    for (int i = 0; i < this->rozmiar; i++) {
        this->tab[i] = Czas(h.tab[i]);
    }
}

Harmonogram::Harmonogram(const Harmonogram &h, int n) {
    if(n > h.rozmiar) {
        throw std::invalid_argument("N jest większe od rozmiaru tablicy.");
    }
    this->rozmiar = n;
    this->tab = new Czas[this->rozmiar];
    for (int i = 0; i < this->rozmiar; i++) {
        this->tab[i] = Czas(h.tab[i]);
    }
}

Harmonogram::Harmonogram(const Harmonogram &h, Czas& c) {
    long max = c.IlośćSekundWCzasie();
    this->rozmiar = 0;
    this->tab = new Czas[0];

    for(int i = 0; i < h.rozmiar; i++) {
        if((max -= h.tab[i].IlośćSekundWCzasie()) >= 0) {
            dodajZadanie(Czas(h.tab[i]));
        } else {
            break;
        }
    }
}

Harmonogram::~Harmonogram() {
    delete[] this->tab;
}

void Harmonogram::dodajZadanie(Czas c) {
    realloc(this->tab, ++this->rozmiar);
    this->tab[this->rozmiar - 1] = c;
}

void Harmonogram::usunZadanie(int index) {
    if (index < 0 || index >= this->rozmiar) {
        throw std::invalid_argument("Index wykracza poza zakres tablicy.");
    }
    for (int i = index; i < this->rozmiar - 1; i++) {
        this->tab[i] = this->tab[i + 1];
    }
    realloc(this->tab, --this->rozmiar);
}

Czas &Harmonogram::operator[](int index) {
    if(index < 0 || index >= this->rozmiar) {
        throw std::invalid_argument("Index wykracza poza zakres tablicy.");
    }
    return tab[index];
}

void Harmonogram::Wypisz() {
    for (int i = 0; i < this->rozmiar; i++) {
        std::cout << i + 1 << ". ";
        this->tab[i].WypiszCzas();
    }
}
// z zadania
int Harmonogram::Wielkość(){
    return this->rozmiar;
}
//z zadania
Czas Harmonogram::Sumuj(){
    Czas czas(0);
    for (int i = 0; i < this->rozmiar; i++) {
        czas += this->tab[i];
    }
    return czas;
}