/*
Un pitic pasionat de numere trebuie să-și pună flori în grădină. El are de plantat m rânduri cu flori, aceeași floare pe tot rândul. Rândurile sunt numerotate de la 1 la m. Având la dispoziție suficiente specii de flori, piticul nostru s-a gândit să le planteze folosind următorul algoritm matematic: pe rândurile care sunt numere prime, va planta exact floarea numerotată cu numărul prim respectiv, iar pe celelalte rânduri va planta floarea numerotată cu suma divizorilor primi ai numărului neprim.

Cerința
Să se realizeze un program care să afişeze ordinea de așezare a florilor pe cele m rânduri.

Date de intrare
Fișierul de intrare pitic.in conține pe prima linie numărul m.

Date de ieșire
Fișierul de ieșire pitic.out va conține pe prima un șir de m numere, separate prin câte un spațiu, fiecare număr reprezentând specia de floare ce urmează să fie plantată pe rândul respectiv.

Restricții și precizări
1 ≤ m ≤ 1000
Exemplu:
pitic.in

6
pitic.out

0 2 3 2 5 5
*/

#include <iostream>
#include <fstream>
#include <math.h>



using namespace std;

int main()
{
    int m, i, d, s, p, x;
    bool prim;
    ifstream f("pitic.in");
    ofstream g("pitic.out");
    f>>m;
    for(i=1;i<=m;i++)
    {
       prim=true;
       d=2;
       if(i == 1)
            prim = false;
       while(d<=sqrt(i)&&prim)
       {
          if(i%d==0)
            prim=false;
          d++;
        }
       if(prim)
            g<<i<<" ";
       else
       {
           s=0;
           x=i;d=2;
           while(x!=1)
           {
               p=0;
               while(x%d==0)
               {
                   p++;x=x/d;
               }
               if(p!=0)
                s=s+d;
               d++;
           }
           g<<s<<" ";
       }
    }

    return 0;
}