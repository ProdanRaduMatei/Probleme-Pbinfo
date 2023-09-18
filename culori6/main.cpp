#include <bits/stdc++.h>

using namespace std;

ifstream fin("culori.in");
ofstream fout("culori.out");

int C, N, M;
int nr1[505], nr2[505], nrmax[501];

int compar(int x[], int y[]) {
    if (x[0] != y[0])
        return (x[0] < y[0] ? -1 : 1);
    int i = 1;
    while (x[i] == y[i] && i <= x[0])
        ++i;
    if (i > x[0])
        return 0;
    if (x[i] < y[i])
        return -1;
    return 1;
}

int main() {
    fin >> C >> N;
    if (C == 1) {
        int L, M, Lmax = 0, Kmax = 1;
        for (int i = 1; i <= N; ++i) {
            fin >> M;
            L = M;
            int c1, c2;
            fin >> c1;
            for (int j = 2; j <= M; ++j) {
                fin >> c2;
                if (c1 != c2)
                    c1 = c2;
                else
                    L = 0;
            }
            if (L >= Lmax) {
                if (L == Lmax)
                    ++Kmax;
                if (L > Lmax) {
                    Lmax = L;
                    Kmax = 1;
                }
            }
        }
        fout << Lmax << ' ' << Kmax << '\n';
        return 0;
    }
    fin>>nr1[0];
    nrmax[0]=nr1[0];
    for(int j=1;j<=nr1[0];++j)
        fin>>nr1[j],nrmax[j]=nr1[j];
    for(int i=2;i<=N;++i)
    {
        fin>>nr2[0];
        for(int j=1;j<=nr2[0];++j)
            fin>>nr2[j];
        int ok=compar(nrmax,nr2);
        if(ok<0)
        {
            nrmax[0]=nr2[0];
            for(int j=1;j<=nrmax[0];++j)
                nrmax[j]=nr2[j];
        }
    }
    for(int i=1;i<=nrmax[0];++i)
        fout<<nrmax[i];
    return 0;
}