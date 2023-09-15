#include <iostream>

using namespace std;

int main()
{
    int numar, sute, unitati, pereche;
    cout <<"Va rog sa introduceti un numar naturalcare contine trei cifre: ";
    cin >>numar;
    unitati=numar%10;
    sute=(numar/100)%10;
    pereche=sute*10+unitati;
    cout <<"Patratul numarului format din cifra sutelor si cifra unitatilor ale numarului introdus de catre dumneavoastra este: "<<pereche*pereche<<" .";
    return 0;
}
