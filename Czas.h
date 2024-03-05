#ifndef HARMONOGRAM_CZAS_H
#define HARMONOGRAM_CZAS_H


class Czas {
private:
    short sekundy;
    short minuty;
    int godziny;

    void SetSekundy(long sekundy);
    void SetMinuty(short minuty);
    void SetGodziny(int godziny);
    void UstawCzas(int godziny, short minuty, short sekundy);
    void UstawCzas(short minuty, short sekundy);

    void AddSekundy(long sekundy);
    void AddMinuty(short minuty);

public:
    Czas(int godziny, short minuty, short sekundy);
    explicit Czas(short minuty, short sekundy);
    explicit Czas(long sekundy);

    short GetSekundy();
    short GetMinuty();
    int GetGodziny();


    void WypiszCzas();

    unsigned long IlośćSekundWCzasie();

    friend bool operator == (Czas & C1, Czas & C2);

    friend bool operator < (Czas & C1, Czas & C2);

    friend bool operator > (Czas & C1, Czas & C2);

    friend bool operator <= (Czas & C1, Czas & C2);

    friend bool operator >= (Czas & C1, Czas & C2);

    friend bool operator != (Czas & C1, Czas & C2);


    friend Czas operator + (Czas & C1, Czas & C2);

    friend Czas operator += (Czas & C1, Czas & C2);

};


#endif //HARMONOGRAM_CZAS_H
