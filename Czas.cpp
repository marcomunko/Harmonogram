#include "Czas.h"
#include <cmath>
#include <iostream>

using namespace std;

Czas::Czas() {
    sekundy = 0;
}

Czas::Czas(int godziny, short minuty, short sekundy)
{
    UstawCzas(godziny,minuty,sekundy);
}

Czas::Czas(short minuty, short sekundy) {
    UstawCzas(minuty,sekundy);
}

Czas::Czas(long sekundy) {
    SetSekundy(sekundy);
}

void Czas::UstawCzas(short minuty, short sekundy) {
    SetSekundy(sekundy + 60*minuty);
}

void Czas::UstawCzas(int godziny, short minuty, short sekundy) {
    SetSekundy(sekundy + 60*minuty + 3600*godziny);
}

void Czas::SetSekundy(long sek) {
    if(sek <= 0){
        this->sekundy=0;
        return;
    }

    this->sekundy=sek;
}

int Czas::GetGodziny() {
    return floor(sekundy/3600);
}

short Czas::GetMinuty() {
    return floor(sekundy%3600/60);
}

short Czas::GetSekundy() {
    return sekundy%60;
}

void Czas::WypiszCzas() {
    cout << GetGodziny() << ":" << GetMinuty() << ":" << GetSekundy() << endl;
}

void Czas::AddSekundy(long sekundy) {
    this->sekundy+=sekundy;
    if(this->sekundy < 0){
        this->sekundy = 0;
    }
}

unsigned long Czas::IlośćSekundWCzasie() {
    return sekundy;
}

bool operator == (Czas& C1, Czas& C2){
    return C1.IlośćSekundWCzasie() == C2.IlośćSekundWCzasie();
}

bool operator < (Czas& C1, Czas& C2){
    return C1.IlośćSekundWCzasie() < C2.IlośćSekundWCzasie();
}

bool operator > (Czas& C1, Czas& C2){
    return C1.IlośćSekundWCzasie() > C2.IlośćSekundWCzasie();
}

bool operator <= (Czas& C1, Czas& C2){
    return C1.IlośćSekundWCzasie() <= C2.IlośćSekundWCzasie();
}

bool operator >= (Czas& C1, Czas& C2){
    return C1.IlośćSekundWCzasie() >= C2.IlośćSekundWCzasie();
}

bool operator != (Czas& C1, Czas& C2){
    return C1.IlośćSekundWCzasie() != C2.IlośćSekundWCzasie();
}

Czas operator + (Czas& C1, Czas& C2){
    Czas c(C1.IlośćSekundWCzasie() + C2.IlośćSekundWCzasie());
    return c;
}

Czas Czas::operator+= (Czas& C2){
    AddSekundy(C2.IlośćSekundWCzasie());
    return *this;
}