#include <iostream>

using namespace std;

int main()
{
    int numar, sute, unitati, pereche;
    cout <<"Va rog sa introduceti un numar care sa contin trei cifre: ";
    cin >>numar;
    unitati=numar%10;
    sute=(numar/100)%10;
    pereche=sute*10+unitati;
    cout <<"Numarul obtinut prin eliminarea cifrei din mijloc a numarului introdus de catre dumneavoastra este: "<<pereche<<" .";
    return 0;
}
