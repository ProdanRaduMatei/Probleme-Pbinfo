#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("memory004.in");
ofstream fout("memory004.out");

bool prim(int x)
{
    if (x < 2)
        return 0;
    if (x > 2 && x % 2 == 0)
        return 0;
    for (int d = 3; d * d <= x; d = d + 2)
        if (x % d == 0)
            return 0;
    return 1;
}

int main() {
    int l, c, v[1001][1001], Lmax = 0, lungime = 0;
    cin >> l >> c;
    for (int i = 1; i <= l; ++i)
        for (int j = 1; j <= c; ++j)
            cin >> v[i][j];
    for (int j = 1; j <= c; ++j)
        for (int i = 1; i <= l; ++i)
        {
            if (prim(v[i][j]))
                ++lungime;
            else
            {
                if (lungime > Lmax)
                    Lmax = lungime;
                lungime = 0;
            }
        }
    cout << Lmax;
    return 0;
}
