/*
Cerinţă
Se dă un șir cu n elemente, numere naturale. Să se determine câte elemente ale șirului conțin cifra 0.

Date de intrare
Programul va citi de la tastatură numărul n, apoi cele n elemente ale șirului.

Date de ieşire
Programul va afişa pe ecran valoarea cerută.

Restricţii şi precizări
n ≤ 100
elementele șirului sunt mai mici decât 109
Exemplu
Intrare

5
18 205 1470 1256 70
Ieşire

3
Explicație
Elementele șirului care conțin cifra 0 sunt: 205 1470 70.
*/

#include <iostream>

using namespace std;

int i, k, n;
long long x;

int main()
{
    cin>>n;
    k=0;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        if(x==0) k++;
       while(x)
       {
           if(x%10==0)
           {
               k++;
               x=0;
           }
           x=x/10;
       }
    }
    cout<<k;
    return 0;
}