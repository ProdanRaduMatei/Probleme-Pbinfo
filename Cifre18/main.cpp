/*
Cerinţă
Să se scrie un program care citește un număr natural n și o valoare nenulă k, cel mult egală cu numărul de cifre ale lui n. Să se mărească a k cifră din n cu 1 dacă este mai mică decât 9 și să se înlocuiască cu 0 în caz contrar.

Date de intrare
Programul va citi de la tastatură numerele n k.

Date de ieşire
Programul va afişa pe ecran valoarea lui n, după transformarea cerută.

Restricţii şi precizări
n ≤ 2.000.000.000
Exemplu 1
Intrare

31615 4
Ieşire

31625
Explicație
A patra cifră a lui n=32615 este 1. Deoarece este mai mică decât 9 se va mări cu 1, deci n devine 32625.

Exemplul 2
Intrare

32695 4
Ieşire

32605
Explicație
A patra cifră a lui n=32615 este 9. În acest caz se înlocuiește cu 0, deci n devine 32605.
*/

#include <iostream>

using namespace std;

int m, k, i, a[11];
long long n, aux;

int main()
{
    cin>>n>>k; ///citim numărul n și poziția k
    aux=n; ///memorăm valoarea lui n într-o variabilă auxiliară
    m=1;
    while(aux>0)
    {
        a[m]=aux%10;
        aux=aux/10;
        m++;
    }
    if(a[m-k]<9) a[m-k]=a[m-k]+1;
    else a[m-k]=0;
    for(i=m-1;i>=1;i--)
        cout<<a[i];
    return 0;
}