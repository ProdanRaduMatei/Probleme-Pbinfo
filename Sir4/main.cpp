#include <iostream>
#include <fstream>
#include <cmath>
#include <bitset>
#include <cstring>
#include <iomanip>
#include <algorithm>

using namespace std;

string nume = "date";

ifstream fin(nume + ".in");
ofstream fout(nume + ".out");

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    int p, n, k;
    cin >> p >> n >> k;
    cout << (p + 1) / 2 << '\n';
    int cifre[10] = {0};
    int len = 0;
    for (int i = n * n - n + 1, k = 1; k <= n; k++, i += 2)
    {
        int aux = i;
        while (aux)
        {
            cifre[aux % 10]++;
            aux /= 10;
        }
    }
    for (int i = 9; i >= 0; i--)
        for (int j = 1; j <= cifre[i] / 2; j++)
            cout << i;
    for (int i = 9; i >= 0; i--)
        if (cifre[i] % 2 == 1)
        {
            cout << i;
            break;
        }
    for (int i = 0; i <= 9; i++)
        for (int j = 1; j <= cifre[i] / 2; j++)
            cout << i;
    cout << '\n';
    int cbr = cbrt(k);
    if (cbr * cbr * cbr == k)
        cout << cbr;
    else
        cout << 0;
    return 0;
}