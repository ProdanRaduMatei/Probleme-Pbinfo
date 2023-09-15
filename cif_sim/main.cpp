/*
Pentru un număr natural n vrem să verificăm dacă toate cifrele sale egal depărtate de extremități au suma egală cu 9. De exemplu, n = 314586 are perechile de cifre egal depărtate de extremități (3, 6), (1,8) și (4,5). Se obțin sumele 3+6=9, 1+8=9 și 4+5=9. Numărul 386 are perechile (3,6) și (8,8) pentru că având număr impar de cifre, atunci 8 are pereche pe el însuși.

Cerința
Dat n, afișați mesajul DA dacă toate cifrele sale egal depărtate de extremități au suma egală cu 9, sau afișați NU dacă există cel puțin o pereche care nu are suma 9.

Date de intrare
Programul citește de la tastatură numărul n

Date de ieșire
Programul va afișa pe ecran DA dacă toate cifrele sale egal depărtate de extremități au suma egală cu 9, sau NU în caz contrar.

Restricții și precizări
1 ≤ n ≤ 1018
Exemplul 1:
Intrare

314586
Ieșire

DA
Exemplul 2:
Intrare

386
Ieșire

NU
*/

#ifdef EZ
   #include "./ez/ez.h"
#else
   #include <bits/stdc++.h>
#endif
#define mp make_pair
#define mt make_tuple
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;

long long x;

int main()
{
   cin.tie(0)->sync_with_stdio(0);
   
   cin >> x;

   int nrcif = log10(x) + 1;
   bool ok = true;
   
   for (long long p = pow(10, nrcif-1); p; p /= 100)
   {
      int cif1 = x / p;
      int cif2 = x % 10;
      if (cif1 + cif2 != 9)
         ok = false;
      
      x %= p; // scoatem prima cifra
      x /= 10; // scoatem ultima cifra
   }

   cout << (ok ? "DA" : "NU");
}