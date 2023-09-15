/*
Cerința
Se desenează un șir de pătrate distincte, de latură: 1,2,3,4,….
Pătratele sunt numerotate cu numerele egale cu laturile lor. Fiecare pătrat este împărțit în pătrate elementare, adică pătrate de latură 1. De exemplu, un pătrat de latură k se împarte, trasând k-1 linii orizontale și k-1 linii verticale echidistante, în k*k pătrate elementare dispuse căte k pe fiecare rând, respectiv coloană. Începând de la primul pătrat desenat, parcurgând în spirală fiecare pătrat din șir, se numerotează toate pătratele elementare, ca în imaginea de mai jos:



În fiecare pătrat din șir, rândurile sunt numerotate de sus în jos cu numerele distincte 1,2,3…. Analog, coloanele sunt numerotate de la stânga la dreapta cu numerele distincte 1,2,3….

Dându-se un număr natural N să se determine:
1) Numărul P al pătratului din șir care conține pătratul elementar numerotat cu N;
2) Rândul R și coloana C în care este situat pătratul elementar cu numărul N în pătratul cu numărul P.

Date de intrare
Fișierul de intrare npe.in conține pe prima linie numărul N.

Date de ieșire
Fișierul de ieșire npe.out va conține pe prima linie cele trei numere naturale P R C determinate, separate prin câte un spațiu, cu semnificația din enunț.

Restricții și precizări
1 ≤ N ≤ 2.000.000.000
Pentru determinarea corectă a numărului P se acordă 40% din punctaj; pentru determinarea corectă a numărului R se acordă 30% din punctaj; pentru determinarea corectă a numărului C se acordă 30% din punctaj
Exemplu:
npe.in

52
npe.out

5 4 3
Explicație
Pătratul cu numărul P=5 conține pe rândul R=4 și coloana C=3 pătratul elementar cu numărul N=52.
*/

#include <fstream>
using namespace std;

/// calculeaza suma patratelor numerelor de la 1 pana la n
int sumaPatrat(int n)
{
   return (long long)n * (n+1) * (2*n+1)  /  6;
}

/// calculeaza linia, coloana si patratul in care se afla valoare nr
void LinColPatrat(int nr, int &lin, int &col, int &pat)
{
   long long s;
   int i, j;
   int val, X, Y; // y reprezinta linia, x reprezinta coloana, punctul de origine este punctul din stanga sus iar axa oy este inversata

// patrat
   s = 0;
   for (i = 1; s < nr; ++i)
      s += (long long)i * i;
   pat = i-1;

// linie, coloana
   val = sumaPatrat(pat-1) + 1;
   X = 1;
   Y = 1;

   // observam ca fiecare patrat se formeaza folosind  n numere, n-1 nr, n-1, n-2, n-2, ..., 2, 2, 1, 1
   for (i = pat; val != nr; )
   {
      for (j = 1; j < i && val != nr; ++j)
         X++, val++;//,cout<<X << ' '<< Y<<" Val:" << val << '\n';
      if (val != nr)
         Y++, val++;
      i--;
      for (j = 1; j < i && val != nr; ++j)
         Y++, val++;//,cout<<X << ' '<< Y<<" Val:" << val << '\n';
      if (val != nr)
         X--, val++;
      for (j = 1; j < i && val != nr; ++j)
         X--, val++;//,cout<<X << ' '<< Y<<" Val:" << val << '\n';
      i--;
      if (val != nr)
         Y--, val++;
      for (j = 1; j < i && val != nr; ++j)
         Y--, val++;//,cout<<X << ' '<< Y<<" Val:" << val << '\n';
      if (val != nr)
         X++, val++;
   }

   lin = Y;
   col = X;
}

int main()
{
   ifstream fin ("npe.in");
   ofstream fout ("npe.out");
   int n;
   int linie, coloana, patrat;
   fin >> n;

   LinColPatrat(n, linie, coloana, patrat);
   fout << patrat << ' ' << linie << ' ' << coloana;

   fin.close();
   fout.close();
   return 0;
}