#include <iostream>

using namespace std;

int main()
{
    int numar, a, b;
    cout <<"Va rog sa introduceti un numar care sa contina doua cifre: ";
    cin >>numar;
    a=numar%10;
    b=(numar/10)%10;
    cout <<"Suma cifrelor numarului introdus de catre dumneavoastra este: "<<a+b<<" .";
    return 0;
}
