/*
Gigel, pasionat de numere, știe că orice număr natural se scrie într-o bază de numerație b ca o succesiune de simboluri care au asociate valori de la 0 la b-1. De exemplu numărul 7, scris în baza 10, se scrie în baza 2 ca 111(2), iar numărul 26732, scris în baza 10, se scrie în baza 37 ca o succesiune de 3 simboluri, primele două având asociată valoarea 19, iar ultimul având asociată valoarea 18. El a descoperit că există numere care au proprietatea că se scriu, în exact două baze diferite, prin exact trei simboluri identice. De exemplu, numărul 931(10) se scrie în baza 11 ca 777(11), iar în baza 30 se scrie 111(30).

Cerința
Fiind dat un număr natural N, să se determine cel mai mare număr natural mai mic sau egal cu N, care are proprietatea că se scrie în exact două baze diferite prin exact 3 simboluri identice.
1. Să se scrie numărul determinat
2. Să se scrie cele două baze determinate și valorile simbolurilor respective.

Date de intrare
Fișierul de intrare cate3cifre.in conţine pe prima linie cerința (1 sau 2). Pe linia a doua a fișierului de intrare se află numărul natural N.

Date de ieșire
Fișierul de ieșire cate3cifre.out va conține pe prima linie, dacă cerința este 1, numărul determinat. Dacă cerința este 2, prima și cea de a doua linie a fișierului de ieșire au aceeași structură: pe fiecare linie se vor scrie, separate printr-un spațiu, două numere naturale b c, reprezentând baza și valoarea simbolului cerut din baza respectivă. Cele două baze se vor afișa în ordine crescătoare.

Restricții și precizări
0 < N ≤ 1000000
Pentru rezolvarea corectă a cerinței 1 se acordă 60 de puncte. Pentru cerința 2, se acordă 30 de puncte. Pentru 50 de puncte N ≤ 10000
Numărul xyz(b) scris în baza b cu simbolurile x, y, z se scrie în baza 10 ca o valoare calculată astfel: x • b2 + y • b + z (unde simbolurile x, y, z se înlocuiesc cu valorile asociate)
Pentru fiecare test există soluție.
În concurs s-au acordat 10 puncte din oficiu. Aici se acordă pentru exemplele din enunț.
Exemplul 1:
cate3cifre.in

1
1000
cate3cifre.out

931
Explicație
Numărul determinat este 931. Numărul determinat se scrie în baza 11 ca 777(11). Același număr se scrie în baza 30 ca 111(30)

Exemplul 2:
cate3cifre.in

2
1000
cate3cifre.out

11 7
30 1
Exemplul 3:
cate3cifre.in

1
30000
cate3cifre.out

26733
Explicație
Numărul determinat este 26733. Numărul determinat se scrie în baza 37 ca (19)(19)(19)(37). Același număr se scrie în baza 163 ca 111(163).

Exemplul 4:
cate3cifre.in

2
30000
cate3cifre.out

37 19
163 1
*/

#include <fstream>

using namespace std;
int C[4], B[4];
int n, m, i, st, dr, mid, j, nr, baza, cifra, k, t;

ifstream fin ("cate3cifre.in");
ofstream fout("cate3cifre.out");

int main () {
    fin>>t>>n;

    for (i=n;i>=2;i--) {
        nr = 0;
        for (baza=2;1+baza+baza*baza<=i;baza++) {
            if (i%(1+baza+baza*baza) != 0)
                continue;

            cifra = i/(1+baza+baza*baza);
            if (cifra < baza) {
                nr++;
                C[nr] = cifra;
                B[nr] = baza;
                if (nr == 3)
                    break;
            }
        }
        if (nr == 2) {
            if (t == 1)
                fout<<i;
            else
                fout<<B[1]<<" "<<C[1]<<"\n"<<B[2]<<" "<<C[2]<<"\n";
            return 0;
        }
    }
}