#include "Czas.h"
#include <cmath>
#include <iostream>

using namespace std;

Czas::Czas(int godziny, short minuty, short sekundy)
{
    UstawCzas(godziny,minuty,sekundy);
}
Czas::Czas(short minuty, short sekundy) {
    godziny = 0;
    UstawCzas(minuty,sekundy);
}

Czas::Czas(long sekundy) {
    godziny = 0;
    minuty = 0;
    SetSekundy(sekundy);
}

void Czas::UstawCzas(short minuty, short sekundy) {
    SetMinuty(minuty);
    SetSekundy(sekundy);
}

void Czas::UstawCzas(int godziny, short minuty, short sekundy) {
    SetGodziny(godziny);
    SetMinuty(minuty);
    SetSekundy(sekundy);
}

void Czas::SetGodziny(int godz) {
    if(godz <= 0){
        this->godziny = 0;
        return;
    }
    this->godziny = godz;
}

void Czas::SetMinuty(short min) {
    if(min <= 0){
        this->minuty = 0;
        return;
    }
    if(min >= 60){
        godziny += (floor(min/60));
    }
    this->minuty=min%60;
}

void Czas::SetSekundy(long sek) {
    if(sek <= 0){
        this->sekundy=0;
        return;
    }

    if(sek >= 60){
        AddMinuty(floor(sek/60));
    }
    this->sekundy=sek%60;
}

int Czas::GetGodziny() {
    return godziny;
}

short Czas::GetMinuty() {
    return minuty;
}

short Czas::GetSekundy() {
    return sekundy;
}

void Czas::WypiszCzas() {
    cout << godziny << ":" << minuty << ":" << sekundy << endl;
}

void Czas::AddSekundy(long sekundy) {
    if(sekundy >= 60){
        AddMinuty(floor(sekundy/60));
    }
    this->sekundy+=sekundy%60;
    if(this->sekundy < 0){
        this->sekundy = 0;
    }
}

void Czas::AddMinuty(short minuty) {
    if(minuty >= 60){
        this->godziny += (floor(minuty/60));
    }
    this->minuty += minuty%60;
    if(this->minuty < 0){
        this->minuty = 0;
    }
}

unsigned long Czas::IlośćSekundWCzasie() {
    return sekundy + 60* minuty +360* godziny;
}

bool operator == (Czas & C1, Czas & C2){
    return C1.IlośćSekundWCzasie() == C2.IlośćSekundWCzasie();
}

bool operator < (Czas & C1, Czas & C2){
    return C1.IlośćSekundWCzasie() < C2.IlośćSekundWCzasie();
}

bool operator > (Czas & C1, Czas & C2){
    return C1.IlośćSekundWCzasie() > C2.IlośćSekundWCzasie();
}

bool operator <= (Czas & C1, Czas & C2){
    return C1.IlośćSekundWCzasie() <= C2.IlośćSekundWCzasie();
}

bool operator >= (Czas & C1, Czas & C2){
    return C1.IlośćSekundWCzasie() >= C2.IlośćSekundWCzasie();
}

bool operator != (Czas & C1, Czas & C2){
    return C1.IlośćSekundWCzasie() != C2.IlośćSekundWCzasie();
}

Czas operator + (Czas & C1, Czas & C2){
    Czas c(C1.IlośćSekundWCzasie() + C2.IlośćSekundWCzasie());
    return c;
}

Czas operator += (Czas & C1, Czas & C2){
    C1.AddSekundy(C2.IlośćSekundWCzasie());
    return C1;
}