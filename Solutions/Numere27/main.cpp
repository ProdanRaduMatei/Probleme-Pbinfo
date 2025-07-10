/*
Într-o zi, Ioana a scris toate numerele naturale de N cifre fiecare îndeplinind, simultan, condițiile:
numărul format din primele două cifre este pătrat perfect;
a treia cifră este obligatoriu număr prim;
nu conține două cifre pare alăturate și nici două cifre impare alăturate.
De exemplu, numerele de trei cifre, scrise de Ioana, sunt: 163, 165, 167, 252, 363, 365, 367, 492, 812.

Cerința
Cunoscându-se numerele N și X, scrieți un program care determină:
1) câte numere de N cifre îndeplinesc cele trei condiții din enunț;
2) care este cel mai apropiat număr de X, diferit de X, care să îndeplinească cele trei condiții din enunț și care să aibă același număr de cifre ca X. Dacă există două astfel de numere, egal depărtate de X, se va afișa cel mai mic dintre ele.

Date de intrare
Fișierul de intrare numere.in conţine pe prima linie un număr natural C. Numărul C poate avea doar valorile 1 sau 2. Pe a doua linie se află, în cazul primei cerințe, numărul N, iar în cazul celei de-a doua cerințe, numărul X.

Date de ieșire
Dacă valoarea lui C este 1, se va rezolva doar cerința 1). În acest caz, fișierul de ieșire numere.out va conține pe prima linie un număr natural, reprezentând rezultatul determinat pentru prima cerință.
Dacă valoarea lui C este 2, se va rezolva doar cerința 2). În acest caz, fișierul de ieșire numere.out va conține pe prima linie un număr natural, reprezentând rezultatul determinat pentru cea de a doua cerință.

Restricții și precizări
3 ≤ N ≤ 29
100 ≤ X ≤ 20.000.000
Pentru rezolvarea primei cerințe se acordă 30 de puncte, iar pentru rezolvarea celei de a doua cerințe se acordă 70 de puncte.
Exemplul 1:
numere.in

1
4
numere.out

45
Explicație
Numerele de patru cifre, scrise de Ioana, sunt: 1630, 1632, 1634, 1636, 1638, 1650, 1652, 1654, 1656, 1658, 1670, 1672, 1674, 1676, 1678, 2521, 2523, 2525, 2527, 2529, 3630, 3632, 3634, 3636, 3638, 3650, 3652, 3654, 3656, 3658, 3670, 3672, 3674, 3676, 3678, 4921, 4923, 4925, 4927, 4929, 8121, 8123, 8125, 8127, 8129.

Exemplul 2:
numere.in

2
200
numere.out

167
Explicație
Cel mai apropiat număr de 200 este 167 (numerele de trei cifre, scrise de Ioana, sunt: 163, 165, 167, 252, 363, 365, 367, 492, 812).
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    unsigned long long int c, n;

    int x, dif1 = 20000000, dif2 = 20000000, y, xx;
    long long xmin, xmax, i, first, second;

    ifstream fin("numere.in");
    ofstream fout("numere.out");

    fin >> c >> n;

    if(c == 1) {
        unsigned long long result = 9;

        n -= 3;
        while(n--)
            result *= 5;

        fout << result;
    } else {
        x = n;
        y = x;
        xmin = 163;
        xmax = 812;
        i = 3;

        while(y > 999) {
            i++;
            if (i % 2 == 0) {
                xmin *= 10;
                xmax = xmax * 10 + 9;
            } else {
                xmin = xmin * 10 + 1;
                xmax = xmax * 10 + 8;
            }
            y /= 10;
        }
        if(x < xmin)
            fout << xmin;
        else if(x > xmax)
                fout << xmax;
            else {
                for(xx = x - 1; xx >= xmin; xx--) {
                    int v[11], k = 0, i, prefix = xx, valid = 1;
                    while(prefix > 99) {
                        k++;
                        v[k] = prefix % 10;
                        prefix /= 10;
                    }
                    if(prefix != 16 && prefix != 25 && prefix != 36 && prefix != 49 && prefix != 81)
                        valid = 0;
                    else if((prefix == 16 || prefix == 36) && (v[k] != 3 && v[k] != 5 && v[k] != 7))
                        valid = 0;
                    else if((prefix == 25 || prefix == 49 ||prefix == 81) && v[k] != 2)
                        valid = 0;
                    else
                        for(i = k - 1; i >= 1; i--)
                            if(v[i] % 2 == v[i + 1] % 2)
                                valid = 0;
                    if (valid) {
                        first = xx;
                        dif1 = x - first;
                        break;
                    }
                }
                for(xx = x + 1; xx <= xmax; xx++) {
                    int v[11], k = 0, i, prefix = xx, valid = 1;
                    while(prefix > 99) {
                        k++;
                        v[k] = prefix % 10;
                        prefix /= 10;
                    }
                    if (prefix != 16 && prefix != 25 && prefix != 36 && prefix != 49 && prefix != 81)
                        valid = 0;
                    else if ((prefix == 16 || prefix == 36) && (v[k] != 3 && v[k] != 5 && v[k] != 7))
                        valid = 0;
                    else if ((prefix == 25 || prefix == 49 || prefix == 81) && v[k] != 2)
                        valid = 0;
                    else
                        for (i = k - 1; i >= 1; i--)
                            if (v[i] % 2 == v[i + 1] % 2)
                                valid = 0;
                    if (valid) {
                        second = xx;
                        dif2 = second - x;
                        break;
                    }
                }

                if(dif1 <= dif2)
                    fout << first << endl;
                else
                    fout << second << endl;
            }
    }

    return 0;
}