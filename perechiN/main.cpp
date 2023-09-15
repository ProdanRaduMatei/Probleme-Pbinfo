#include <iostream>

using namespace std;

/*
Cerința
Se dă un număr natural nenul n. Afișați toate perechile x y cu proprietatea că x + y = n și 0 < x ≤ y.

Date de intrare
Programul citește de la tastatură numărul n.

Date de ieșire
Programul va afișa la ecran, pe câte o linie o pereche x y cu proprietatea că x + y = n și 0 < x ≤ y. Perechile se vor afișa crescător după x.

Restricții și precizări
1 ≤ n ≤ 100
Exemplu:
Intrare

10
Ieșire

1 9
2 8
3 7
4 6
5 5

*/

int main()
{
    int n;
    cin >> n;

    for (int x = 1; x <= n / 2; x++)
    {
        int y = n - x;
        cout << x << " " << y << endl;
    }

    return 0;
}