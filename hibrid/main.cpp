#include <bits/stdc++.h>

#define VMAX 300000

using namespace std;

ifstream fin("hibrid.in");
ofstream fout("hibrid.out");

struct Interval
{
    int l, r, c;
};
Interval v[100005];
int N, C, P, sm[200005][2], L, R, pr, cnt, poz, maxcnt, la;
unsigned long long suma;
int freq[2 * VMAX + 20];

int main()
{
    fin >> C >> P >> N;
    for (int i = 1; i <= P; ++i)
    {
        fin >> L >> R >> pr;
        L += VMAX;
        R += VMAX;
        L = min(L, R);
        R = max(L, R);
        v[i].l = L;
        v[i].r = R;
        v[i].c = pr;
    }
    fin >> L;
    for (int i = 2; i <= N; ++i)
    {
        fin >> R;
        int p1 = min(L, R), p2 = max(L, R);
        if (!(p2 <- VMAX || p1 > VMAX))
        {
            p1 = max(p1, -VMAX);
            p2 = min(p2, VMAX);
            p1 = min(p1, p2);
            p2 = max(p1, p2);
            p1 += VMAX;
            p2 += VMAX;
            sm[la][0] = p1;
            sm[la][1] = p2;
            ++la;
        }
        L = R;
    }
    if (la)
    {
        int minc = 600001;
        int maxc = -1;
        int li, ri;
        for (int i = 0; i < la; ++i)
        {
            li = sm[i][0];
            freq[li] = freq[li] + 1;
            ri = sm[i][1];
            freq[ri + 1] = freq[ri + 1] - 1;
            if (li < minc)
                minc = li;
            if (ri > maxc)
                maxc = ri;
        }
        for (int i = 1; i <= 600000; ++i)
            freq[i] = freq[i] + freq[i - 1];
        for (int i = 1; i <= P; ++i)
        {
            cnt = freq[v[i].l];
            if (cnt > maxcnt) {
                maxcnt = cnt;
                poz = i;
            }
            if (cnt)
                suma = suma + 1ULL * cnt * v[i].c;
        }
    }
    if (C == 1)
    {
        if (poz)
            fout << poz;
        else
            fout << -1;
    }
    else
        fout << suma;
    return 0;
}