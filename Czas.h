#ifndef HARMONOGRAM_CZAS_H
#define HARMONOGRAM_CZAS_H


class Czas {
private:
    long sekundy;

    void SetSekundy(long sekundy);
    void UstawCzas(int godziny, short minuty, short sekundy);
    void UstawCzas(short minuty, short sekundy);

    void AddSekundy(long sekundy);

public:
    Czas();
    explicit Czas(int godziny, short minuty, short sekundy);
    explicit Czas(short minuty, short sekundy);
    explicit Czas(long sekundy);

    short GetSekundy();
    short GetMinuty();
    int GetGodziny();


    void WypiszCzas();
    unsigned long IlośćSekundWCzasie();

    //operatory
    friend bool operator == (Czas& C1, Czas& C2);

    friend bool operator < (Czas& C1, Czas& C2);

    friend bool operator > (Czas& C1, Czas& C2);

    friend bool operator <= (Czas& C1, Czas& C2);

    friend bool operator >= (Czas& C1, Czas& C2);

    friend bool operator != (Czas& C1, Czas& C2);

    friend Czas operator + (Czas& C1, Czas& C2);

    Czas operator += (Czas& C2);
};


#endif //HARMONOGRAM_CZAS_H
