#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cout <<"Va rog sa introduceti doua numere intregi: ";
    cin >>a>>b;
    if ((a<0)&(b<0))
    {
        cout <<"Numerele introduse de catre dumneavoastra au acelasi semn, mai exact sunt negative.";
    }
    if ((a>0)&(b>0))
    {
        cout <<"Numerele introduse de catre dumneavoastra au acelasi semn, mai exact sunt pozitive.";
    }
    if ((a<0)&(b>0))
    {
        cout <<"Numerele introduse de catre dumneavoastra nu au acelasi semn, mai exact primul este negativ, iar al doilea este pozitiv.";
    }
    if ((a>0)&(b<0))
    {
        cout <<"Numerele introduse de catre dumneavoastra nu au acelasi semn, mai exact primul este pozitiv,iar al doilea este negativ.";
    }
    return 0;
}
