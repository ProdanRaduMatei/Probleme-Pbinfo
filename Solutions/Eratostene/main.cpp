#include <bits/stdc++.h>

using namespace std;

ifstream fin("eratostene.in");
ofstream fout("eratostene.out");

bool c[1000005];

int main() {
    c[0] = c[1] = 1;
    for (int i = 2; i <= 1000; ++i)
        if (c[i] == 0)
            for (int j = 2; i * j <= 1000000; ++j)
                c[i * j] = 1;
    int n;
    fin >> n;
    int x;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        fin >> x;
        if (c[x] == 0)
            cnt++;
    }
    fout << cnt;
    return 0;
}