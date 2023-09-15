#include <iostream>

using namespace std;

int main()
{
    int gaini, oi, capete, picioare;
    cout <<"Va rog sa introduceti numarul de gaini si de oi pe care le doriti: ";
    cin >>gaini>>oi;
    capete=gaini+oi;
    picioare=gaini*2+oi*4;
    cout <<"Numarul de capete al animalelor este: "<<capete<<" , iar numarul de picioare al animalelor este: "<<picioare<<" .";
    return 0;
}
