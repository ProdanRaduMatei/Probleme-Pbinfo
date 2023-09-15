#include <iostream>

using namespace std;

int main()
{
    int numar, unitati, sute;
    cout <<"Va rog sa introduceti un numar care contine trei cifre: ";
    cin >>numar;
    unitati=numar%10;
    sute=(numar/100)%10;
    cout <<"Produsul dintre cifra unitatilor si cifra sutelor numarului introdus de catre dumneavoastra este: "<<sute*unitati<<" .";
    return 0;
}
