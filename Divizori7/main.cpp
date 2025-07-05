/*
Cerința
Se dă un număr natural n. Calculați suma dintre cei mai mici doi divizori proprii ai lui n.

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

5
Explicație
Cei mai mici doi divizori proprii al lui 12 sunt 2 3.
*/

#include <bits/stdc++.h>

using namespace std;

int n,i,ok,sum;
int main()
{
    cin>>n;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {

            sum+=i;
            if(ok==1){cout<<sum;return 0;}
            ok++;
        }
    }
    cout<<sum+n/sum;
    return 0;
}