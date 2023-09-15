/*
Cerinţa
Se citesc de la tastatură numerele n k, apoi n numere naturale. Să se determine suma celor impare și câte dintre ele se divid cu k.

Date de intrare
Programul citește de la tastatură numerele n k, apoi n numere naturale.

Date de ieşire
Programul afișează pe ecran numerele S C, separate prin câte un spatiu, reprezentând suma celor impare și numărul celor care se divid cu k.

Restricţii şi precizări
n ≤ 50
numerele citite vor fi mai mici decât 10000
k > 0
Exemplu:
Intrare

4 3
104 63 22 5
Ieșire

68 1

*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,x,s=0,c=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x%2)
            s+=x;
        if(x%k==0)
            c++;
    }
    cout<<s<<" "<<c;
    return 0;
}