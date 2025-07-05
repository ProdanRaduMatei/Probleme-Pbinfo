/*
Cerința
Se citesc două numere naturale a și b (a < b) având cel mult 9 cifre fiecare. Afișați câte numere din intervalul [a, b] au exact 3 divizori.

Date de intrare
Programul citește de la tastatură numerele a și b, separate printr-un spațiu.

Date de ieșire
Programul va afișa pe ecran numărul de numere din intervalul [a,b] care au exact 3 divizori.

Restricții și precizări
1 ≤ a < b < 1.000.000.000
Exemplu:
Intrare

11 50
Ieșire

2
Explicație
Numerele din intervalul [11,50] care au exact 3 divizori sunt 25 și 49.
*/

#include <iostream>
#include <cmath>
#define ciurlim 32767
#define _1 false
#define _0 true
using namespace std;

bool prime[ciurlim];

void ciur()
{
   prime[0] = prime[1] = _0;
   int i, j, k;
   for (i = 4; i < ciurlim; i += 2)
      prime[i] = _0;
   for (i = 3; i < ciurlim; i += 2)
   {
      if (prime[i] == _1)
      {
         k = i*2;
         for (j = i*3; j < ciurlim; j += k)
            prime[j] = _0;
      }
   }
}

int main()
{
   // numere care au numar impar de divizori sunt doar cele patrate perfecte.
   // de ce? fiecarui numar care nu este patrat perfect, putem sa ii asociem fiecarui divizor un alt divizor al numarului care, inmultiti, dau numarul initial.
   // 50 -> 1*50, 2*25, 5*10.
   // 36 -> 1*36, 2*18, 3*12, 4*9, 6.
   // pentru ca 36 este patrat perfect, divizorului 6 ii asociem tot divizorul 6, doar ca numarul de divizori nu se aduna cu 2, ci cu 1.
   // de aceea, patratele perfecte au numar impar de divizori.

   // pentru ca un numar sa aiba 3 divizori, trebuie sa fie in primul rand patrat perfect, iar in al doilea numarul care se repeta de doua ori (pt 36, nr este 6) sa nu aiba mai mult de 2 divizor.
   // inafara de 2, numerele pare au mai mult de 2 divizori
   ciur();
   int a, b, sta, end, cate = 0;
   cin >> a >> b;

   sta = sqrt(a);
   if (sta*sta < a)
      sta++;
   if (sta % 2 == 0)
      sta++;
   end = sqrt(b);
   if (sta <= 2 && end >= 2)
      cate++; // 4 este exceptie
   if (sta == 1)
      sta += 2;

   for (; sta <= end; sta += 2)
      if (prime[sta] == _1)
         cate++;

   cout << cate;
   return 0;
}