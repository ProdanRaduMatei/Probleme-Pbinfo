#include <istream>
#include <fstream>

using namespace std;

ifstream fin("cautanrinmatrice.in");
ofstream fout("cautanrinmatrice.out");

int e[1000001], n, m, p = 1, b, x, q, a;

int cb(int val) {
    int st = 0, dr = p - 1, poz = 1;
    while (st <= dr) {
        int m = (st + dr) / 2;
        if (val <= e[m]) {
             poz = m;
             dr = m - 1;
        }
        else
            st = m + 1;
    }
    if (e[poz] == val)
        return poz;
    else
        return 0;
}
int main() {
    fin >> n >> m;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 1) {
            int aux = m - 1;
            for (int j = 0; j < m; ++j) {
                fin >> e[p + aux];
                aux--;
            }
            p += m;
        }
        else
            for (int j = 0; j < m; ++j) {
                fin >> e[p];
                p++;
            }
    }
    fin >> q;
    for (int i = 0; i < q; ++i) {
        fin >> x;
        if (cb(x)) {
            int a = cb(x) / m + 1;
            if (cb(x) % m == 0)
                a--;
            int b = (cb(x)) % m;
            if (b == 0)
                b = m;
            if (a % 2 == 0)
                b = m - b + 1;
            fout << a << ' ' << b << '\n';
        }
       else
           fout << 0 << '\n';
    }
    return 0;
}
