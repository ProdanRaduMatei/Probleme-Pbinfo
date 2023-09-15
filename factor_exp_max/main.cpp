/*
Cerința
Se dă un număr natural n. Să se determine factorul prim din descompunerea lui n care apare la puterea cea mai mare. Dacă există mai mulți factori care apar la putere maximă, se va afișa cel mai mare dintre ei.

Date de intrare
Programul citește de la tastatură numărul n.

Date de ieșire
Programul va afișa pe ecran factorul prim cerut.

Restricții și precizări
n este un număr natural strict mai mare decât 1 și are cel mult 12 cifre (este de tip long long)
Exemplu:
Intrare

7623
Ieșire

11
Explicație
Descompunerea lui n=7623 în factori este 32 * 71 * 112. Sunt doi factori de exponent maxim 2, din care cel mai mare este 11.
*/

#include <iostream>
using namespace std;

int main()
{
    long long n,d=2,maxd=0,pmax=0;
    cin >> n;

    while(n>1){
        int p=0;
        while(n%d==0){
            p++;
            n/=d;
        }
        if(p>=pmax){
            maxd=d;
            pmax=p;
        }
        d++;
        if(n>1 && d*d>n) d=n;
    }
    cout << maxd;
    return 0;
}