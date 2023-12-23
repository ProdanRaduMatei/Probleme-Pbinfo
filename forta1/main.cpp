#include <bits/stdc++.h>

using namespace std;

ifstream fin("forta.in");
ofstream fout("forta.out");

struct Forta {
    unsigned long long val;
    int fr, poz;
};

Forta v[1001];
int n, sm;

int Contor(unsigned long long nr1, unsigned long long nr2) {
    int fr1[10], fr2[10], cnt = 0;
    for (int i = 0; i < 10; ++i) {
        fr1[i] = 0;
        fr2[i] = 0;
    }
    do {
        fr1[nr1 % 10]++;
        nr1 /= 10;
    } while(nr1);
    do {
        fr2[nr2 % 10]++;
        nr2 /= 10;
    } while(nr2);
    for (int i = 0; i < 10; ++i)
        if (fr1[i] && fr2[i])
            cnt += min(fr1[i], fr2[i]);
    return cnt;
}

int main() {
    unsigned long long x;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> x;
        v[i].val = x;
        v[i].poz = i;
    }
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j) {
            sm = Contor(v[i].val, v[j].val);
            v[i].fr += sm;
            v[j].fr += sm;
        }
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; ++j)
            if (v[i].fr > v[j].fr)
                swap(v[i], v[j]);
            else if (v[i].fr == v[j].fr)
                if (v[i].poz < v[j]. poz)
                    swap(v[i], v[j]);
    for (int i = 1; i <= n; i++)
        fout << v[i].val << " ";
    return 0;
}