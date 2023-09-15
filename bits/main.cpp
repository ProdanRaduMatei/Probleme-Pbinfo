/*
Se dă un număr natural N.

Cerința
Determinați valoarea unor anumiți biți din reprezentarea sa în baza 2.

Date de intrare
Fișierul de intrare bits.in conține pe prima linie două numere naturale N și Q separate prin spațiu. Pe linia a doua se află Q numere naturale separate prin câte un spațiu.

Date de ieșire
Fișierul de ieșire bits.out conține pe prima linie Q valori, neseparate prin spațiu, reprezentând, în ordine, răspunsurile la întrebări.

Restricții și precizări
0 ≤ N ≤ 263-1
1 ≤ Q ≤ 63
valorile de pe a doua linie a fișierului de intrare sunt distincte și cuprinse între 0 și 62 (inclusiv)
biții se numerotează începând cu poziția 0 (cel mai puțin semnificativ)
numărul N este reprezentat pe 64 de biți
Exemplu:
bits.in

12 4
2 0 3 20
bits.out

1010
Explicație
Reprezentarea internă a valorii 12 este 000...0001100. Biții de pe pozițiile 0 și 20 au valoarea 0 iar cei de pe pozițiile 2 și 3 au valoarea 1.
*/

#include <iostream>
#include <fstream>
#include <bitset>
#include <string>

int main()
{
   std::ifstream fin("bits.in");
   std::ofstream fout("bits.out");

   unsigned long long n, q, p;
   fin >> n >> q;

   for (int i = 0; i < q; ++i)
   {
      fin >> p;
      fout << ((n >> p) & 1);
   }

   return 0;
}