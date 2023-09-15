/*
Cerinţa
Se citesc de la tastatură numere naturale până la apariția lui zero. Să se determine suma celor pare și câte dintre ele au două cifre.

Date de intrare
Programul citește de la tastatură numere naturale. Citirea se încheie la introducerea valorii 0.

Date de ieşire
Programul afișează pe ecran numerele S C, separate prin câte un spatiu, reprezentând suma celor pare și numărul celor cu două cifre.

Restricţii şi precizări
numerele citite vor fi mai mici decât 10000
valoarea absolută a sumei nu va depăși 109
Exemplu:
Intrare

105 63 20 4 0
Ieșire

24 2

*/

#include <bits/stdc++.h>

using namespace std;


int a,sum,cnt;
int main()
{
    cin>>a;
    while(a!=0)
    {
        if(a%2==0)sum+=a;
        if(a/100==0&&a/10!=0)cnt++;
        cin>>a;
    }
    cout<<sum<<" "<<cnt;


    return 0;
}