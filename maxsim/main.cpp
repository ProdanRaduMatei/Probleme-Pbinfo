#include <bits/stdc++.h>

using namespace std;

ifstream fin("maxsim.in");
ofstream fout("maxsim.out");

int main()
{
    int n, smax = 0, v[1001], st, dr;
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    for (int i = 1; i <= n / 2; ++i) {
        int s = v[i] + v[n - i + 1];
        if (s > smax) {
            smax = s;
            st = i;
            dr = n - i + 1;
        }
    }
    fout << smax << " " << st << " " << dr;
    return 0;
}
