/*
Cerința
Se dă numărul natural nenul n. Să se determine produsul primelor n numere pare nenule.

Date de intrare
Programul citește de la tastatură numărul n.

Date de ieșire
Programul va afișa pe ecran numărul P, reprezentând produsul primelor n numere pare nenule.

Restricții și precizări
1 ≤ n ≤ 10
Exemplu:
Intrare

4
Ieșire

384
Explicație
Produsul primelor 4 numere pare este 2 *4 * 6 * 8 = 384.
*/

#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n;
    cin >> n;
    unsigned long long prod = 1;
    for(int i = 2; i <= n * 2; i += 2)
        prod *= i;
    cout << prod;
}