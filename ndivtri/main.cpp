/*
Șirul numerelor triunghiulare e obținut prin adunarea numerelor naturale. Deci al șaptelea număr triunghiular e 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. Primii 10 termeni din șir sunt: 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
Să listăm toți divizorii primelor 7 numere triunghiulare:
 1: 1
 3: 1,3
 6: 1,2,3,6
10: 1,2,5,10
15: 1,3,5,15
21: 1,3,7,21
28: 1,2,4,7,14,28

Se poate observa că 28 e primul număr triunghiular care are mai mult de 5 divizori.
Cerința
Se dă un număr natural n. Să se scrie un program care determină primul număr triunghiular cu mai mult de n divizori.

Date de intrare
Programul citește de la tastatură numărul natural n.

Date de ieșire
Programul afișează pe ecran numărul x, reprezentând primul număr triunghiular care are mai mult de n divizori.

Restricții și precizări
1 ≤ n ≤ 1000
Exemplul 1:
Intrare

3
Ieșire

6
Explicație
Primul număr trunghiular care are mai mult de 3 divizori este 6.

Exemplul 2:
Intrare

1
Ieșire

3
Explicație
Primul număr trunghiular care are mai mult de un divizor este 3.

Exemplul 3:
Intrare

133
Ieșire

437580
Explicație
Primul număr trunghiular care are mai mult de 133 de divizori este 437580.
*/

#include <iostream>

using namespace std;

bool primes[30000];

int main(void)
{
    int n, i, j, t = 1, a = 1, count = 0, tt, exponent, p;

    primes[0] = primes[1] = 1;

    for(i = 2; i <= 200; i++)
        if(primes[i] == 0)
            for(j = 2; i * j <= 30000; j++)
                primes[i * j] = 1;

    cin >> n;

    while(count <= n) {
        count = 1;
        a++;
        t += a;
        tt = t;
        for(p = 2; p <= 1000; p++) {
            if(primes[p] == 1)
                continue;
            if(p * p > tt) {
                count *= 2;
                break;
            }
            exponent = 1;
            while(tt % p == 0) {
                exponent++;
                tt /= p;
            }
            if(exponent > 1)
                count *= exponent;
            if(tt == 1)
                break;
        }
    }

    cout << t;

    return 0;
}