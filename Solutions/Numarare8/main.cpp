#include <bits/stdc++.h>

using namespace std;

const string file = "numarare8";
ifstream in(file + ".in");
ofstream out(file + ".out");

#define cin in
#define cout out
int f[1000];

bool prim(int x) {
    for (int i = 2; i < x; ++i)
        if (x % i == 0)
            return 0;
    return 1;
}

int n, x, k;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
    f[x] = 1;
    }
    for (int i = 100; i <= 999; ++i)
        if (prim(i) && !f[i])
            k++;
    cout << k;
    return 0;
}