/*
Cerința
Pe prima linie a fișierului suminvdiv.in se găsesc cel mult 1000 de numere naturale distincte mai mici decât 10.000.000.000. Scrieți un program care determină pentru fiecare număr citit x suma s=1/d1+1/d2+..+1/di
, unde d1,d2,….,di
 sunt divizorii numărului x. Valorile determinate se vor afișa separate printr-un spațiu.

Date de intrare
Fișierul de intrare suminvdiv.in conține pe prima linie cel mult 1000 de numere naturale distincte mai mici decât 10.000.000.000 separate prin spații.

Date de ieșire
Fișierul de ieșire suminvdiv.out va conține pe prima linie valorile determinate cu exact 2 zecimale pentru fiecare număr x din fișierul de intrare, valori separate printr-un spațiu.

Restricții și precizări
pe prima linie a fișierului sunt cel mult 1000 de numere
numerele de pe prima linie a fișierului de intrare sunt mai mici decât 10.000.000.000
rezultatul este considerat corect dacă diferența dintre fiecare valoare afișată și cea corectă este mai mică decât 0.01
Exemplu:
suminvdiv.in

12 9 123 78 34 278313 349012 6 24242 900000
suminvdiv.out

2.33 1.44 1.37 2.15 1.59 1.58 1.75 2.00 1.71 3.55
Explicație
Divizorii lui 12 sunt: 1, 2, 3, 4, 6 și 12……s=(11+12+13+14+16+112)=2.33
Divizorii lui 9 sunt: 1, 3 și 9……s=(11+13+19)=1.44
, etc.
*/

#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main(void)
{
    unsigned int n, i;
    double s;

    ifstream fin("suminvdiv.in");
    ofstream fout("suminvdiv.out");

    while(fin >> n) {
        s = 1 + 1 / (float)n;
        if(n == 1) {
            fout << 1 << " ";
        } else {
            for(i = 2; i * i <= n; i++) {
                if(n % i == 0) {
                    s += 1 / (float)i;
                    if (n / i != i)
                        s += 1 / (float)(n / i);
                }
            }

            fout << fixed << setprecision(2) << s << " ";
        }
    }

    return 0;
}