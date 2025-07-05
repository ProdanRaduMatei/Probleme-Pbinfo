/*
Cerința
Georgiana nu are clipă de răgaz. Profesorul de info îi cere acum să afle cel mai mic număr natural de n cifre care împărţit la b dă restul r. Poate o ajutaţi să treacă şi peste acest hop.

Date de intrare
Programul citește de la tastatură numerele n, b şi r.

Date de ieșire
Programul va afișa pe ecran numărul cerut.

Restricții și precizări
1 ≤ n ≤ 100.000
2 ≤ b ≤ 1.000.000.000
0 ≤ r < b
dacă numărul nu există se va afişa -1
Exemplu:
Intrare

5 97 14
Ieșire

10005
Explicație
Cel mai mic număr de 5 cifre care împărţit la 97 dă restul 14 este 10005.
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
    long long n, b, r;
    cin >> n >> b >> r;
    long long k = 0, x = r;
    while (x != 0) {
        k++;
        x /= 10;
    }
    if (k > n)
        cout << -1;
    else if (k == n)
        cout << r;
    else {
        long long s = 1, nr = 0;
        for (int i = 2; i <= n; ++i)
            s = (s * 10) % b;
        if (s <= r)
            nr = r - s;
        else
            nr = b - s + r;
        if (nr == 0) {
            cout << 1;
            for (int i = 1; i < n; ++i)
                cout << 0;
        }
        else {
            k = 0;
            x = nr;
            while (x != 0) {
                ++k;
                x /= 10;
            }
            cout << 1;
            for (int i = 1; i < n - k; ++i)
                cout << 0;
            cout << nr;
        }
    }
}
