/*
Cerința
Se dă un număr k și un șir cu n elemente, numere naturale nenule. Să se determine suma elementelor șirului pentru care suma exponenților din descompunerea în factori primi este cel puțin k.

Date de intrare
Programul citește de la tastatură numerele k n, apoi cele n elemente ale șirului.

Date de ieșire
Programul va afișa pe ecran numărul cerut.

Restricții și precizări
1 ≤ n ≤ 1.000
elementele șirului vor fi mai mici decât 1.000.000.000
Exemplu:
Intrare

3 5
30 23 13 40 60
Ieșire

130
Explicație
Elementele șirului pentru care suma exponenților din descompunerea în factori primi este cel puțin 3 sunt 30 40 60. Suma lor este 130.
*/

#include <bits/stdc++.h>

using namespace std;
int prod(int a,int k)
{
    int i,sum=0,cnt;
    for(i=2;i<=a;i++)
    {
        cnt=0;
        while(a%i==0)
        {
            cnt++;
            a/=i;
        }
        if(cnt!=0)sum+=cnt;

        if(i*i>a&&a>1)i=a-1;
    }
    if(sum>=k)return 1;
    return 0;
}



long long int k,n,a,sum,aux,i;
int main()
{
    cin>>k>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        aux=prod(a,k);
        if(aux)sum+=a;
    }
    cout<<sum;
    return 0;
}