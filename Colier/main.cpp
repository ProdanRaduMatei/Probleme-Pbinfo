#include <bits/stdc++.h>
 
using namespace std;

ifstream fin("colier.in");
ofstream fout("colier.out");

int N, T, poz, poz1, poz2, mini, maxi;

int tip(int x) {
    int poz1 = 1, poz2 = 1, poz = 1;
    int mini = maxi = x % 10;
    x /= 10;
    while (x) {
        poz++;
        if (x % 10 < mini) {
            mini = x % 10;
            poz1 = poz;
        }
        if (x % 10 > maxi) {
            maxi = x % 10;
            poz2 = poz;
        }
        x /= 10;
    }
    if (poz1 > poz2)
        return 1;
    else
        return 2;
}

int main()
{
    fin >> T >> N;
    if (T == 1) {
        int cnt = 0;
        for (int i = 1; i <= N; ++i) {
            int x;
            fin >> x;
            if (tip(x) == 1)
                ++cnt;
        }
        fout << cnt;
    }
    else {
        int secvInit = 0, uSecv = 0, ll = 1, nrMargele = N, x, t;
        fin >> x;
        secvInit = tip(x);
        uSecv = secvInit;
        for (int i = 2; i <= N; ++i) {
            fin >> x;
            t = tip(x);
            if (t == uSecv)
                ++ll;
            else {
                nrMargele = nrMargele - ll + 1;
                ll = 1;
                uSecv = t;
            }
        }
        nrMargele = nrMargele - ll + 1;
        if (secvInit == uSecv)
            nrMargele--;
        fout << nrMargele;
    }

    return 0;
}