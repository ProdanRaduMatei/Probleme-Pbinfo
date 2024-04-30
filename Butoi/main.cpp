#include <bits/stdc++.h>
#define N1 10
#define N3 100001

using namespace std;

ifstream fin("butoi.in");
ofstream fout("butoi.out");

int C, V, N, K, P;
int fr[N1], c[N1], minim = 1000000;
int sa, s, nr, cnt, sol2[N1], sol3;
int c3[N3];
long long sum, cat, cmin = 100000000000;

int main()
{
    int i;
    fin >> C;
    fin >> V >> N >> K >> P;
    if (C == 1 || C == 2)
    {
        for (i = 0; i < N; ++i)
            fin >> c[i];
        do
        {
            fr[N - 1]++;
            s = 0;
            sa = 0;
            nr = 0;
            for (i = N - 1; i >= 1; --i)
            {
                if (fr[i] > K)
                {
                    fr[i] = fr[i] - (K + 1);
                    fr[i - 1]++;
                }
                s += fr[i];
                nr += fr[i];
                sa += fr[i] * c[i];
            }
            s += fr[0];
            nr += fr[0];
            sa += fr[0] * c[0];
            if (sa == V)
            {
                ++cnt;
                if (nr < minim)
                {
                    minim = nr;
                    for (i = 0; i < N; ++i)
                        sol2[i] = fr[i];
                }
            }
        } while (s < N * K);
        if (C == 1)
        {
            fout << cnt;
            return 0;
        }
        else
        {
            for (i = 0; i < N; ++i)
                fout << sol2[i] << ' ';
            return 0;
        }
    }
    for (i = 1; i <= N; ++i)
    {
        fin >> c3[i];
        if (i <= P)
            sum += c3[i];
    }
    if (V % sum == 0)
    {
        cat = V / sum;
        if (cat < cmin)
        {
            cmin = cat;
            sol3 = 1;
        }
    }
    for (i = P + 1; i <= N; ++i)
    {
        sum = (sum - c3[i - P]) + c3[i];
        if (V % sum == 0)
        {
            cat = V / sum;
            if (cat < cmin)
            {
                cmin = cat;
                sol3 = i - P + 1;
            }
        }
    }
    fout << sol3;
    return 0;
}