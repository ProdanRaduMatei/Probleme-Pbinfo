#include <bits/stdc++.h>

using namespace std;

ifstream fin("test.in");
ofstream fout ("test.out");

long long putere(long long a, long long p, int mod) {
    if (p == 0)
        return 1;
    else {
       long long x = putere(a, p / 2, mod);
       if (p % 2 == 0)
           return x * x % mod;
       else
           return x * x % mod * a % mod;
    }
}

int main() {
    unsigned long long a[1005], b[1005], s = 0;
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int i = 1; i <= n; i++)
        fin >> b[i];
    for (int i = 1; i <= n; i++)
        s += putere(a[i], b[i], 6669666);
    fout << s;
    return 0;
}
