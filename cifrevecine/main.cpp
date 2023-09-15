/*
Cerința
Se dau două numere naturale n și k. Determinați cea mai mare valoare care se poate obține eliminând din numărul n exact k cifre aflate pe poziții alăturate(una după alta).

Date de intrare
Fișierul de intrare va conține pe prima linie numărul n și pe a doua linie nunărul k.

Date de ieșire
În fișierul de ieșire se va scrie pe prima linie valoarea cerută.

Restricții și precizări
n este un număr cuprins între 10 și 1017 inclusiv.
1 ≤ k < numărul de cifre ale lui n.
pentru 50 de puncte k este 1.
Exemplul 1:
cifrevecine.in

10002
3
cifrevecine.out

12
Exemplul 2:
cifrevecine.in

1938
2
cifrevecine.out

38
*/
#include <fstream>
#include <vector>

typedef unsigned long long ull;


// formeaza numarul cu cifrele de la pozitiile [pos1, pos2] si [pos3, pos4], in ordinea in care apar in vector
ull formNumar(std::vector<int> cif, int pos1, int pos2, int pos3, int pos4)
{
   int i;
   ull x = 0;
   if (pos1 != -1 && pos2 != -1)
      for (i = pos1; i <= pos2; ++i)
         x = x*10 + cif[i];
   if (pos3 != -1 && pos4 != -1)
      for (i = pos3; i <= pos4; ++i)
         x = x*10 + cif[i];

   return x;
}


int main()
{
   std::ifstream fin ("cifrevecine.in");
   std::ofstream fout ("cifrevecine.out");
   ull n;   int k;
   ull max, x;   int i;
   fin >> n >> k;

   std::vector<int> cif_n;
   for (; n != 0; n /= 10)
      cif_n.insert(cif_n.begin(), n%10);

   max = formNumar(cif_n,  0, cif_n.size()-k-1,  -1 ,-1); // numarul din primele cifre
   x = formNumar(cif_n,  k, cif_n.size()-1,  -1, -1); // numarul din ultimele cifre
   max = std::max(max, x);
   for (i = 1; i < cif_n.size()-k; ++i)
   {
      x = formNumar(cif_n,  0, i-1,  k+i, cif_n.size()-1);
      max = std::max(max, x);
   }

   fout << max;

   fin.close();
   fout.close();
   return 0;
}