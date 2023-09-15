/*
Maria a aflat că numerele naturale care încep cu cifra 1 și au toate cifrele ordonate strict crescător şi consecutive sau încep cu cifra 9 și au toate cifrele ordonate strict descrescător şi consecutive se numesc numere speciale. Interesată să descopere legătura dintre numerele speciale cu același număr de cifre, a observat că poate construi tabelul alăturat.

Cerinţe
Scrieţi un program care citind patru numere naturale K, N, A şi B determină:

1) cel mai mare număr special situat în tabel pe linia K;
2) numărul special obţinut din numărul N prin ştergerea unei cifre;
3) numărul de numere speciale din mulțimea {A , A +1, A+2, A+3…,B-1,B}.

Date de intrare
Fișierul de intrare speciale.in conține pe prima linie un număr natural P. Pentru toate testele de intrare, numărul P poate avea doar valoarea 1, valoarea 2 sau valoarea 3. Pe a doua linie a fișierului speciale.in se găsesc, în această ordine, numerele naturale K, N, A și B, separate prin câte un spațiu.

Date de ieșire
Dacă valoarea lui P este 1, se va rezolva numai punctul 1) din cerințe. În acest caz, fişierul de ieşire speciale.out va conține pe prima linie un număr natural reprezentând cel mai mare număr special situat în tabel pe linia K.

Dacă valoarea lui P este 2, se va rezolva numai punctul 2) din cerințe. În acest caz, fişierul de ieşire speciale.out va conține pe prima linie un număr natural reprezentând numărul special obţinut din numărul N prin ştergerea unei cifre sau 0 dacă un astfel de număr nu se poate obţine;

Dacă valoarea lui P este 3, se va rezolva numai punctul 3) din cerințe. În acest caz, fişierul de ieşire speciale.out va conține pe prima linie un număr natural reprezentând numărul de numere speciale din mulțimea {A , A +1, A+2, A+3…,B-1,B}.

Restricții și precizări
1 ≤ K ≤ 9
1 ≤ N ≤ 999999999
1 ≤ A  ≤ B ≤ 999999999
Pentru rezolvarea corectă a primei cerinţe se acordă 20 de puncte, pentru rezolvarea corectă a celei de a doua cerințe se acordă 40 de puncte, pentru rezolvarea corectă a celei de a treia cerințe se acordă 40 de puncte.
Exemplul 1
speciale.in

1
3 125345 320 888888
speciale.out

987
Explicație
P = 1, pentru acest test, se rezolva cerința 1). Numerele speciale de pe linia a treia a tabelului sunt 123 și 987, cel mai mare fiind 987.

Exemplul 2
speciale.in

2
3 125345 320 888888
speciale.out

12345
Explicație
P = 2, pentru acest test, se rezolva cerința 2). Ștergând cifra 5 aflată pe poziția a treia în 125345 se obține numărul special 12345.

Exemplul 3
speciale.in

3
3 125345 320 888888
speciale.out

6
Explicație
P = 3, pentru acest test, se rezolvă cerința 3). Sunt 6 numere speciale în mulțimea {320, 321,..., 888888} și anume 987, 1234, 9876, 12345, 98765, 123456
*/

#include <fstream>
using namespace std;

int speciale[18] = {1, 9, 12, 98, 123, 987, 1234, 9876, 12345, 98765, 123456, 987654, 1234567, 9876543, 12345678,
                    98765432, 123456789, 987654321};

bool esteSpecial(int x)
{
   int st = 0, dr = 17, mij;

   while (st <= dr)
   {
      mij = (st + dr) /2;

      if (x < speciale[mij])
         dr = mij - 1;
      else if (x > speciale[mij])
         st = mij + 1;
      else
         return true;
   }

   return false;
}

int main()
{
   ifstream fin ("speciale.in");
   ofstream fout ("speciale.out");
   int cer, k, n, a, b;
   fin >> cer >> k >> n >> a >> b;

   if (cer == 1)
   {
      for (int i = 0; i < k; ++i)
         fout << 9 - i;
   }
   else if (cer == 2)
   {
      int nr_nou;
      long long p = 1;

      while (p <= (long long)n)
      {
         nr_nou = (n / p / 10) * p  +  n % p;
         if (esteSpecial(nr_nou))
         {
            fout << nr_nou;
            return 0;
         }

         p *= 10;
      }

      fout << 0;
   }
   else if (cer == 3)
   {
      int numere_count = 0;

      for (int i = 0; i < 18; ++i)
         if (a <= speciale[i] && speciale[i] <= b)
            numere_count ++;

      fout << numere_count;
   }
   return 0;
}