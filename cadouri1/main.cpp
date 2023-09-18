#include <bits/stdc++.h>

using namespace std;

const string file = "cadouri";
ifstream fin(file + ".in");
ofstream fout(file + ".out");

#define cin in
#define cout out

int c, n, mini = LONG_MAX, s, d, nr, v[1000001], r[1000001], l[1000001];

int main () {
    fin >> c >> n;
    for (int i = 1; i <= n; i++) {
        fin >> v[i];
        if (v[i] < mini)
            mini = v[i];
    }
    for (int i = 2; i <= n; i += 2) {
        s = v[i] + v[i - 1];
        r[i] = max(r[i - 2], s);
    }
    for (int i = n - 1; i >= 1; i -= 2) {
        d = v[i] + v[i + 1];
        l[i] = max(l[i + 2], d);
    }
    if (c == 1)
        fout << n / 2 << " ";
    else {
        if (n % 2 == 0)
            fout << r[n] << " ";
        else {
            for (int i = 1; i <= n; i++)
                if (v[i] == mini) {
                    if (i % 2 == 1) {
                        nr= max(nr, r[i - 1]);
                        nr = max(nr, l[i + 1]);
                    }
                    else {
                        nr = max(nr, v[i - 1] + v[i + 1]);
                        nr = max(nr, r[i - 2]);
                        nr = max(nr, l[i + 2]);
                    }
                }
            fout << nr << " ";
        }
    }
    if (n % 2 == 1) 
        fout << mini;
    else 
        fout << 0;
    return 0;
}