# include <bits/stdc++.h>

# define MOD 1000000007
# define NM 100003
using namespace std;

ifstream fin("easy_sum.in");
ofstream fout("easy_sum.out");

int x[NM], n;
long long S;

int main() {
    fin >> n;
    for (int i = 0; i < n; ++i)
        fin >> x[i];
    for (int i = 0; i < n; ++i)
        S = (S + 1LL * x[i] * (i + 1) * (n - i)) % MOD;
    fout << S << '\n';
    return 0;
}