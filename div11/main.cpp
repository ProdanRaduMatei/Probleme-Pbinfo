#include <bits/stdc++.h>

#define ll long long

using namespace std;

ifstream fin("div11.in");
ofstream fout("div11.out");

int n;
ll v[100005], mat[2][12], sol, aux, nrc;

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> v[i];
        aux = v[i];
        nrc = 0;
        while (aux) {
            ++nrc;
            aux /= 10;
        }
        ++mat[nrc % 2][v[i] % 11];
    }
    for (int i = 1; i <= n; ++i)
    {
        aux = v[i];
        nrc = 0;
        while (aux) {
            ++nrc;
            aux /= 10;
        }
        --mat[nrc % 2][v[i] % 11];
        ll r = v[i] % 11, tot = (11 - r) % 11;
        sol += mat[0][tot];
        r = ((v[i] % 11) * 10LL) % 11;
        tot = (11 - r) % 11;
        sol += mat[1][tot];
        ++mat[nrc % 2][v[i] % 11];
    }
    fout << sol;
    return 0;
}