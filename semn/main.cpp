#include <iostream>

using namespace std;

int main()
{
    int numar;
    cout <<"Va rog sa introduceti un numar intreg: ";
    cin >>numar;
    if (numar<0)
    {
        cout <<"Numarul introdus de catre dumneavoastra este negativ (are semnul -).";
    }
    if (numar>0)
    {
        cout <<"Numarul introdus de catre dumneavoastra este pozitiv (are semnul +).";
    }
    if (numar=0)
    {
        cout <<"Numarul introdus de catre dumneavoastra este nul ( este egal cu zero).";
    }
    return 0;
}
