/*
Cerința
Se dă un șir cu n elemente, numere naturale nenule. Să se determine cel mai mare divizor comun al celui mai mic și celui mai mare element din șir.

Date de intrare
Programul citește de la tastatură numărul n, apoi cele n elemente ale șirului.

Date de ieșire
Programul va afișa pe ecran numărul cerut.

Restricții și precizări
1 ≤ n ≤ 1.000
elementele șirului vor fi mai mici decât 1.000.000.000
Exemplu:
Intrare

5
18 25 12 40 36
Ieșire

4
Explicație
Cel mai mic element al șirului este 12, iar cel mai mare este 40. Cel mai mare divizor comun al lor este 4.
*/

#include <iostream>

using namespace std;

int main()
{

    int n,nr,maxx=-2e9, minn=2e9;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>nr;
        if (nr>maxx) maxx=nr;
        else if (nr<minn) minn=nr;
    }

    while(minn!=0)
    {
        int rest=maxx%minn;
        maxx=minn;
        minn=rest;
    }
    cout<<maxx;
    return 0;
}