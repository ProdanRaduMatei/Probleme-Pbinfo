#include <iostream>

using namespace std;

int main()
{
    int a, b, c, diferenta;
    cout <<"Va rog sa introduceti trei numere naturale: ";
    cin >>a>>b>>c;
    if ((a>b)&(b>c))
    {
        diferenta=a-c;
        cout <<"Diferenta dintre cel mai mare si cel mai mic numar inrodus de catre dumneavoastra este: "<<diferenta<<" .";
    }
    if ((a<b)&(b<c))
    {
        diferenta=c-a;
        cout <<"Diferenta dintre cel mai mare si cel mai mic numar inrodus de catre dumneavoastra este: "<<diferenta<<" .";
    }
    if ((b>a)&(a>c))
    {
        diferenta=b-c;
        cout <<"Diferenta dintre cel mai mare si cel mai mic numar inrodus de catre dumneavoastra este: "<<diferenta<<" .";
    }
    if ((b>c)&(c>a))
    {
        diferenta=b-a;
        cout <<"Diferenta dintre cel mai mare si cel mai mic numar inrodus de catre dumneavoastra este: "<<diferenta<<" .";
    }
    if ((a>c)&(c>b))
    {
        diferenta=a-b;
        cout <<"Diferenta dintre cel mai mare si cel mai mic numar inrodus de catre dumneavoastra este: "<<diferenta<<" .";
    }
    return 0;
}
