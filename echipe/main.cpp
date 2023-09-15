/*
În cadrul unui joc, echipele se formează după următoarea regulă: numărul echipei stabilește câți membri are echipa respectivă, adică echipa cu numărul 7 are 7 membri, echipa cu numărul 10 are 10 membri. Nu există echipă incompletă și echipele se formează pe rând, în ordine crescătoare (prima dată echipa cu numărul 1, apoi echipa cu numărul 2, …). Dacă ultima echipă nu va fi completă, acele persoane nu participă la joc (pot face galerie).

Cerința
Aflați câte persoane nu pot participa la joc.

Date de intrare
Fișierul de intrare echipe.in conține pe prima linie valoarea n, reprezentând numărul de persoane care vor să participe la joc.

Date de ieșire
Fișierul de ieșire echipe.out va conține numărul de persoane care nu au putut fi incluse într-o echipă completă.

Restricții și precizări
1 ≤ n ≤ 1 000 000
10 puncte se acordă pentru exemplele din enunț
Exemplul 1:
echipe.in

12
echipe.out

2
Explicație
Se pot forma echipe cu 1, 2, 3 și 4 jucători, deci 4 echipe complete care vor avea în total 10 jucători. Numărul de persoane care nu pot participa este 2.

Exemplul 2:
echipe.in

15
echipe.out

0
Explicație
Se pot forma echipe cu 1, 2, 3, 4 și 5 jucători deci 5 echipe complete care vor avea în total 15 jucători. Toți participă la joc.


*/

#include <fstream>

using namespace std;

int d,n;
ifstream f("echipe.in");
ofstream g("echipe.out");

int main()
{
    f>>n;
    for(d=1;d*(d+1)/2<=n;d++)
        if(d*(d+1)/2==n)
        {
            g<<0;
            return 0;
        }
    g<<n-d*(d-1)/2;
    return 0;
}