#include <bits/stdc++.h>
#define ULL unsigned long long int
using namespace std;

bool CifreDistincte(ULL n) {
    int FrC[10] = {0};
    while (n) {
        ++FrC[n % 10];
        n /= 10;
    }
    for (int i = 1; i <= 9; ++i)
        if (FrC[i] > 1)
            return false;
    return true;
}

ULL UltimaCifra(ULL n, ULL &p) {
    while (n > 9) {
        p *= 10;
        n /= 10;
    }
    p *= 10;
    return n;
}

ULL Transforma(ULL n) {
    ULL aux = n;
    int FrC[10] = {0};
    while (aux) {
        ++FrC[aux % 10];
        aux /= 10;
    }
    ULL p = 1;
    while (n) {
        int c = n % 10;
        if (c && FrC[c] == 1) {
            aux = aux + c * p;
            p *= 10;
            --FrC[c] = 0;
        }
        else
            if (c && FrC[c] > 1)
                --FrC[c];
        n /= 10;
    }
    return aux;
}

int NrCifre(int n) {
    int nrc = 0;
    while (n) {
        ++nrc;
        n /= 10;
    }
    return nrc;
}

int main() {
    int c, n;
    ifstream fin("siruri.in");
    fin >> c >> n;
    ofstream fout("siruri.out");
    if (c == 1) {
        int x, cnt = 0;
        for (int i = 1; i <= n; ++i) {
            fin >> x;
            if (CifreDistincte(x))
                ++cnt;
        }
        fout << cnt;
        return 0;
    }
    ULL x, xu, p, a[n + 2];
    fin >> x;
    int N = 0, i = 1;
    while (i <= n) {
        fin >> xu;
        ++i;
        p = 1;
        if (x % 10 != UltimaCifra(xu, p)) {
            a[++N] = Transforma(x);
            x = xu;
        }
        else {
            xu = Transforma(xu);
            p = 1;
            while (x % 10 == UltimaCifra(xu, p)) {
                x = x * p + xu;
                x = Transforma(x);
                fin >> xu;
                ++i;
                p = 1;
            }
            a[++N] = x;
            x = xu;
        }
    }
    if (c == 2)
        fout << N << '\n';
    else {
        int FrNrC[N + 1], NrMaxC = 0, Nr = 1;
        for (int i = 1; i <= N; ++i) {
            FrNrC[i] = NrCifre(a[i]);
            if (FrNrC[i] >= NrMaxC) {
                if (FrNrC[i]>NrMaxC) {
                    NrMaxC = FrNrC[i];
                    Nr = 1;
                }
                else
                    ++Nr;
            }
        }
        fout << NrMaxC << ' ' << Nr << '\n';
    }
    return 0;
}