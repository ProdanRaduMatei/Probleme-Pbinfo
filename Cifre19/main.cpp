/*
Cerinţă
Să se scrie un program care citește un număr natural n cu cifrele distincte și schimbă între ele cea mai mare și cea mai mică cifră a lui n.

Date de intrare
Programul va citi de la tastatură numărul n.

Date de ieşire
Programul va afişa pe ecran valoarea lui n, după transformarea cerută.

Restricţii şi precizări
10 ≤ n < 1.000.000.000
cifrele lui n sunt distincte
Exemplu 1
Intrare

31526
Ieşire

36521
*/

#include <iostream>

using namespace std;

int a[11], k, i, maxim, minim, poz_max, poz_min;
long long n;

int main()
{
    cin>>n;
    maxim=-1;
    minim=10;
    poz_max=0;
    poz_min=0;
    k=1;
    while(n)
    {
        if(n%10>maxim)
        {
            maxim=n%10;
            poz_max=k;
        }
        else if(n%10<minim)
        {
            minim=n%10;
            poz_min=k;
        }
        a[k]=n%10;
        k++;
        n=n/10;
    }
    a[poz_min]=maxim;
    a[poz_max]=minim;
    for(i=k-1;i>=1;i--)
        cout<<a[i];
    return 0;
}