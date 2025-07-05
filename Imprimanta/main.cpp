/*
Cif-Oji6 este o imprimantă matriceală numită şi imprimantă cu ace, deoarece tipărirea se realizează prin impactul acelor capului de imprimare pe o bandă cu tuş.
Acele sunt aranjate într-o grilă dreptunghiulară formată din 5 rânduri de ace, pe fiecare rând aflându-se la distanţe egale câte 3 ace, aşa cum se observă în figura alăturată.
Prin acţionarea diferitelor combinaţii de ace din grilă, se defineşte forma fiecărei cifre ce permite tipărirea acesteia prin puncte, în felul următor:

         

De exemplu, cifra 2 va fi tipărită prin 11 puncte ca rezultat al acţionării a 11 ace din grilă: din primul rând de ace al grilei se vor acţiona toate cele 3 ace, din următorul rând doar acul din dreapta, apoi de pe următorul rând toate cele 3 ace, apoi acul din stânga de pe penultimul rând iar din ultimul rând toate cele 3 ace.

Cerințe
a) Ştiind că imprimanta Cif-Oji6 a tipărit numărul N, determinaţi care este cea mai mare cifră a numărul N pentru care s-a acţionat un număr minim de ace ale grilei.
b) Ştiind că imprimanta mai are tuş pe bandă doar pentru imprimarea a K puncte, determinaţi cel mai mare număr natural ce poate fi tipărit prin exact K puncte.

Date de intrare
Fișierul de intrare imprimanta.in conține pe prima linie două numere naturale N şi K separate printr-un spaţiu, unde N reprezintă numărul tipărit de imprimantă iar K numărul de puncte pentru care imprimanta mai are tuş.

Date de ieșire
Fișierul de ieșire imprimanta.out va conține:

pe prima linie un singur număr natural ce reprezintă cea mai mare cifră a numărul N pentru care s-a acţionat un număr minim de ace ale grilei.
pe cea de-a doua linie a fişierului se va scrie cel mai mare număr natural ce poate fi tipărit prin K puncte.
Restricții și precizări
10 ≤ N ≤ 1015
14 ≤ K ≤ 100000
Pentru rezolvarea corectă a cerinţei a) se acordă 30% din punctajul fiecărui test iar pentru rezolvarea corectă a cerinţei b) se acordă 70% din punctajul fiecărui test.
Exemplul 1
imprimanta.in

2852 16
imprimanta.out

5
74
Explicație
Pentru tipărirea cifrei 2 s-au acţionat 11 ace, pentru cifra 8 s-au acţionat 13 ace iar pentru cifra 5 tot 11 ace. Numărul minim de ace pentru tipărirea unei cifre este 11.
5 este cea mai mare cifră a numărului 2852 ce a fost tipărită cu 11 ace.
Cel mai mare număr natural ce poate fi tipărit prin 16 puncte este 74
7 puncte (pentru cifra 7) + 9 puncte (pentru cifra 4) = 16 puncte.

Exemplul 2
imprimanta.in

88 25
imprimanta.out

8
11111
Explicație
Pentru tipărirea cifrei 8 s-au acţionat 13 ace.
Cel mai mare număr natural ce poate fi tipărit prin 25 de puncte este 11111
5* (5 puncte pentru cifra 1) = 25 puncte.
*/

#include <fstream>
using namespace std;
int main()
{ ifstream fi("imprimanta.in"); ofstream fo("imprimanta.out");
  int k,i,cm,pm,r,p[10]={12,5,11,11,9,11,12,7,13,12};
  long long int n;
  fi>>n>>k; pm=15; cm=0;
  while (n>0)
  {  r=n%10; n/=10;
     if (p[r]<pm || (p[r]==pm && r>cm))
            {cm=r; pm=p[r];}
  }
fo<<cm<<"\n";
r=k%5; cm=k/5;
if (k==16) { fo<<74; cm=0;}
else
  switch (r)
  { case 0: break;
    case 1: fo<<777; cm-=4; break;
    case 2: fo<<7; cm--; break;
    case 3: fo<<8; cm-=2; break;
    case 4: fo<<77; cm-=2; break;
  }
for (i=0;i<cm;i++) fo<<1;
fo<<"\n";
return 0;
}