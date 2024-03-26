#include "Czas.h"
#include <cmath>
#include <iostream>


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
    std::cout << (GetGodziny() < 10? "0" : "") << GetGodziny()
    << ":" << (GetMinuty() < 10 ? "0" : "" ) << GetMinuty()
    << ":" << (GetSekundy() < 10? "0" : "") << GetSekundy()
    << std::endl;
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

bool Czas::operator == (Czas& C2){
    return IlośćSekundWCzasie() == C2.IlośćSekundWCzasie();
}

bool Czas::operator < (Czas& C2){
    return IlośćSekundWCzasie() < C2.IlośćSekundWCzasie();
}

bool Czas::operator > (Czas& C2){
    return IlośćSekundWCzasie() > C2.IlośćSekundWCzasie();
}

bool Czas::operator <= ( Czas& C2){
    return IlośćSekundWCzasie() <= C2.IlośćSekundWCzasie();
}

bool Czas::operator >= ( Czas& C2){
    return IlośćSekundWCzasie() >= C2.IlośćSekundWCzasie();
}

bool Czas::operator != ( Czas& C2){
    return IlośćSekundWCzasie() != C2.IlośćSekundWCzasie();
}

Czas Czas::operator + ( Czas& C2){
    Czas c(IlośćSekundWCzasie() + C2.IlośćSekundWCzasie());
    return c;
}

Czas &Czas::operator = (const Czas &C2) {
    sekundy = C2.sekundy;
    return *this;
}

Czas& Czas::operator += (const Czas& C2){
    AddSekundy(C2.sekundy);
    return *this;
}

Czas& Czas::operator-=(const Czas &C2) {
    AddSekundy(-C2.sekundy);
    return *this;
}