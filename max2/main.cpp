#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cout <<"Va rog sa introduceti doua numere intregi pentru a le compara: ";
    cin >>a>>b;
    if (a<=b)
    {
        cout <<b<<" este cel mai mare dintre cele doua numere.";
    }
    else
    {
        cout <<a<<" este cel mai mare dintre cele doua numere.";
    }
    return 0;
}
