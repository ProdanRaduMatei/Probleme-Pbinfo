/*
Cerința
Se dă numărul natural nenul n. Să se determine produsul primelor n pătrate perfecte nenule.

Date de intrare
Programul citește de la tastatură numărul n.

Date de ieșire
Programul va afișa pe ecran numărul P, reprezentând produsul primelor n pătrate perfecte nenule.

Restricții și precizări
1 ≤ n ≤ 10
Exemplu:
Intrare

4
Ieșire

576
Explicație
Produsul primelor 4 pătrate perfecte este 1 *4 * 9 * 16 = 576.
*/

#include <iostream>
using namespace std;
long long n, i, p;
int main()
{
    cin >> n;
    p = 1;
    for(i = 1; i <= n; i++)
        p *= i * i;
    cout << p;
    return 0;
}