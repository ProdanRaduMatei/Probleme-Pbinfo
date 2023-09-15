#include <iostream>

using namespace std;

int main()
{
    int numar, a, b, c;
    cout <<"Va rog sa introduceti un numar care sa contina trei cifre: ";
    cin >>numar;
    a=numar%10;
    b=(numar/10)%10;
    c=(numar/100)%10;
    cout <<"Suma cifrelor numarului introdus de catre dumneavoastra este: "<<a+b+c<<" .";
    return 0;
}
