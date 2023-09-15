/*
Când adunăm două cifre c1 și c2, obținem transport dacă c1 + c2 ≥ 10. Când adunăm două numere naturale, se poate obține chiar de mai multe ori transport. De exemplu, dacă adunăm 538 și 726, atunci obținem de două ori transport, prima oară când adunăm cifrele unităților, 8 + 6, a doua oară când adunăm cifrele sutelor, 5 + 7.

Cerința
Se dau două numere naturale n și m care au același număr de cifre. Să se afișeze mesajul NU dacă adunând cele două numere cifră cu cifră nu obținem niciodată transport, sau mesajul DA, dacă obținem măcar o dată transport.

Date de intrare
Programul citește de la tastatură numerele n și m.

Date de ieșire
Programul va afișa pe ecran mesajul NU dacă adunând cele două numere cifră cu cifră nu obținem niciodată transport, sau mesajul DA, dacă obținem măcar o dată transport.

Restricții și precizări
1 ≤ n, m ≤ 1.000.000.000
numerele n și m au același număr de cifre
Exemplul 1:
Intrare

538 726
Ieșire

DA
Exemplul 2:
Intrare

1234 8765
Ieșire

NU
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n, m;
   cin >> n >> m;

   bool ok = false;
   while (n)
   {
      if ((n % 10 + m % 10) >= 10)
         ok = true;
      n /= 10;
      m /= 10;
   }

   if (ok)
      cout << "DA";
   else
      cout << "NU";
}