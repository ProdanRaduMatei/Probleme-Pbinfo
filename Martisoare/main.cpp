/*
Gică şi Lică lucrează la o fabrică de jucării, în schimburi diferite. Anul acesta patronul fabricii a hotărât să confecţioneze şi mărţişoare. Mărţişoarele gata confecţionate sunt puse în cutii numerotate consecutiv.

Cutiile sunt aranjate în ordinea strict crescătoare şi consecutivă a numerelor de pe acestea.
Gică trebuie să ia în ordine fiecare cutie, să lege la fiecare mărţişor câte un şnur alb-roşu şi apoi să le pună la loc în cutie.

În fiecare schimb, Gică scrie pe o tablă magnetică, utilizând cifre magnetice, în ordine strict crescătoare, numerele cutiilor pentru care a legat șnururi la mărțișoare.

Când se termină schimbul lui Gică, Lică, care lucrează în schimbul următor, vine şi ambalează cutiile cu numerele de pe tablă şi le trimite la magazine. Totul merge ca pe roate, până într-o zi, când, două cifre de pe tablă se demagnetizează şi cad, rămânând două locuri goale. Lică observă acest lucru, le ia de jos şi le pune la întâmplare pe tablă, în cele două locuri goale. Singurul lucru de care ţine cont este acela că cifra 0 nu poate fi prima cifră a unui număr.

Cerințe
Scrieţi un program care să citească numerele naturale N (reprezentând numărul de numere scrise pe tablă) şi c1, c2, …, cN (reprezentând numerele scrise, în ordine, pe tablă, după ce Lică a completat cele două locuri goale cu cifrele căzute) și care să determine:
a) cele două cifre care au fost schimbate între ele, dacă, după ce au completat locurile goale, acestea au schimbat șirul numerelor scrise de Gică;
b) numărul maxim scris pe tablă de Gică.

Date de intrare
Fișierul de intrare martisoare.in conține pe prima linie numărul natural N reprezentând numărul de numere de pe tablă. A doua linie a fişierului conţine, în ordine, cele N numere c1, c2, …, cN, separate prin câte un spaţiu, reprezentând, în ordine, numerele existente pe tablă, după ce Lică a completat cele două locuri libere cu cifrele căzute.

Date de ieșire
Fișierul de ieșire martisoare.out va conține pe prima linie două cifre, în ordine crescătoare, separate printr-un spațiu, reprezentând cele două cifre care au fost schimbate între ele sau 0 0 în cazul în care cele două cifre magnetice căzute, după ce au fost puse înapoi pe tablă, nu au schimbat șirul numerelor scrise de Gică. A doua linie va conține un număr reprezentând numărul maxim din secvenţa de numere consecutive scrisă de Gică pe tablă.

Restricții și precizări
4 ≤ N ≤ 100.000
1 ≤ ci ≤ 100.000, (1≤i≤N)
N, c1, c2, …, cN sunt numere naturale;
cele două cifre care cad de pe tablă pot proveni din același număr;
pentru rezolvarea cerinţei a) se acordă 60% din punctaj, iar pentru cerinţa b) se acordă 40% din punctaj.
Exemplul 1
martisoare.in

5
65 22 27 28 29
martisoare.out

2 6
29
Explicație
Gică a scris pe tablă, în ordine, numerele: 25 26 27 28 29
Au fost schimbate între ele cifra 2 din primul număr şi cifra 6 din al doilea număr. Cel mai mare număr scris de Gică pe tablă este 29.

Exemplul 2
martisoare.in

4
95 96 97 89
martisoare.out

8 9
98
Explicație
Gică a scris pe tablă, în ordine, numerele: 95 96 97 98
Au fost schimbate între ele cifrele ultimului număr.
Cel mai mare număr scris de Gică pe tablă este 98.

Exemplul 3
martisoare.in

5
35 36 37 38 39
martisoare.out

0 0
39
Explicație
Gică a scris pe tablă, în ordine, numerele: 35 36 37 38 39
Șirul numerelor nu a fost schimbat, cel mai mare număr fiind 39.
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream f("martisoare.in");
ofstream g("martisoare.out");
int v[100001];
int main()
{
    int i,x,k=1,y,n, a=0,b=0;
    f>>n>>x;
    v[1]=x; y=x;
    for(i=2;i<=n;i++)
    {
        f>>v[i];
        x=max(x,v[i]);
        y=min(y,v[i]);
    }
    if(y+n-1==x)
      {
          for(i=1; i<=n;i++,y++)
           if(v[i]!=y){a=v[i]; b=y; break;}
      }
    else
    {   int i=1;
        if(v[1]!=y && v[2]==y)
        {  if(v[3]==y+1){a=v[1]; b=y-1; x=b+n-1;}
              else {x=v[3]+n-3; a=v[3]-1;b=y;}
        }
        else
        { i=2;
          while(y+1==v[i] && i<=n){i++;y++;}
          a=v[i];b=y+1; x=y+(n-i+1);
        }
    }
    if(a*b)
    {
        while(a%10==b%10)
        {
            a=a/10; b=b/10;
        }
        a=a%10; b=b%10;
        if(a>b)swap(a,b);
    }
    g<<a<<" "<<b<<endl<<x<<endl;
    return 0;
}