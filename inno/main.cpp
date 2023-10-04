#include <bits/stdc++.h>

#define NMAX 200005

using namespace std;

ifstream fin("inno.in");
ofstream fout("inno.out");

int n, k, a[NMAX], st[NMAX], dr[NMAX], x = -1, y;
long long val, sol;

int count_bit(int v) {
    int c = 0;
    v = v - ((v >> 1) & 0x55555555);
    v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
    c = ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
    return c;
}

int bsearch(int p, int u, int key) {
    int m = 0;
    while (p < u) {
        m = (p + u) / 2;
        if (dr[m] & key < k)
            p = m + 1;
        else
            u = m;
    }
    m = (p + u) / 2;
    if (dr[m] & key < k)
        ++m;
    return m;
}

int main() {
    fin >> n >> k;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    st[1] = a[1];
    dr[n] = a[n];
    for (int i = 2; i <= n; ++i)
        st[i] = (st[i - 1])&(a[i]);
    for (int i = n - 1; i >= 1; i--)
        dr[i] = (dr[i + 1])&(a[i]);
    if (count_bit(st[1]) < k)
        x = 0;
    if (count_bit(dr[n]) < k)
        y = n + 1;
    if (x < 0) {
        x = 1;
        int i = 2;
        while (i <= n) {
            if (count_bit(st[i]) >= k)
                x = i;
            i++;
        }
    }
    if (!y) {
        y = n;
        int i = n - 1;
        while (i >= 1) {
            if (count_bit(dr[i]) >= k)
                y = i;
            i--;
        }
    }
    if (x == n)
        fout << n * (n + 1) / 2;
    else if (x == 0 && y == n + 1)
        fout << 0;
    else if (x >= 1 && x < n && y == n + 1)
        fout << x;
    else if (x == 0 && y > 1 && y <= n)
        fout << n - y + 1;
    else if (x == 0 && y == 0)
        fout << 1;
    else {
       sol = n - y + 1;
       for (int i = 1; i <= x; ++i) {
            val = bsearch(y, n, st[i]);
            sol += (n - val + 2);
       }
       fout << sol;
    }
    return 0;
}