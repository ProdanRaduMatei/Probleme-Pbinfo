#include <bits/stdc++.h>

using namespace std;

ifstream fin("cate.in");
ofstream fout("cate.out");

int C, n, a, b, p[1000001];
bool prime[1001];

int main() {
    fin >> C;
    if (C == 1) {
        fin >> n;
        for (int i = 1; i <= n; ++i) {
            fin >> a >> b;
            if (a > b)
                swap(a, b);
            fout << (int)pow(b, 0.5) - (int)pow(a - 1, 0.5) << '\n';
        }
        return 0;
    }
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= 1000; ++i)
        if (prime[i] == true) {
            p[i * i] = 1;
            for (int j = i * i; j <= 1000; j += i)
                prime[j] = false;
        }
    for (int i = 1; i <= 1000000; ++i)
        p[i] += p[i - 1];
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> a >> b;
        if (a > b)
            swap(a, b);
        fout << p[b] - p[a - 1] << '\n';
    }
    return 0;
}