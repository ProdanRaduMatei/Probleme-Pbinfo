/*
Iliuță și Pandele au învățat la școală operații aritmetice cu numere naturale. Astfel cei doi frați exersează operațiile folosindu-se de o tablă. Iliuță spune un număr natural X, iar Pandele scrie pe tablă rezultatul înmulțirii tututor numerelor naturale de la 1 la X. Glumeț, Iliuță șterge cifrele egale cu 0 de la finalul numărului scris de Pandele.
Ca să îl ierte, Pandele spune și el un număr natural Y și îi cere lui Iliuță să determine un număr natural Z care este cel mai mare divizor al lui Y având un număr impar de divizori.

Cerința
Cunoscându-se numerele spuse de copii, scrieți un program care rezolvă următoarele cerințe:
1) afișează ultimele K cifre ale produsului calculat de Pandele, după ștergerea cifrelor egale cu 0 de la finalul acestuia;
2) afișează numărul Z cu semnificația de mai sus și numărul de divizori ai acestuia.

Date de intrare
Fișierul de intrare copii.in conține pe prima linie numărul C, care reprezintă numărul cerinței și poate avea doar valorile 1 sau 2. Pentru prima cerință fișierul conține pe a doua linie numărul X, iar pe cea de a treia linie numărul K. Pentru a doua cerință fișierul conține pe a doua linie numărul Y.

Date de ieșire
Pentru cerința 1), pe prima linie a fișierului copii.out se vor afișa cele K cifre cerute, fără spații, în ordine de la stânga la dreapta.
Pentru cerința 2), pe prima linie se vor afișa, în această ordine, numărul Z determinat și numărul de divizori ai acestuia. Numerele vor fi separate printr-un spațiu.

Restricții și precizări
1 ≤ X ≤ 106
1 ≤ Y ≤ 1012
1 ≤ K ≤ 9
Numărul rămas după ștergerea zerourilor de la finalul produsului are cel puțin K cifre;
Pentru rezolvarea primei cerințe se acordă 40 de puncte;
Pentru rezolvarea celei de a doua cerințe se acordă 60 de puncte.
Exemplul 1:
copii.in

1
12
3
copii.out

016
Explicație
Produsul 1*2*3*4*5*6*7*8*9*10*11*12 = 479001600. După ștergerea zerourilor de la finalul produsului, ultimele 3 cifre sunt 016.

Exemplul 2:
copii.in

2
14641
copii.out

14641 5
Explicație
Cel mai mare divizor al lui 14641 care are un număr impar de divizori este chiar 14641.

Exemplul 3:
copii.in

1
723432
9
copii.out

813433856
Explicație
După ștergerea zerourilor de la finalul produsului, ultimele 9 cifre sunt 813433856.

Exemplul 4:
copii.in

2
573194962208
copii.out

286597481104 105
Explicație
Cel mai mare divizor cu un număr impar de divizori este 286597481104 care are 105 divizori.
*/

#include <fstream>
#include <algorithm>
#include <cassert>

using namespace std;

long long prim[1000010];
int expp[1000010], p = 0;

int main ()
{
    ifstream cin ("copii.in");
    ofstream cout ("copii.out");

    int c, k;
    long long x;
    cin >> c >> x;

    assert (c == 1 || c == 2);

    if (c == 1)
    {
        cin >> k;

        assert (1LL <= x && x <= 1000000LL);
        assert (1 <= k && k <= 9);

        int m = 1;
        for (int i = 1; i <= k; ++i)
            m *= 10;

        assert (m > 0);

        int nr2 = 0, nr5 = 0;
        for (int i = 1; i <= x; ++i)
        {
            int ci = i;

            while (ci % 5 == 0)
            {
                ++nr5;
                ci /= 5;
            }
        }

        nr2 = nr5;


        long long prod = 1LL;
        for (int i = 1; i <= x; ++i)
        {
            int ci = i;
            while (ci % 2 == 0 && nr2 > 0)
            {
                --nr2;
                ci /= 2;
            }

            while (ci % 5 == 0 && nr5 > 0)
            {
                --nr5;
                ci /= 5;
            }

            prod *= 1LL * ci;
            prod %= 1LL * m;
        }

        int aux = prod, p = 0;
        while (aux > 0)
        {
            ++p;
            aux /= 10;
        }

        for (int i = p + 1; i <= k; ++i)
            cout << 0;

        cout << prod << '\n';
    }

    else
    {
        assert (1LL <= x && x <= 1000000000000LL);

        long long i = 2LL;
        while (i * i <= x)
        {
            if (x % i == 0LL)
            {
                prim[++p] = i;

                while (x % i == 0)
                {
                    x /= i;
                    ++expp[p];
                }
            }

            i += 1LL;
        }

        if (x > 1LL)
        {
            prim[++p] = x;
            expp[p] = 1;
        }

        long long divizor = 1LL, numar = 1LL;
        for (int i = 1; i <= p; ++i)
        {
            if (expp[i] % 2 == 1) --expp[i];

            for (int j = 1; j <= expp[i]; ++j)
                divizor *= prim[i];

            numar *= 1LL * (1 + expp[i]);
        }

        cout << divizor << " " << numar << '\n';
    }

    return 0;
}