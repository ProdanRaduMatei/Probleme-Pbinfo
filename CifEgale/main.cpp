#include <iostream>

using namespace std;

int main()
{
    int numar, iu, iz, is;
    cout <<"Va rog sa introduceti un numar natural de trei cifre: ";
    cin >>numar;
    iu=numar%10;
    iz=(numar/10)%10;
    is=(numar/100)%10;
    if ((iu=iz)&(iz=is))
    {
        cout <<"Numarul introdus de catre dumneavoastra are toate cifrele egale intre ele.";
    }
    else
    {
        cout <<"Numarul introdus de catre dumneavoastra nu are toate cifrele egale intre ele.";
    }
    return 0;
}
