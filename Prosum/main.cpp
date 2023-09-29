#include <fstream>
#include <iostream>
#include <map>
#include <algorithm>
#include <set>

#define DIM 100010
#define ULL long long

using namespace std;

ULL v[DIM], w[DIM];
ULL n, m, i, j, sol, X, Y, nr0;

map<ULL, ULL> mp, f;
map<ULL, ULL>::iterator it;
set<ULL> st;

ULL cmmdc(ULL a, ULL b, ULL &x, ULL &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    else {
        ULL xa, ya;
        ULL r = cmmdc(b, a % b, xa, ya);
        x = ya;
        y = xa - (a / b) * ya;
        return r;
    }
}

ULL gcd(ULL a, ULL b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main () {
    ifstream fin ("prosum.in");
    ofstream fout("prosum.out");

    fin >> n >> m;
    for (i = 1; i <= n; i++) {
        fin >> v[i];
        v[i] %= m;
        w[i] = gcd(v[i] + 1, m);
        st.insert(v[i]);
    }
    for (i = 1; i <= n; i++) {
        if (v[i] == 0) {
            nr0++;
            continue;
        }
        if (w[i] != 1)
            continue;
        cmmdc((v[i] + 1) % m, m, X, Y);
        X = (X % m + m) % m;
        X--;
        if (X < 0)
            X += m;
        if (st.find(X) != st.end()) {
            f[v[i]] = X;
            f[X] = v[i];
        }
    }
    for (i = 1; i <= n; i++) {
        if (f.find(v[i]) != f.end()) {
            it = mp.find(f[ v[i] ]);
            if (it != mp.end())
                sol += mp[f[ v[i] ]];
        }
        it = mp.find(v[ i ]);
        if (it == mp.end())
            mp[v[i]] = 1;
        else
            mp[v[i]]++;
    }
    fout << sol + nr0 * (nr0 - 1) / 2;
    return 0;
}