/*
Cerința
Se citește numărul natural nenul n și o cifră x. Să se determine cifra minimă a lui n, strict mai mare decât x.

Date de intrare
Programul citește de la tastatură numărul n și cifra x.

Date de ieșire
Programul va afișa pe ecran cifra minimă a lui n, strict mai mare decât x. Dacă nu există această cifră, afișați -1.

Restricții și precizări
1 ≤ n ≤ 1018
0 ≤ x ≤ 9
Exemplu:
Intrare

395445271 4
Ieșire

5

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    long long n;
    int x;
    cin >> n >> x;
    int min = 10;
    while (n)
    {
        if (n % 10 > x && n % 10 < min)
            min = n % 10;
        n /= 10;
    }
    if (min == 10)
        cout << -1;
    else
        cout << min;
    return 0;
}