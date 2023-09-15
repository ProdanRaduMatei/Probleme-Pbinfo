#include <iostream>

using namespace std;

int main()
{
    int numar, unitati, zeci, sute, iu, iz, is, t;
    cout <<"Va rog sa introduceti un numarnatural de trei cifre: ";
    cin >>numar;
    unitati=numar%10;
    zeci=(numar/10)%10;
    sute=(numar/100)%10;
    if (unitati%2!=0)
    {
        iu=1;
    }
    if (zeci%2!=0)
    {
        iz=1;
    }
    if (sute%2!=0)
    {
        is=1;
    }
    t=iu+iz+is;
    cout <<"Numarul introdus de catre dumneavoastra contine: "<<t<<" numere impare.";
    return 0;
}
