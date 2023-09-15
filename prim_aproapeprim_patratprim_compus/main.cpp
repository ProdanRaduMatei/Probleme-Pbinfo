/*
Cerința
Un număr natural nenul este prim, dacă are exact doi divizori (ex. 7).
Un număr natural nenul se va numi pătrat prim, dacă este pătratul unui număr prim (ex. 49 = 7 * 7).
Un număr natural nenul se va numi aproape prim, dacă este produsul a două numere prime distincte (ex. 10 = 2 * 5).
Un număr natural nenul ce nu se încadrează în niciuna din cazurile de mai sus, se numeşte compus (ex. 8=2*2*2, 100=2*2*5*5).
Se citeşte un număr natural n. Să se identifice din ce categorie de mai sus face parte.

Date de intrare
Programul citește de la tastatură numărul n.

Date de ieșire
Programul va afișa pe ecran unul dintre mesajele: prim, aproape prim, patrat prim sau compus.

Restricții și precizări
1 < n ≤ 2.000.000.000
Exemplu:
Intrare

20
Ieșire

compus
Explicație
Numărul 20=2*2*5, deci este număr compus.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n,d1,d2;
    cin>>n;
    for (d1=2;d1*d1<=n;++d1)
        if (n%d1==0)
            break;
    if (n%d1!=0)
        cout<<"prim\n";
    else
        if (d1*d1==n)
            cout<<"patrat prim\n";
        else
        {
            d2=d1;
            for (d2=d1;d2*d2<=n/d1;++d2)
                if ((n/d1)%d2==0)
                    break;

            if ((n/d1)%d2==0)
              cout<<"compus\n";
            else
              cout<<"aproape prim\n";
        }
    return 0;
}