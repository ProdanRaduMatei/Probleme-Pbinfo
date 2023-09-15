#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("intervale6.in");
ofstream fout("intervale6.out");

int caut(int x, int n, int v[], int &ok) {
    ok = 0;
    int s = 1, d = n;
    while (s <= d) {
        int m = (s + d) / 2;
        if (v[m] == x) {
            ok = 1;
            return m;
        }
        if (v[m] > x)
            d = m - 1;
        if (v[m] < x)
            s = m + 1;
    }
    return s;
}

int main() {
    int n, v[10001], x, y, c = 0, kx, ky;
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    while (fin >> x >> y) {
        if (y < v[1])
            ++c;
        else if (x > v[n])
            ++c;
        else {
            if (caut(y, n, v, kx) - caut(x, n, v, ky) == 1 && kx == 0 && ky == 0)
                ++c;
        }
    }
    fout << c;
    return 0;
}
