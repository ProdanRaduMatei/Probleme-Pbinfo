#include <iostream>

using namespace std;

int main()
{
    int a, b, diferenta;
    cout <<"Va rog sa introduceti varstele celor doi copii: ";
    cin >>a>>b;
    if (a>b)
    {
        diferenta=a-b;
        if (diferenta<20)
        {
            cout <<"Mai mare este primul copil, iar dierenta de varsta dintre cei doi este de: "<<diferenta<<" ani.";
        }
        if (diferenta>=20)
        {
            cout <<"Mai mare este primul copil,iar diferenta de varsta dintre cei doi este de: "<<diferenta<<" de ani.";
        }
    }
    if (b>a)
    {
        diferenta=b-a;
        if (diferenta<20)
        {
            cout <<"Mai mare este al doilea copil, iar dierenta de varsta dintre cei doi este de: "<<diferenta<<" ani.";
        }
        if (diferenta>=20)
        {
            cout <<"Mai mare este al doilea copil,iar diferenta de varsta dintre cei doi este de: "<<diferenta<<" de ani.";
        }
    }
    return 0;
}
