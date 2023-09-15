#include <bits/stdc++.h>

using namespace std;

ifstream fin("prosum.in");
ofstream fout("prosum.out");

int main()
{
    int n, m, v[100001], c = 0;
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j) {
            long long k = v[i] * v[j] + v[i] + v[j];
            if (k % m == 0)
                ++c;
        }
    fout << c;
    return 0;
}
