/*
Se citește un număr natural n. Acest număr se “împarte” în alte două numere x și y, astfel: x este format din cifrele din prima jumătate a lui n, y este format din cifrele din a doua jumătate a lui n. Dacă n are număr impar de cifre, cifra din mijloc va fi prima cifră a lui y. De exemplu, dacă n=88132, atunci x=88, iar y=132.

Cerința
Să se determine cel mai mare divizor comun al lui x și y.

Date de intrare
Fișierul de intrare jumatate1.in conține pe prima linie numărul n.

Date de ieșire
Fișierul de ieșire jumatate1.out va conține pe prima linie cel mai mare divizor
comun al lui x și y.

Restricții și precizări
Numărul n va avea cel mult 16 cifre.
Exemplu:
jumatate1.in

88132
jumatate1.out

44
Explicație
Numărul x este 88 iar numărul y este 132. Cel mai mare divizor comun al lor este 44.
*/

#include <cstdio>

using namespace std;
long long n,i,j,x,y,p,q,r;
int main()
{
    freopen("jumatate1.in","r",stdin);
    freopen("jumatate1.out","w",stdout);
    scanf("%lld\n",&n);
    p=q=1;
    while (n/q>0)
    {
        p*=10;
        q*=100;
    }
    x=n/p;  y=n%p;  r=x%y;
    while(r)
    {
        x=y;
        y=r;
        r=x%y;
    }
    printf("%lld\n",y);
    return 0;
}