/*
Cerința
Să se scrie un program care citește un număr natural n și care crește cu 1 valoarea cifrelor pare. De exemplu, dacă n=1234 atunci se va obține numărul 1335, iar dacă n=135 atunci numărul rămâne neschimbat.

Date de intrare
Programul citește de la tastatură numărul n.

Date de ieșire
Programul va afișa pe ecran numărul obținut prin creșterea cu 1 a cifrelor pare ale lui n.

Restricții și precizări
0 ≤ n ≤ 1.000.000.000
Exemplu:
Intrare

1234
Ieșire

1335
*/

// O(n * 2^n)
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin >> n;

   if (n == 0)
      cout << 1;
   else
   {
      for (int p = 1; p <= n; p *= 10)
         if (n/p % 10 % 2 == 0)
            n += p;
   
      cout << n;
   }
}