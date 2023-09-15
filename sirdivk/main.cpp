/*
Cu ajutorul a trei cifre date a, b, c, unde a > 0, se construieşte următorul şir de numere:

a,ab¯¯¯¯¯,abc¯¯¯¯¯¯¯,abca¯¯¯¯¯¯¯¯¯¯,abcab¯¯¯¯¯¯¯¯¯¯¯¯,abcabc¯¯¯¯¯¯¯¯¯¯¯¯¯¯,…
. De exemplu, pentru a=1, b=3, c=7, putem construi şirul:
1,13,137, 1371,13713, 137137, 1371371, 13713713, ...

Cerința
Scrieţi un program care determină câte numere divizibile cu k se găsesc în primii n termeni ai şirului dat.

Date de intrare
Fișierul de intrare sirdivk.in conține pe prima linie numerele a b c n k.

Date de ieșire
Fișierul de ieșire sirdivk.out conţine o singură linie pe care este scris numărul nr de numere divizibile cu k aflate printre primii n termeni ai şirului dat.

Restricții și precizări
1 < n < 1000
2 ≤ k < 32000
1 ≤ a ≤ 9, 0 ≤ b,c ≤ 9
Exemplu:
sirdivk.in

7 2 1 8 3 
sirdivk.out

2
Explicație
Printre primii 8 termeni ai şirului: 7, 72, 721, 7217, 72172, 721721, 7217217,  72172172,... există doi termeni divizibili cu 3.
*/

#include <fstream>
using namespace std;

// vom face impartirea numarului cel mai mare (cel format din n cifre) cifra cu cifra, cum se face la matematica.
// oricand vom gasi 0 in urma scaderilor de la impartire ( 5/2: 2*2 = 4, 5-4 = {[1]} ), vom aduna 1 la o variabila care incepe de la 0.
char abc_ = 'a';
int gasite;

int main()
{
   ifstream fin ("sirdivk.in");
   ofstream fout ("sirdivk.out");
   int i;
   int rest;
   int a, b, c, n, k;
   fin >> a >> b >> c >> n >> k;

   int numar[n];
   for (i = 0; i < n; i += 3)
      numar[i] = a;
   for (i = 1; i < n; i += 3)
      numar[i] = b;
   for (i = 2; i < n; i += 3)
      numar[i] = c;
   // `numar` este un vector care contine deja cifrele numarului format din n cifre

   rest = 0;
   for (i = 0; i < n; ++i)
   {
      rest = rest*10 + numar[i];
      if (rest % k == 0)
         gasite ++;

      rest %= k;
   }

   fout << gasite;

   fin.close();
   fout.close();
   return 0;
}