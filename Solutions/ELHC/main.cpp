/*
După șase ani de lucru, Charles a terminat de curățat instalațiile pentru producerea negrului de fum din Copșa Mică. Pentru a se ține departe de mesele de Blackjack, el s-a angajat la CERN, unde va lucra la noul accelerator de particule numit Even Larger Hadron Collider (ELHC). ELHC are forma unui tunel circular cu o circumferință de P kilometri, P fiind un număr prim. De-a lungul tunelului sunt plasați P senzori numerotați de la 0 la P - 1, distanța dintre doi senzori consecutivi fiind de exact 1 kilometru.

Un experiment efectuat în ELHC constă în studierea unei particule de tip G, 1 ≤ G < P. Dacă această particulă este ridicată la nivelul de energie k și este lansată din dreptul senzorului 0 în direcția senzorului 1, ea va parcurge exact Gk kilometri prin tunel și apoi se va dezintegra, declanșând în acel moment senzorul s în dreptul căruia are loc dezintegrarea particulei. Se consideră că experimentul are date complete dacă, lansând P - 1 particule de tip G ridicate la toate nivelurile de energie k de la 1 la P - 1, este posibil să declanșăm toți senzorii s numerotați cu valori între 1 și P - 1, adică toți senzorii din tunel mai puțin senzorul 0.

Cerința
Dându-se T perechi de numere G și P, determinați dacă experimentul pentru studierea particulei de tip G într-un tunel de circumferință P produce date complete.

Date de intrare
Fișierul de intrare elhc.in conține pe prima linie un număr T, reprezentând numărul de experimente care vor fi efectuate. Pe fiecare din următoarele T linii se află câte două numere G și P separate printr-un spațiu, reprezentând efectuarea unui experiment cu o particulă de tip G într-un tunel de circumferință P.

Date de ieșire
În fișierul de ieșire elhc.out se va afla o singură linie cu T biți scriși unul după altul, adică fără spații între ei. Al i-ulea bit este 1 dacă pentru cel de-al i-lea experiment putem obține date complete, și 0 în
caz contrar.

Restricții și precizări
1 ≤ T ≤ 1 000
1 ≤ G < P < 1 000 000 000
P este un număr prim
Exemplu:
elhc.in

6
2 3
3 5
2 7
3 7
3 11
5 11
elhc.out

110100
Explicație
Fișierul de intrare conține T = 6 experimente.
A doua particulă are tipul 3 și va fi lansată printr-un tunel de circumferință 5, cu 5 senzori numerotați de la 0 la 4. Ridicată la nivelurile de energie 1, 2, 3, respectiv 4, și lansată de fiecare dată din dreptul senzorului 0, particula va călători 3, 9, 27, respectiv 81 de kilometri și va declanșa senzorii 3, 4, 2, respectiv 1. Aceștia sunt toți senzorii pe care trebuie să-i declanșăm, prin urmare experimentul produce date valide, deci al doilea bit din șirul afișat este 1.

A treia particulă are tipul 2 și va fi lansată printr-un tunel de circumferință 7. Ridicată la nivelurile de energie 1, 2, 3, 4, 5, respectiv 6, și lansată de fiecare dată din dreptul senzorului 0, particula va declanșa senzorii 2, 4, 1, 2, 4, respectiv 1. Deoarece nu declanșăm senzorii 3, 5 și 6, experimentul nu are date complete, deci al treilea bit din șirul afișat este 0.
*/

#include <bits/stdc++.h>

using namespace std;
ifstream fin("elhc.in");
ofstream fout("elhc.out");
int T, G, P, cnt;
int po(int b, int e, int M)
{
    if(e==0) return 1;
    else if(e%2==0)
    {
        int z = po(b,e/2,M);
        return (1LL*z*z)%M;
    }
    else return (1LL*b*po(b,e-1,M))%M;
}
int Factor(int nr)
{
    int d, p;
    while(nr%2==0)
    {
        p++;
        nr/=2;
    }
    if(p)
    {
        if(po(G,(P-1)/2, P)==1)
            return 1;
    }
    for(d=3; d*d<=nr; d+=2)
    {
        p=0;
        while(nr%d==0)
        {
            p++;
            nr/=d;
        }
        if(p)
        {
            if(po(G,(P-1)/d, P)==1)
                return 1;
        }
    }
    if(nr>1)
        if(po(G,(P-1)/nr, P)==1)
                return 1;
    return 0;
}
int main()
{
    fin>>T;
    for(int i=1; i<=T; ++i)
    {
        fin>>G>>P;
        if(G==1 && P==2)
            fout<<1;
        else
            fout<<!Factor(P-1);
    }
    return 0;
}