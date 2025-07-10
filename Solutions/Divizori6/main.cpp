/*
Cerința
Se dă un număr natural n. Calculați suma dintre cel mai mic și cel mai mare divizor propriu al lui n.

Date de intrare
Programul citește de la tastatură numărul n.

Date de ieșire
Programul va afișa pe ecran numărul determinat.

Restricții și precizări
4 ≤ n ≤ 1.000.000.000
se garantează că n are cel puțin doi divizori proprii
divizorii proprii ai unui număr sunt divizorii diferiți de 1 și de numărul însuși
Exemplu:
Intrare

12
Ieșire

8
Explicație
Cel mai mic divizor propriu al lui 12 este 2, iar cel mai mare este 6.
*/

#include <bits/stdc++.h>

using namespace std;

int n,i;
int main()
{
    cin>>n;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            cout<<i+n/i;
            return 0;
        }
    }

    return 0;
}