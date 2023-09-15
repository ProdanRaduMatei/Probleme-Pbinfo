#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("puternic.in");
ofstream fout("puternic.out");

int prim(int x) {
    if (x <= 1)
        return 0;
    if (x == 2)
        return 1;
    if (x % 2 == 0)
    return 0;
    for (int d = 3; d * d <= x; d = d + 2)
        if (x % d == 0)
            return 0;
    return 1;
}

int verifputere(int x) {
    if (x <= 1)
        return 0;
    if (x == 2)
        return 1;
    if (x % 2 == 0)
    return 0;
    for (int d = 3; d * d <= x; d = d + 2)
        if (prim(d) == 1 && x % d == 0 && x % (d * d) != 0) {
            return 0;
        }
    return 1;
}

int nrcifre(int x) {
    int c = 0;
    if (x == 0)
        return 1;
    while (x) {
        ++c;
        x = x / 10;
    }
    return c;
}

long long concatnr(int a, int b) {
    int c = nrcifre(b), p = 1;
    while (c)
        p = p * 10;
    while (a) {
        b = (a % 10) * p + b;
        a = a /  10;
        p = p * 10;
    }
    return b;
}

int main(){
    int c, n, v[10000000], nrp = 0, p = 0;
    fin >> c >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> v[i];
        if (verifputere(v[i]) == 1) {
            ++nrp;
            --i;
        }
    }
    for (int i = 1; i <= n / 2; ++i)
        if (verifputere(concatnr(v[i], v[n - i + 1])) == 1) {
            ++p;
            fout << v[i] << " " << v[n - i + 1] << endl;
        }
    if (p == 0)
        fout << -1;
    return 0;
}