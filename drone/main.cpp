/*
Moș Crăciun s-a modernizat, folosind drone pentru colectarea prăjiturilor primite în dar de la copii. El a folosit n drone de modele diferite. Fiecare dronă utilizată avea un cod din maximum 9 cifre inscripționat pe ea. A observat că anumite drone erau cam zgomotoase și a decis să le înlocuiască pentru anul viitor. A mai remarcat că la dronele zgomotoase codul avea următoarele caracteristici: prima cifră era mai mică decât 7 și produsul tuturor cifrelor era un număr par.

Cerința
Determinați câte drone trebuie înlocuite.

Date de intrare
Fișierul de intrare drone.in conține pe prima linie valoarea n, reprezentând numărul de drone folosite de Moș Crăciun. Pe liniile următoare sunt exact n numere naturale separate prin spații, reprezentând codurile fiecărei drone.

Date de ieșire
Fișierul de ieșire drone.out va conține numărul dronelor ce trebuie înlocuite.

Restricții și precizări
valoarea n și codurile dronelor sunt numere naturale cu maximum 9 cifre fiecare
3 < n < 2000000001
10 puncte se acordă pentru exemplul din enunț.
Exemplu:
drone.in

10
72143
999
300056
543
53331
180
4
12345
1
6
drone.out

6
Explicație
Numerele 300056, 543, 180, 4, 12345, 6 respectă toate cerințele: prima cifră este mai mică decât 7 și produsul tuturor cifrelor este par.
*/

#include <fstream>
using namespace std;
int i,n,x;
long long ct;
ifstream f("drone.in");
ofstream g("drone.out");
short int primcif(int a)
{
    while(a>9)
        a/=10;
    return a;
}
bool produs(int a)
{
    if(a%2==0) return 1;
    if(primcif(a)%2==0) return 1;
    while(a)
    {
        if(a%10%2==0) return 1;
        a/=10;
    }
    return 0;
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x;
        if(primcif(x)<7 && produs(x)) ct++;
    }
    g<<ct;
}