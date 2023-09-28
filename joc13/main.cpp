#include <bits/stdc++.h>

using namespace std;

ifstream fin("joc.in");
ofstream fout("joc.out");

int C, N, x1, x2, fr[7], c1[100001], c2[100001], a, b, lc1, lc2;

unsigned long numardiv(unsigned long n) {
    unsigned long p = 1, j, al = 0, ok = 0, p1, p2;
    while (n % 2 == 0) {
        n /= 2;
        al++;
    }
    p *= (al + 1);
    for (j = 3; j * j <= n && n != 1 && !ok; j += 2 ) {
        al = 0;
        while (n % j == 0) {
            n /= j;
            al++;
        }
        p *= (al + 1);
        if ( n == 1)
            ok = 1;
    }
    if (n > 1)
        p *= 2;
    return p;
}

int main() {
    fin >> C >> N;
    if (C == 1) {
        fout << numardiv(N);
        return 0;
    }
    c1[1] = c2[1] = 1;
    lc1 = lc2 = 1;
    int nm = 1, p1 = 1, p2 = 1;
    a = 1;
    do {
        if (a == 1) {
            if (nm % 2) {
                if (p1 < N) {
                    x1 = (nm + (p1 + N) % 10) % 6 + 1;
                    fr[x1]++;
                    if (p1 + x1 <= N) {
                        nm++;
                        p1 = p1 + x1;
                    }
                    else {
                        nm++;
                        p1 = N;
                    }
                    if (p1 <= N)
                        c1[++lc1] = p1;
                    if (p2 == p1) {
                        p2 = 1;
                        c2[++lc2] = p2;
                    }
                    if (x1 == 6 && p1 < N) {
                        a = 1;
                        b = 0;
                    }
                }
            }
            else {
                if (p1 < N) {
                    x1 = ((((nm + 1) % 5) + ((p1 + N) % 10)) % 6) + 1;
                    fr[x1]++;
                    if (p1 + x1 <= N) {
                        p1 = p1 + x1;
                        nm++;
                    }
                    else {
                        p1 = N;
                        nm++;
                    }
                    if (p2 == p1) {
                        p2 = 1;
                        c2[++lc2] = p2;
                    }
                    if (p1 <= N)
                        c1[++lc1] = p1;
                    if (x1 == 6 && p1 < N) {
                        a = 1;
                        b = 0;
                    }
                }
            }
            if (x1 != 6) {
                a = 0;
                b = 1;
            }
        }
        else if (b == 1) {
            if (nm % 2) {
                if (p2 < N) {
                    x2 = (nm + (p2 + N) % 10) % 6 + 1;
                    fr[x2]++;
                    if (p2 + x2 <= N) {
                        nm++;
                        p2 = p2 + x2;
                    }
                    else {
                        p2 = N;
                        nm++;
                    }
                    if (p2 <= N)
                        c2[++lc2] = p2;
                    if (p2 == p1) {
                        p1 = 1;
                        c1[++lc1] = p1;
                    }
                    if (x2 == 6 && p2 < N) {
                        a = 0;
                        b = 1;
                    }
                }
            }
            else {
                if (p2 < N) {
                    x2 = ((((nm + 1) % 5) + ((p2 + N) % 10)) % 6) + 1;
                    fr[x2]++;
                    if (p2 + x2 <= N) {
                        nm++;
                        p2 = p2 + x2;
                    }
                    else {
                        p2 = N;
                        nm++;
                    }
                    if (p2 == p1) {
                        p1 = 1;
                        c1[++lc1] = p1;
                    }
                    if (p2 <= N)
                        c2[++lc2] = p2;
                    if (x2 == 6 && p2 < N) {
                        a = 0;
                        b = 1;
                    }
                }
            }
            if (x2 != 6) {
                b = 0;
                a = 1;
            }
        }
    } while (p1 < N && p2 < N);
    if (C == 2) {
        int sol = 0;
        for (int i = 0; i <= 6; ++i)
            if (fr[i] > sol)
                sol = fr[i];
        fout << sol;
    }
    else {
        if (c1[lc1] == N)
            for (int i = 1; i <= lc1; ++i)
                fout << c1[i] << " ";
        else
            for (int i = 1; i <= lc2; ++i)
                fout << c2[i] << " ";
    }
    return 0;
}