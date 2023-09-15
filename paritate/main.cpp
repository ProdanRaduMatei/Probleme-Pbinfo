#include <iostream>

using namespace std;

int main()
{
    int numar;
    cout <<"Va rog sa introduceti un numar natural pentru a se verifica daca acesta este par sau impar: ";
    cin >>numar;
    if (numar%2==0)
    {
        cout <<"Nuarul introdus de catre dumneavoastrra este par.";
    }
    else
    {
        cout <<"Numarul introdus de catre dumneavoastra este  impar.";
    }
    return 0;
}
