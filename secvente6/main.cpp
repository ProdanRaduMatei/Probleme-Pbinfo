#include <bits/stdc++.h>

using namespace std;

ifstream f("secvente.in");
ofstream g("secvente.out");

const int nmax = 100090;
int n, t, ind = 1;
long long pre[nmax];
pair<int, int> v[nmax];

long long calc(int p, int q, int st, int dr) {
    return (long long)pre[q] - pre[p - 1] - 1ll * (v[q + 1].second - dr - 1) * v[q].first - 1ll * (dr - v[p].second + 1) * (st - 1);
}

int main() {
    f >> n;
    for (int i = 1; i <= n; ++i)
        f >> v[i].first >> v[i].second;
    sort(v + 1, v + n + 1);
    for (int i = 2; i <= n; ++i)
        if (v[i].first >= v[ind].first) {
            while (ind > 0 && v[ind].second >= v[i].second)
                --ind;
            v[++ind] = v[i];
        }
    n = ind;
    v[n + 1] = {v[n].second + 1, 1000001};
    for (int i = 1; i <= n; ++i)
        pre[i] = pre[i - 1] + 1ll * v[i].first * (v[i + 1].second - v[i].second);
    f >> t;
    for (int i = 1, st, dr, mid, poz1, poz2, p, q; i <= t; ++i) {
        f >> st >> dr;
        p = poz1 = 0;
        poz2 = n;
        while (poz1 <= poz2) {
            mid = ((poz1 + poz2) >> 1);
            if (st > v[mid].first)
                poz1 = mid + 1;
            else {
                p = mid;
                poz2 = mid - 1;
            }
        }
        if (p == 0 || dr < v[p].second) {
            g << "0\n";
            continue;
        }
        poz1 = p;
        poz2 = n;
        q = 0;
        while (poz1 <= poz2) {
            mid = ((poz1 + poz2) >> 1);
            if (dr < v[mid].second)
                poz2 = mid - 1;
            else {
                q = mid;
                poz1 = mid + 1;
            }
        }
        g << calc(p, q, st, dr) << '\n';
    }
    return 0;
}