#include <iostream>
#include "Czas.h"

using namespace std;
int main() {
    Czas czas1(5);
    Czas czas2(10);
    Czas czas3(5);
    cout<<"== "<< (czas1 == czas3)<<endl;
    Czas czas (12,121,183);
    czas.WypiszCzas();
//kometarz
    return 0;
}
