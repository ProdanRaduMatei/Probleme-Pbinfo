/*
Se dă următorul şir de numere:
1  1 2 2   1 2 3 3 3   1 2 3 4 4 4 4   1 2 3 4 5 5 5 5 5...
În şir avem grupe formate după următoarea regulă: grupa g conţine numerele naturale de la 1 la g în ordine crescătoare, urmate de g-1 valori egale cu g (g=1, 2, ...).

Cerința
Scrieţi un program care citeşte o valoare k şi afişează al k-lea termen al şirului de mai sus.

Date de intrare
Fișierul de intrare ksir.in conţine pe prima linie numărul natural k.

Date de ieșire
Fișierul de ieșire ksir.out va conţine o singură linie pe care va fi scris un număr natural ce reprezintă al k-lea element din şir.

Restricții și precizări
1 ≤ k ≤ 20.000.000.000
Poziţiile termenilor din şir sunt numerotate începând cu 1.
Exemplu:
ksir.in

8
ksir.out

3
Explicație
Al 8-lea element din şir este 3.
*/

#include <fstream>

using namespace std;

ifstream fin("ksir.in");
ofstream fout("ksir.out");

long long int k, total, grupa;

int main() {
    fin>>k;
    grupa=1;
    total=0;
    while (total+2*grupa-1<k) {
        total+=2*grupa-1;
        grupa++;
    }
    if (k-total<=grupa)
        fout<<k-total<<'\n';
    else
        fout<<grupa<<'\n';
    fout.close();
    return 0;
}