#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("2prim.in");
ofstream fout("2prim.out");

int a, n, p;

int prim(int x) {
    if (x < 2)
        return 0;
    if (x == 2)
        return 1;
    if (x % 2 == 0)
        return 0;
    for (int d = 3; d * d <= x; d = d + 2)
        if (x % d == 0)
            return 0;
    return 1;
}

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> a;
        a = a % 100;
        if (prim(a) == 1)
            ++p;
    }
    fout << p;
    return 0;
}
