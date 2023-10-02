#include <bits/stdc++.h>

using namespace std;

const int nMAX = 1e6;

int n, s;
int v[nMAX + 1];
unordered_map<int, int> m;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    long long secvente = 0;
    int sc = 0;
    for (int i = 1; i <= n; ++i) {
        sc += v[i];
        auto it = m.find(sc - s);
        if (it != m.end())
            secvente += it->second;
        if (sc == s)
            secvente++;
        m[sc]++;
    }
    cout << secvente;
}