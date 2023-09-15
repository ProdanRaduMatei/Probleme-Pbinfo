#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("divizori2.in");
ofstream fout("divizori2.out");

void div(int n) {
    for (int d = 1; d <= n; ++d) {
        if (n % d == 0)
            fout << d << " ";
    }
}

int prim(int n) {
    if (n < 2)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    for (int d = 3; d * d <= n; d = d + 2)
        if (n % d == 0)
            return 0;
    return 1;
}

int main()
{
    int p, n;
    fin >> p >> n;
    if (p == 1) {
        int m = 0, x;
        for (int i = 1; i <= n; ++i) {
            fin >> x;
            if (x > m)
                m = x;
        }
        div(m);
    }
    else if (p == 2) {
        int c = 0, x;
        for (int i = 1; i <= n; ++i) {
            fin >> x;
            if (prim(x)) {
                fout << x << " ";
                ++c;
            }
        }
        if (c == 0)
            fout << -1;
    }
    else if (p == 3) {
        int m = 1000000, v[1001];
        for (int i = 1; i <= n; ++i) {
            fin >> v[i];
            if (v[i] < m)
                m = v[i];
        }
        for (int j = 1; j <= m; ++j) {
            int c = 0;
            for (int i = 1; i <= n; ++i)
                if (v[i] % j == 0)
                    ++c;
            if (c == n)
                fout << j << " ";
        }
    }
    return 0;
}
