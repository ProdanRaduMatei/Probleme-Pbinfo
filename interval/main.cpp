#include <iostream>

using namespace std;

int main()
{
    int a, b, x;
    cout <<"Va rog sa introduceti limita minima a intervalului: ";
    cin >>a;
    cout <<"Va rog sa introduceti limita maxima a intervalului: ";
    cin >>b;
    cout <<"Va rog sa introduceti numarul,pentru a verifica daca apartine intervalului: ";
    cin >>x;
    if (x<a)
    {
        cout <<"Numarul nu apartine intervalului, pentru ca este mmai mic decat limita minima a intervalului.";
    }
    if (x>b)
    {
        cout <<"Numarul nu apartine intervalului, pentru ca este mai mare decat limita maxima a intervalului.";
    }
    if ((x>a)&(x<b))
    {
        cout <<"Numarul apartine intervalului, pentru ca este mai mare decat limita minima si totodata mai mic decat limita maxima a acestuia.";
    }
    if (x=a)
    {
        cout <<"Numarul apartine intervalului, pentru ca este egal cu limita minima a acestuia.";
    }
    if (x=b)
    {
        cout <<"Numarul apartine intervalului, pentru ca este egal cu limita maxima a acestuia.";
    }
    return 0;
}
