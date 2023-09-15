/*
Cerința
Un număr natural se numește palPow dacă oglinditul său are strict mai mulți divizori pozitivi decât are numărul. De exemplu 23 este un număr palPow deoarece 23 are doi divizori pozitivi (1 23) iar oglinditul său, 32, are șase divizori pozitivi (1 2 4 8 16 32). Oglinditul unui număr este valoarea obținută considerând cifrele numărului de la dreapta la stânga(de exemplu, oglinditul lui 675 este 576 iar oglinditullui 20310 este 1302). Pentru un șir de n numere naturale date să se determine câte numere palPow sunt în șir precum și care este cel mai mic și cel mai mare număr palPow din șir.

Date de intrare
Fișierul de intrare conține pe prima linie numărul n și pe a doua linie n numere naturale separate prin spațiu.

Date de ieșire
Fișierul de ieșire va conține pe prima linie trei valori separate prin câte un spațiu, reprezentând în ordine, numărul de numere palPow, cel mai mic număr palPow, cel mai mare număr palPow din șirul dat.

Restricții și precizări
1 ≤ n ≤ 1000.
numerele din șir sunt naturale cel mult egale cu 109.
șirul conține cel puțin un număr palPow.
Exemplu:
palpow.in

6
13 23 231 408 48 36
palpow.out

3 23 231
*/

#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

static int count_divs(int n)
{
    int cnt = 1;
    int d = 2;
    int p = 0;

    while (n > 1) {
        p = 0;
        while (n % d == 0)
            n /= d, p++;
        if (p)
            cnt *= (p + 1);
        d++;
        if (d * d > n)
            d = n;
    }

    return cnt;
}

static int reversed(int n)
{
    int r = 0, d;

    while(n) {
        d = n % 10;
        n /= 10;
        r = r * 10 + d;
    }

    return r;
}

int main(void)
{
    int n, x, cnt = 0, minp = INT_MAX, maxp = INT_MIN;

    ifstream fin("palpow.in");
    ofstream fout("palpow.out");

    fin >> n;

    while(n--) {
        fin >> x;

        if(count_divs(reversed(x)) > count_divs(x)) {
            cnt++;
            minp = min(minp, x);
            maxp = max(maxp, x);
        }
    }

    fout << cnt << " " << minp << " " << maxp;

    return 0;
}