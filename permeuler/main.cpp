/*
Cerința
Indicatorul lui Euler, φ(n) – câteodată numit funcția phi, e folosit pentru a determina câte numere pozitive mai mici decât n care sunt relativ prime cu n există. De exemplu, cum 1, 2, 4, 5, 7 și 8 sunt toate mai mici decât 9 și sunt relativ prime la 9, φ(9)=6. Numărul 1 e considerat a fi relativ prim cu toate numerele naturale, deci φ(1)=1. În mod interesant, φ(87109)=79180, și se poate observa că 87109 e o permutare a lui 79180.

Se consideră un șir de cel mult 10000 de numere naturale distincte mai mici decât 10.000.000. Să se scrie un program care găsește valoarea lui n, pentru care φ(n) e o permutare a lui n și fracția n/φ(n) are valoare minimă. Dacă sunt mai multe valori cu aceeași proprietate atunci se scrie prima valoare din șir. Dacă nu sunt valori cu proprietatea menționată se va scrie valoarea 0.

Date de intrare
Fișierul de intrare permeuler.in conține pe prima linie cel mult 10000 de numere naturale distincte mai mici decât 10.000.000, separate prin spații.

Date de ieșire
Fișierul de ieșire permeuler.out va conține pe prima linie primul număr x pentru care φ(x) e o permutare a lui x și fracția x/φ(x) are valoare minimă.

Restricții și precizări
în fișier sunt cel mult 10000 de numere
numerele de pe prima linie a fișierului de intrare vor fi mai mici decât 10.000.000
Exemplu:
permeuler.in

1000 345 21 34567 5678 63 345678 1234
permeuler.out

21
Explicație
În fișierul de intrare sunt 2 numere care îndeplinesc proprietatea cerută de problemă: 21 care are φ(21)=12 și raportul 21/φ(21)=1.75 și 63 care are  φ(63)=36  și raportul  63/φ(63)=1.75. În fișierul de ieșire va fi scrisă valoarea 21.
*/

#include <fstream>
using namespace std;

int Phi(int n)
{
    int d;
    unsigned long long int nrp=n,prod=1;
    if(n%2==0)
    {
        while(n%2==0)
            n/=2;
        nrp*=(2-1),prod*=2;
    }
    d=3;
    while(n>1)
    {
        if(n%d==0)
        {
            while(n%d==0)
                n/=d;
            nrp*=d-1,prod*=d;
        }
        else
            d+=2;
        if(n>1&&d*d>n)
        {
            nrp*=n-1,prod*=n;
            break;
        }
    }
    return (int) (nrp/prod);
}

bool perm(int x,int y)
{
    if(x==y)
        return false;
    int Cx[10],Cy[10];
    for(int i=0;i<=9;++i)
        Cx[i]=Cy[i]=0;
    while(x)
        ++Cx[x%10],x/=10;
    while(y)
        ++Cy[y%10],y/=10;
    for(int i=0;i<=9;++i)
        if(Cx[i]!=Cy[i])
            return false;
    return true;
}

int main()
{
    int x,sol=0;
    double Min=1000000000;
    ifstream f("permeuler.in");
    while(f>>x)
    {
        int p=Phi(x);
        if(perm(x,p))
        {
            double t=1.0*x/p;
            if(t<Min)
                Min=t,sol=x;
        }
    }
    ofstream g("permeuler.out");
    g<<sol;
    return 0;
}