/*
Cerința
Bubu are 2 cutii cu bomboane, în prima cutie sunt a bomboane, iar în a doua cutie sunt b bomboane. Bunica i-a promis lui Bubu că de fiecare dată când primește un zece la informatică, va adăuga în prima cutie a bomboane, iar bunicul i-a promis că de fiecare dată când primește un zece la matematică va adăuga în a doua cutie b bomboane.

Determinați numărul minim de note de zece pe care trebuie să le primească Bubu pentru ca numărul de bomboanele din cele 2 cutii să devină egal.

Date de intrare
Programul citește de la tastatură două numere naturale a și b, reprezentând numărul de bomboane din prima, respectiv din a doua cutie.

Date de ieșire
Programul va afișa pe ecran numărul S, reprezentând numărul minim de note de zece pe care trebuie să le ia Bubu pentru ca numărul de bomboanele din cele 2 cutii să devină egal.

Restricții și precizări
1 ≤ a, b ≤ 1.000.000.000
Exemplu:
Intrare

6 9
Ieșire

3
Explicație
Doi de 10 la info si un 10 la mate.
*/

///Mihai Daniel
#include <iostream>
using namespace std;
long long p,a,b,r,x1,x2;
int main()
{
    cin>>a>>b;
    p=a*b;
    x1=a;
    x2=b;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    p/=a;
    x1=p/x1;
    x2=p/x2;
    cout<<x1+x2-2;
}