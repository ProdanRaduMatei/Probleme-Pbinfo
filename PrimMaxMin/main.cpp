/*
Cerința
Se dă un șir cu n elemente, numere naturale nenule. Să se determine suma dintre cel mai mic și cel mai mare element prim din șir.

Date de intrare
Programul citește de la tastatură numărul n, apoi cele n elemente ale șirului.

Date de ieșire
Programul va afișa pe ecran numărul cerut.

Restricții și precizări
1 ≤ n ≤ 1.000
elementele șirului vor fi mai mici decât 1.000.000.000
șirul va conține cel puțin un element prim
Exemplu:
Intrare

5
18 23 13 40 37
Ieșire

50
Explicație
Cel mai mic element prim al șirului este 13, iar cel mai mare este 37. Suma lor este 50.
*/

#include <bits/stdc++.h>

using namespace std;

int n,i,mini=INT_MAX,maxi=INT_MIN,a,j,ok;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        ok=1;
        for(j=2;j*j<=a;j++)
        {
            if(a%j==0){ok=0;break;}
        }
        if(ok)
        {

            if(mini>a)mini=a;
            if(maxi<a)maxi=a;
        }
    }
    cout<<mini+maxi;
    return 0;
}