/*
Două numere sunt “bune” dacă cifra maximă a unui număr coincide cu cifra minimă din celălalt sau invers.

Cerința
Se dau două numere a și b numere naturale. Verificați dacă cele două numere sunt “bune” și afișați cifra comună. Dacă cele două numere nu sunt bune, afișați NU.

Date de intrare
Programul citește de la tastatură două numere a și b.

Date de ieșire
Programul va afișa pe ecran numărul c, reprezentând cifra comuna celor două numere citite.

Restricții și precizări
cele doua numere a si b vor fi mai mici decât 1.000.000.000
Exemplu 1:
Intrare

123 3456
Ieșire

3
Exemplu 2:
Intrare

123 67
Ieșire

NU

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
    int a, b;
    cin >> a >> b;
    int maxa = 0, maxb = 0, mina = 9, minb = 9;
    while (a)
    {
        if (a % 10 > maxa)
            maxa = a % 10;
        if (a % 10 < mina)
            mina = a % 10;
        a /= 10;
    }
    while (b)
    {
        if (b % 10 > maxb)
            maxb = b % 10;
        if (b % 10 < minb)
            minb = b % 10;
        b /= 10;
    }
    if (maxa == minb)
        cout << maxa;
    else if (maxb == mina)
        cout << maxb;
    else
        cout << "NU";
    return 0;
}