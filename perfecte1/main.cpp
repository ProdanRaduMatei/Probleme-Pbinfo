/*
Cerința
Dorel este pasionat de studiul pătratelor perfecte. El doreşte să afle răspunsul la Q cerinţe de forma: dacă se dau numerele naturale l, r, a, b, cu l ≤ r, să se afle câte numere naturale x cuprinse între l şi r (inclusiv acestea) au proprietatea că x+a şi x+b sunt simultan pătrate perfecte.

Date de intrare
Pe prima linie a intrării standard se află numărul Q, iar pe următoarele Q linii se află câte patru valori l, r, a, b, separate prin spaţiu.

Date de ieșire
La ecran se vor afişa, pe linii diferite, răspunsurile la cele Q cerinţe ale lui Dorel.

Restricții și precizări
1 ≤ Q ≤ 100.000
1 ≤ l ≤ r ≤ 2.000.000.000
1 ≤ a < b ≤ 1.000.000
Exemplu:
Intrare

3
1 9 3 10
13 780 4 61
35 789 4 3279
Ieșire

1
2
0
Explicație
Pentru primul exemplu, între numerele 1 şi 9 există o singură valoare a lui x pentru care numerele x+3 şi x+10 să fie simultan pătrate perfecte, şi anume x=6.

Pentru al doilea exemplu, între numerele 13 şi 780 există două valori ale lui x pentru care numerele x+4 şi x+61 să fie simultan pătrate perfecte, şi anume x=60 şi x=780.
*/

#include <bits/stdc++.h>
using namespace std;
long long a, b, l, r, dif, k, w, e, x, q , sol = 0, f;
int main()
{
    cin >> q; 
    for(int i = 1; i <= q; ++i)
    {
        sol = 0;
        cin >> l >> r >> a >> b;
        k = sqrt(l + a);  // stim ca l <= x && x <= r si a < b deci l + a <= x + a <= r + a < r + b
        // de asemenea l + a <= x + b <= r + b; din cele doua relatii obtinem ca l + a <= x + a < x + b < r + b astfel vom nota cu w si k radical din capetele intervalului
        w = sqrt(r + b);
        dif = b - a;
        // notam cu e * e si f * f doua patrate perfecte astfel ca e * e = x + b si f * f = x + a, e > f,  deci e * e - f * f = b - a adica (e - f) * (e + f) = b - a;
        for(int i = 1; i * i <= (b - a); ++i)
        {
            if(dif % i == 0)
            {
            e = (dif / i + i) / 2;
            f = (dif / i - i) / 2;
            if((l <= e * e - b && e * e - b <= r) && (e * e - b == f * f - a) && (l <= f * f - a && f * f - a <= r))
               {
                   sol++;
               }
            }
        }
        cout << sol << '\n';
    }
    return 0;
}