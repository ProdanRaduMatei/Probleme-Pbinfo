/*
George a primit ca temă la matematică următoarea problemă. Se dă un număr X, asupra acestui număr se pot face următoarele transformări:

1) În această ordine (toți acești 3 pași reprezintă o transformare):

se înmulțește numărul cu 5 (de exemplu: X=416 devine 416*5=2080)
se elimină toate zerourile din număr (2080 devine 28)
se oglindește numărul (28 devine 82)
2) În această ordine (toți acești 3 pași reprezintă o transformare):

se înmulțește numărul cu 2 (de exemplu: X=32 devine 32*2=64)
se elimină toate zerourile din număr (64 rămâne 64)
se oglindește numărul (64 devine 46)
George trebuie să aplice alternativ cele două transformări asupra numărului X. Prima dată aplică transformarea 1, apoi pe rezultatul obținut se aplică transformarea 2, apoi pe rezultat se aplică iar transformarea 1, apoi iar transformarea 2 și așa mai departe. George trebuie să aplice asupra numărului X exact K transformări, în ordinea descrisă mai sus.

Cerința
Dându-se numerele X și K determinaţi:
1) Produsul dintre ultima cifră a numărului X * X * X * ... * X (de K ori) şi prima cifră a lui X.
2) Numărul rezultat după aplicarea celor K transformări.

Date de intrare
Pe prima linie a fișierului de intrare rotire25.in se află trei numere separate prin câte un spațiu C, X și K. Dacă C=1 se va rezolva doar prima cerință, iar dacă C=2 se va rezolva doar a doua cerință.

Date de ieșire
Fișierul de ieșire rotire25.out va conține un singur număr. Dacă C = 1, acest număr reprezintă rezultatul pentru prima cerinţă, iar dacă C = 2, acest număr reprezintă rezultatul pentru a doua cerință.

Restricții și precizări
1 ≤ X ≤ 999
1 ≤ K ≤ 1.000.000.000
Pentru teste în valoare de 29 de puncte, C = 1.
Pentru teste în valoare de 71 de puncte, C = 2.
Exemplul 1:
rotire25.in

1 27 3
rotire25.out

6
Explicație
Se rezolvă cerinţa 1: X = 27, K = 3. 27 * 27 * 27 = 19683 → ultima cifră este 3. Prima cifră a lui 27 este 2, deci rezultatul este 2 * 3 = 6

Exemplul 2:
rotire25.in

2 13 3
rotire25.out

551
Explicație
Se rezolvă cerinţa 2: X = 13, K = 3. Se fac urmatoărele transformări:

13 * 5 = 65, scoatem zerourile si rotim → 56
56 * 2 = 112, scoatem zerourile și rotim → 211
211 * 5 = 1055, scoatem zerourile → 155, rotim → 551
Exemplul 3:
rotire25.in

2 42 1782321
rotire25.out

12
Explicație
Se rezolvă cerinţa 2: X = 42, K = 1782321. După ce se fac cele K transformări se ajunge la numărul 12.


*/

#include <fstream>
#include <cmath>
using namespace std;
ifstream fin ("rotire25.in");
ofstream fout ("rotire25.out");

int operatie(int x, int inm)
{
   x *= inm;

   int ans = 0;
   while (x)
   {
      if (x%10 == 0)
      { x/=10; continue; }

      ans = ans*10 + x%10;
      x /= 10;
   }

   return ans;
}


int ultCifPutere(int a, int b)
{
   if (b == 0)
      return 1;

   a %= 10;
   if (a == 0 || a == 1 || a == 5 || a == 6)
      return a;
   return (int) pow(a, b%4 + 4) % 10;
}


int primaCif(int x)
{
   while (x > 9)
      x /= 10;
   return x;
}


int main()
{
   int c, x, k;
   fin >> c >> x >> k;

   if (c == 1)
   {
      fout << ultCifPutere(x, k) * primaCif(x);
   }

   if (c == 2)
   {
      // numerele se repeta cate doua..
      int num1 = operatie(x, 5);
      int num2 = operatie(num1, 2);
      int num3 = operatie(num2, 5);
      int num4 = operatie(num3, 2);

      if (k == 1)
         fout << num1;
      else if (k == 2)
         fout << num2;
      else
         if (k % 2 == 1)
            fout << num3;
         else
            fout << num4;
   }
}