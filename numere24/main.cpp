/*
Se consideră răsturnatul unui număr natural valoarea obținută prin parcurgerea cifrelor acestuia de la dreapta la stânga. De exemplu, răsturnatul numărului 245 este 542. Un număr este palindrom dacă este egal cu răsturnatul său. De exemplu 121 este palindrom, iar numărul 21 nu este palindrom.
Se consideră inițial șirul numerelor naturale 0, 1, 2, 3, 4, …
Din acest șir se elimină numerele divizibile cu 10 și, după fiecare număr care NU este palindrom, se inserează răsturnatul său. Noul șir astfel obținut va fi 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 21, 13, 31, …

Cerința
Scrieți un program care să citească:
1. un număr natural n și să afișeze al n-lea număr eliminat din șirul inițial;
2. un număr natural x și să afișeze următoarele trei numere: n1 – numărul de apariții în noul șir ale numărului obținut din x prin eliminarea ultimei sale cifre; n2 – numărul de apariții în noul șir ale numărului obținut din x prin eliminarea ultimelor sale două cifre; n3 – numărul de apariții în noul șir ale numărului obținut din x prin eliminarea ultimelor sale trei cifre.
3. un număr natural k și să afișeze numărul valorilor de k cifre din noul șir.

Date de intrare
Fișierul de intrare numere24.in conține pe prima linie un număr natural C, care poate fi 1, 2 sau 3.
Pe linia a doua se găsește numărul natural n, dacă C=1, sau numărul natural x, dacă C=2 sau numărul natural k, dacă C=3, numerele având semnificația din enunț.

Date de ieșire
Dacă valoarea lui C este 1, se va rezolva numai cerința 1. În acest caz, în fişierul de ieşire numere24.out se va scrie al n-lea număr eliminat.
Dacă valoarea lui C este 2, se va rezolva numai cerința 2. În acest caz, în fişierul de ieşire numere24.out se vor scrie trei numere, n1, n2, n3, cu semnificația din enunț, în această ordine, separate prin câte spațiu.
Dacă valoarea lui C este 3, se va rezolva numai cerința 3. În acest caz, fişierul de ieşire numere24.out va conține numărul valorilor de k cifre din noul șir.

Restricții și precizări
1 ≤ n ≤ 2.000.000.000
1000 ≤ x ≤ 2.000.000.000
1 ≤ k ≤ 50 (1 ≤ k ≤ 18, pentru teste în valoare de 20 de puncte)
Pentru rezolvarea corectă a primei cerințe se acordă 10 puncte, pentru rezolvarea corectă a celei de a doua cerințe se acordă 25 de puncte, iar pentru rezolvarea corectă a celei de a treia cerințe se acordă 55 de puncte.
În concurs s-au acordat 10 puncte din oficiu. Aici se acordă 10 puncte pentru exemplele din enunț.
Exemplul 1:
numere24.in

1
2
numere24.out

10
Explicație
n=2 și al doilea număr eliminat este 10. (C fiind 1 se rezolvă numai cerința 1)

Exemplul 2:
numere24.in

2
1205
numere24.out

0 2 1
Explicație
x=1205, numărul 120 nu apare în șir, deci n1=0, 12 apare de două ori, deci n2=2, iar 1 apare o singură dată, deci n3=1 (C fiind 2 se rezolvă numai cerința 2)

Exemplul 3:
numere24.in

3
2
numere24.out

153
Explicație
k=2 și în noul șir sunt 153 de numere de câte 2 cifre. (C fiind 3 se rezolvă numai cerința 3)
*/

#include <fstream>
using namespace std;
ifstream fin("numere24.in");
ofstream fout("numere24.out");
long long p,x,k,n,i,ogl,aux,nr;
int main()
{
    fin>>p;
    if(p==1){fin>>n; fout<<(n-1)*10<<'\n';return 0;}
    if(p==2)
    {
        fin>>x;
        for(i=1;i<=3;i++)
        {
            x=x/10;ogl=0;aux=x;
            while(aux)ogl=ogl*10+aux%10,aux/=10;
            if(ogl==x)nr=1;else if(x%10==0)nr=0;
            else nr=2;
            fout<<nr<<' ';
        }
        return 0;
     }
     ///p=3  numere mari
      fin>>k;
     if(k==1){fout<<9<<'\n';return 0;}
     if(k==2){fout<<153<<'\n';return 0;}
     if(k==3){fout<<1530<<'\n';return 0;}
     if(k==4){fout<<16110<<'\n';return 0;}
     x=(k-1)/2;
     fout<<161;
     for(i=1;i<=k-x-3;i++)fout<<9;
     fout<<1;
     for(i=1;i<=x;i++)fout<<0;
    return 0;
}