/*
Cerința
Fie Z un număr natural în baza 10. Considerăm rkrk-1 … r1r0 scrierea numărului Z în baza 3.
Fie T = rkrk−1…r1r0¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 numărul în baza 10 format cu cifrele rk, rk-1, … r1, r0.
Notăm cu S restul împărțirii numărului T la 7.
Se dau N numere naturale Z1, Z2, … , ZN.
Pentru fiecare dintre numerele Z1, Z2, … , ZN se cere să se calculeze S1, S2, … , SN. (Si reprezintă restul împărțirii la 7 a numărului Ti iar Ti reprezintă numărul format cu cifrele scrierii în baza 3 a numărului Zi).

Date de intrare
Programul citește de la tastatură numărul N, iar apoi N numere naturale Z1, Z2, … , ZN, separate prin spații.

Date de ieșire
Programul va afișa pe ecran, pe câte o linie, numerele S1, S2, … , SN.

Restricții și precizări
1 ≤ N ≤ 40000
Z1, Z2, … , ZN vor fi mai mici decât 264
Exemplu:
Intrare

2
19 30
Ieșire

5
2
Explicație
S-au citit 2 numere: 19 și 30.
Numărul 19 în baza 3 se scrie: 201. Restul împărțirii numărului 201 la 7 este 5.
Numărul 30 în baza 3 se scrie: 1010. Restul împărțirii numărului 1010 la 7 este 2.
*/

#include <iostream>
using namespace std;

int main()
{
   unsigned long long n, x;
   cin >> n;
   while (n--)
   {
      cin >> x;
      cout << x % 7 << '\n';
   }
   return 0;
}