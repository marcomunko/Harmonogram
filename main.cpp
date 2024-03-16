#include <iostream>
#include "Czas.h"
#include "Harmonogram.h"
#include <ctime>
#include <clocale>
#include <string>
#include <exception>

Czas CzasUżytkownika(){
    std::cout << "Podaj czas trwania czynności <hh:mm:ss>: ";
    std::string czas;
    std::cin >> czas;

    // sprawdż czy czas jest podany w formule hh:mm:ss
    if(czas.length() != 8){
        throw std::invalid_argument("Nieprawidłowy format czasu");
    }

    //(godziny, minuty, sekundy)
    // <hh>
    std::string hours = czas.substr(0, 2);
    // <mm>
    std::string minutes = czas.substr(3, 2);
    // <ss>
    std::string seconds = czas.substr(6, 2);

    // zamień
    int h = stoi(hours);
    int m = stoi(minutes);
    int s = stoi(seconds);

    if(h < 0 || m < 0 || s < 0){
        throw std::invalid_argument("Czas nie może być ujemny");
    }

    return Czas(h, m, s);
}

int main() {
    //zmuszenie konsoli do używania utf8 (Windows)
    system("chcp 65001");
    srand(time(NULL));
    setlocale( LC_ALL, "pl_PL.UTF-8" );

    Harmonogram har;
    for(int i = 0; i < 5; i++){
        har.dodajZadanie(Czas(rand()%5000));
    }

    bool working = true;
    while(working){
        std::cout << "1. Dodaj czynność\n"
        << "2. Wypisz harmonogram\n"
        << "3. Usuń czynność\n"
        << "4. Test operatorów\n"
        << "5. Zakończ\n";
        std::cout << "> ";

        int wybor;
        std::cin >> wybor;

        if(std::cin.fail()){
            std::cout << "Błędne dane\n";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            continue;
        }

        switch(wybor) {
            case 1: {
                try {
                    har.dodajZadanie(CzasUżytkownika());
                } catch (std::exception e) {
                    std::cout << "Nieprawidłowy format czasu\n";
                    break;
                }
                break;
            }
            case 2:
                std::cout << "1. Pełen zakres\n"
                          << "2. Zakres czasowy\n"
                          << "3. Zakres ilościowy\n";
                std::cout << "> ";

                int wybor2;
                std::cin >> wybor2;

                if (std::cin.fail()) {
                    std::cout << "Błędne dane\n";
                    std::cin.clear();
                    std::cin.ignore(256, '\n');
                    break;
                }

                switch (wybor2) {
                    case 1:
                        har.Wypisz();
                        break;
                    case 2: {
                        try {
                            auto c = CzasUżytkownika();
                            Harmonogram h(har, c);
                            h.Wypisz();
                        } catch (std::exception e) {
                            std::cout << "Nieprawidłowy format czasu\n";
                            break;
                        }
                        break;
                    }
                    case 3: {
                        std::cout << "Podaj ilość czynności: ";
                        int ilosc;
                        std::cin >> ilosc;
                        if (std::cin.fail()) {
                            std::cout << "Błędne dane\n";
                            std::cin.clear();
                            std::cin.ignore(256, '\n');
                            break;
                        }
                        Harmonogram h1(har, ilosc);
                        h1.Wypisz();
                        break;
                    }
                    default:
                        std::cout << "Komenda poza zakresem\n";
                        break;
                }
                break;
            case 3:
                std::cout << "Podaj numer czynności do usunięcia: ";
                int numer;
                std::cin >> numer;

                if (std::cin.fail()) {
                    std::cout << "Błędne dane\n";
                    std::cin.clear();
                    std::cin.ignore(256, '\n');
                    break;
                }

                har.usunZadanie(--numer);
                break;
            case 4:{
                std::cout << "Testowane czasy:\n";
                Czas h1;
                Czas h2;
                try {
                    h1 = CzasUżytkownika();
                    h2 = CzasUżytkownika();
                } catch (std::exception e) {
                    std::cout << "Nieprawidłowy format czasu\n";
                    break;
                }

                std::cout << "====# 0-fałsz 1-prawda #==== \n";
                std::cout << "== " << (h1 == h2) << "\n";
                std::cout << "!= " << (h1 != h2) << "\n";
                std::cout << "< " << (h1 < h2) << "\n";
                std::cout << "> " << (h1 > h2) << "\n";
                std::cout << "<= " << (h1 <= h2) << "\n";
                std::cout << ">= " << (h1 >= h2) << "\n";
                std::cout << "===========================\n";
                break;
            }
            case 5:
                working = false;
                break;
            default:
                std::cout << "Komenda poza zakresem\n";
                break;
        }
    }

    return 0;
}
