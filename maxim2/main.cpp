#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cout <<"Va rog sa introduceti doua numere intregi.";
    cin >>a>>b;
    if (a<b)
    {
        cout <<"Dintre cele doua numere introduse "<<b<<" este cel mai mare.";
    }
    if (a>b)
    {
        cout <<"Dintre cele doua numere introduse "<<a<<" este cel mai mare.";
    }
    return 0;
}
