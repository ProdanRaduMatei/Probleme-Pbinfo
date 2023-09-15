/*
Cerința
Se dă un șir de n numere naturale nenule și de asemenea un număr natural p. Să se calculeze suma numerelor din șir care au cel puțin p divizori.

Date de intrare
Programul citește de la tastatură numerele n și p, iar apoi șirul de n numere naturale, separate prin spații.

Date de ieșire
Programul va afișa pe ecran numărul S, reprezentând suma numerelor din șir care au cel puțin p divizori.

Restricții și precizări
1 ≤ n ≤ 1000
1 ≤ p ≤ 1000
cele n numere din șir vor fi numere naturale nenule mai mici decât 1.000.000
Exemplul 1:
Intrare

5 3
7 4 10 17 1
Ieșire

14
Explicație
Numerele din șir care au cel puțin 3 divizori sunt 4 și 10, iar suma lor este 14.

Exemplul 2:
Intrare

5 100
5 12 24 3 72
Ieșire

0
Explicație
Niciun număr nu are cel puțin 100 de divizori, deci suma este 0.
*/

#include <iostream>

using namespace std;

int main()
{
    int n,c=0,x,s=0,p;
    cin>>n>>p;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        for(int d=1;d*d<=x;d++)
        {
            if(x%d==0)
            {
               if(x/d==d)
                c++;
               if(x/d!=d)
                c=c+2;
            }
        }
        if(c>=p)
            s=s+x;
        c=0;
    }
    cout<<s;
    return 0;
}