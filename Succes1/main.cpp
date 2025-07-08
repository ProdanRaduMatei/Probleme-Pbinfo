#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("succes.in");
ofstream fout("succes.out");

int n, m, k, a[1000000001], b[1000000001], sa[1000000001], sb[1000000001];
int multimi[2000001][5];

void read()
{
    fin >> n >> m >> k;
    for (int i = 1; i <= m; ++i)
    {
        fin >> a[i];
        sa[i] = sa[i - 1] + a[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        fin >> b[i];
        sb[i] = sb[i - 1] + b[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        fin >> multimi[i][0];
        for (int j = 1; j <= multimi[i][0]; ++j)
        {
            fin >> multimi[i][j];
        }
    }
}

int main()
{
    read();
}