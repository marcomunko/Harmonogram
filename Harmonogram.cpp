#include "Harmonogram.h"
#include <memory>
#include <iostream>

using namespace std;

Harmonogram::Harmonogram() {
    this->rozmiar = 0;
    this-> tab = new Czas[0];
}

Harmonogram::Harmonogram(const Harmonogram &h) {
    this->rozmiar = h.rozmiar;
    this->tab = new Czas[this->rozmiar];
    for (int i = 0; i < this->rozmiar; i++) {
        this->tab[i] = h.tab[i];
    }
}

Harmonogram::Harmonogram(const Harmonogram &h, int n) {
    if(n > h.rozmiar) {
        throw invalid_argument("N jest większe od rozmiaru tablicy.");
    }
    this->rozmiar = n;
    this->tab = new Czas[this->rozmiar];
    for (int i = 0; i < this->rozmiar; i++) {
        this->tab[i] = h.tab[i];
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
        throw invalid_argument("Index wykracza poza zakres tablicy.");
    }
    for (int i = index; i < this->rozmiar - 1; i++) {
        this->tab[i] = this->tab[i + 1];
    }
    realloc(this->tab, --this->rozmiar);
}

Czas &Harmonogram::operator[](int index) {
    if(index < 0 || index >= this->rozmiar) {
        throw invalid_argument("Index wykracza poza zakres tablicy.");
    }
    return tab[index];
}

void Harmonogram::Wypisz() {
    for (int i = 0; i < this->rozmiar; i++) {
        this->tab[i].WypiszCzas();
    }
}

int Harmonogram::Wielkość(){
    return this->rozmiar;
}

Czas Harmonogram::Sumuj(){
    Czas czas(0);
    for (int i = 0; i < this->rozmiar; i++) {
        czas += this->tab[i];
    }
    return czas;
}