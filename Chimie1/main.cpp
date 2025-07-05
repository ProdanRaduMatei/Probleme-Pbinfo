/*
Mateo este elev în clasa a 9-a și este pasionat atât de chimie cât și de informatică. El folosește de obicei două substanțe standard în cantități ce reprezintă două numere prime distincte, și a descoperit că anumite substanțe au în compoziție una sau chiar cele două substanțe standard în cantități ce reprezintă produsul cantităților celor două substanțe standard sau puteri ale acestora. El are în laborator un set de recipiente cu substanțe diferite și dorește să afle care este substanța de cantitate maximă care să aibă în componență una sau chiar cele două substanțe standard și de câte ori se regăsește această substanță de cantitate maximă.

Cerința
Pentru a-l ajuta pe Mateo căutați într-un sir de n numere cel mai mare element care are maximum doi divizori factori primi d1 si d2, reprezentând cele două substanțe standard și afișați de câte ori apare.

Date de intrare
Fișierul de intrare chimie1.in conține pe prima linie trei parametrii n, d1 și d2 cu semnificația din enunț, iar pe a doua linie n numere naturale separate prin spații.

Date de ieșire
Fișierul de ieșire chimie1.out va conține pe prima linie numărul m, reprezentând cel mai mare număr care respectă cerința și o variabilă ap care reprezintă numărul său de apariții. Dacă nu există niciun număr care respectă cerința se afișează mesajul NU EXISTA.

Restricții și precizări
1 ≤ n ≤ 1.000.000
1 < d1 < d2 < 33.000
numerele de pe a doua linie a fișierului de intrare sunt naturale și vor fi mai mici decât 33000
Exemplu:
chimie1.in

6 5 7
4 35 5 175 23 175
chimie1.out

175 2
Explicație
175 este format din 5 la puterea 2 si 7 la puterea 1. Mai apar în șir numere care respectă cerința, dar 175 este cel mai mare.
*/

using namespace std;
#ifdef EZ
   #include "./ez/ez.h"
   const string FILE_NAME = "test";
#else
   #include <bits/stdc++.h>
   const string FILE_NAME = "chimie1";
#endif
#define mp make_pair
#define mt make_tuple
#define ll long long
#define pb push_back
#define fi first
#define se second
#define cin fin
#define cout fout
ifstream fin (FILE_NAME + ".in");
ofstream fout (FILE_NAME + ".out");

int main()
{
   int n, d1, d2, max_nr = 0, max_cnt;
   cin >> n >> d1 >> d2;

   for (int i = 1; i <= n; ++i)
   {
      int x, xc;
      cin >> x;
      xc = x;

      if (x <= 1)
         continue;
      
      while (xc % d1 == 0)
         xc /= d1;
      while (xc % d2 == 0)
         xc /= d2;
      if (xc != 1)
         continue;
      
      if (x > max_nr)
      {
         max_nr = x;
         max_cnt = 1;
      }
      else if (x == max_nr)
         max_cnt ++;
   }

   if (max_nr == 0)
      cout << "NU EXISTA";
   else
      cout << max_nr << ' ' << max_cnt;
}