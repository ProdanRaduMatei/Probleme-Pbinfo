#include <bits/stdc++.h>

using namespace std;

ifstream fin("puternic.in");
ofstream fout("puternic.out");

int N, C, nrp, x, lv, ok, lp;
int v[100005], p[551];
bool ciur[4001];

long long concat(int a, int b) {
    string s1 = to_string(a);
    string s2 = to_string(b);
    string s = s1 + s2;
    long long c = stoll(s);
    return c;
}

int puternic(long long nr) {
    int ex = 0, k = 1;
    while (k <= lp) {
        ex = 0;
        while (nr % p[k] == 0) {
            ex++;
            nr = nr / p[k];
        }
        if (ex == 1)
            return 0;
        k++;
    }
    if (nr == 1)
        return 1;
    if (nr < 4000 && ciur[nr] == 0)
        return 0;
    long long patrat = (round)(sqrt(nr));
    if (patrat * patrat == nr)
        return 1;
    long long cub = (round)(cbrt(nr));
    if (cub * cub * cub == nr)
        return 1;
    return 0;
}

int main() {
    int j;
    ciur[0] = ciur[1] = 1;
    for (int i = 2; i <= 4000; ++i)
        if (ciur[i] == 0) {
            p[++lp] = i;
            j = i + i;
            while (j <= 4000) {
                ciur[j] = 1;
                j = j + i;
            }
        }
    fin >> C >> N;
    if (C == 1) {
        for (int i = 1; i <= N; ++i) {
            fin >> x;
            if (x > 1)
                if (puternic(x))
                    nrp++;
        }
        fout << nrp;
        return 0;
    }
    for (int i = 1; i <= N; ++i) {
        fin >> x;
        if (x == 1) {
            lv++;
            v[lv] = 1;
        }
        else if (!puternic(x)) {
            lv++;
            v[lv] = x;
        }
    }
    for (int i = 1; i <= lv / 2; ++i) {
        int nr1 = v[i], nr2 = v[lv - i + 1];
        long long lp = concat(nr1, nr2);
        if (puternic(lp)) {
            fout << v[i] << " " << v[lv - i + 1] << '\n';
            ok = 1;
        }
    }
    if (!ok)
        fout << -1;
    return 0;
}