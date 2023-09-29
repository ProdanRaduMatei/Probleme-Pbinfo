#include <bits/stdc++.h>

using namespace std;

ifstream fin("secv10.in");
ofstream fout("secv10.out");

int n, nr, l, lmax, cnt;

int main() {
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> nr;
        if (nr % 10 == 0) {
            ++l;
            if (lmax < l) {
                lmax = l;
                cnt = 1;
            }
            else
                if (l == lmax)
                    ++cnt;
        }
        else
            l = 0;
    }
    fout << lmax << ' ' << cnt;
    return 0;
}