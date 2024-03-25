#ifndef HARMONOGRAM_CZAS_H
#define HARMONOGRAM_CZAS_H


class Czas {
private:
    unsigned long sekundy;

    void SetSekundy(long sekundy);
    void UstawCzas(int godziny, short minuty, short sekundy);
    void UstawCzas(short minuty, short sekundy);

    void AddSekundy(long sekundy);

public:
    Czas();
    Czas(int godziny, short minuty, short sekundy);
    Czas(short minuty, short sekundy);
    Czas(long sekundy);

    short GetSekundy();
    short GetMinuty();
    int GetGodziny();


    void WypiszCzas();
    unsigned long IlośćSekundWCzasie();

    //operatory
    bool operator == (Czas& C2);

    bool operator < (Czas& C2);

    bool operator > (Czas& C2);

    bool operator <= (Czas& C2);

    bool operator >= ( Czas& C2);

    bool operator != (Czas& C2);

    Czas operator + (Czas& C2);

    Czas& operator += (Czas& C2);

    Czas& operator -= (Czas& C2);
};


#endif //HARMONOGRAM_CZAS_H
