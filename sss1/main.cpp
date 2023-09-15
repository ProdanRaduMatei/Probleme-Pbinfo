/*
Se dă un număr N, și un șir de N numere naturale nenule.

Cerința 1
Determinați suma valorilor aflate pe ultimele K poziții în șir (unde K reprezintă valoarea celei mai din dreapta cifre nenule a primei valori din șir).

Cerința 2
Ne imaginăm împărțirea șirului în secvențe în următorul mod: prima secvență este formată din primele L elemente, a doua este formată din următoarele L-1 elemente, a treia este formată din următoarele L-2 elemente și așa mai departe, ultima secvență este formată dintr-un singur element și acesta coincide cu ultimul element din șir. Considerând suma valorilor fiecărei secvențe, să se determine cea mai mare dintre aceste sume.

Date de intrare
Pe prima linie a fișierului sss.in se află două valori C și N separate printr-un spațiu. Pe linia a doua se află N numere naturale separate prin câte un spațiu. Pentru C = 1 se rezolvă doar cerința 1 iar pentru C = 2 se rezolvă doar cerința 2.

Date de ieșire
Fișierul sss.out conține un singur număr care reprezintă valoarea calculată conform cerinței.

Restricții și precizări
1 ≤ N ≤ 100.000
Valorile din șir sunt numere naturale nenule ≤ 100.000;
Se garantează că pentru testele în care C = 1 șirul are cel puțin K elemente;
Se garantează că valoarea lui N permite descompunerea conform descrierii, pentru testele care au C = 2;
Pentru teste în valoare de 51 de puncte avem C = 1;
Pentru 27 de puncte dintre testele în care C = 1, primul număr din șir are o cifră;
Pentru teste în valoare de 49 de puncte avem C = 2;
Pentru teste în valoare de 22 de puncte dintre cele care au C = 2, valoarea lui N este mai mică sau egală cu 10.
Denumirea problemei este o prescurtare de la “sume și secvențe”.
Exemplul 1:
sss.in

1 6
120 4 21 5 31 6
sss.out

37
Explicație
Ultima cifră nenulă a primului element din șir este 2. Suma ultimelor două valori din șir este 37.

Exemplul 2:
sss.in

2 10
1 4 2 1 3 6 1 6 5 3
sss.out

11
Explicație
Descompunerea se poate realiza în secvențe de lungimile 4, 3, 2 și 1. Sumele obținute pentru fiecare sunt: 8, 10, 11, 3.
*/

#include <iostream>
#include <fstream>
using namespace std;

int vcmddcn(int n)
{
    while(n)
        if(n%10)
            return n%10;
        else
            n/=10;
    return -1;
}

int main()
{
    int C,N;
    ifstream f("sss.in");
    f>>C>>N;
    int a[N+1],s[N+1];s[0]=0;
    for(int i=1;i<=N;++i)
        f>>a[i],s[i]=s[i-1]+a[i];
    ofstream g("sss.out");
    if(C==1)
    {
        int c=vcmddcn(a[1]),s=0;
        for(int i=N;i>N-c;--i)
            s+=a[i];
        g<<s;
    }
    else
    {
        int S,Max=0;
        for(int i=N,j=1;i>0;)
        {
            S=s[i]-s[i-j];
            Max=max(S,Max);
            i-=j;
            ++j;
        }
        g<<Max;
    }
    return 0;
}