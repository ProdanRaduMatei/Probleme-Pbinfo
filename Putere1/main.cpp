/*
Cerința
Se dau numerele naturale b n p. Determinați numărul format din ultimele p cifre ale lui bn.

Date de intrare
Programul citește de la tastatură numerele b n p.

Date de ieșire
Programul va afișa pe ecran numărul format din ultimele p cifre ale lui bn.

Restricții și precizări
1 ≤ b ≤ 1000000
1 ≤ n < 231
1 ≤ p ≤ 9
Exemplu:
Intrare

2 10 2
Ieșire

24
Explicație
210=1024. Numărul format din ultimele 2 cifre ale lui 1024 este 24.
*/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

#include <iostream>
using namespace std;

long long p_b = 1;

long long Putere(long long a, long long b)
{
   if (b == 0)
      return 1;
   if (b & 1) // impar
      return a * Putere(a, b-1) % p_b;
   else
   {
      long long p = Putere(a, b/2);
      return p * p % p_b;
   }
}

int main()
{
   long long b, n, p, rezultat = 1, i;
   cin >> b >> n >> p;
   for (i = 0; i < p; ++i)
      p_b *= 10;
   
   cout << Putere(b, n);

   return 0;
}