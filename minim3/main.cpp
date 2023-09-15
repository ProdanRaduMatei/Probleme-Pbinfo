#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cout <<"Va rog sa introduceti trei numere pentru a determina minimul acestora (care este cel mai mic numar din cele trei numere introduse): ";
    cin >>a>>b>>c;
    if ((a<b)&(a<c))
    {
        cout <<"Cel mai mic numar dintre cele intriduse este: "<<a<<" .";
    }
    if ((b<a)&(b<c))
    {
        cout <<"Cel mai mic numar dintre cele intriduse este: "<<b<<" .";
    }
    if ((c<a)&(c<b))
    {
        cout <<"Cel mai mic numar dintre cele intriduse este: "<<c<<" .";
    }
    return 0;
}
