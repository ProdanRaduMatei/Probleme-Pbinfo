#include <bits/stdc++.h>

using namespace std;

ifstream fin("vecine.in");
ofstream fout("vecine.out");

int P, N, cif1, cif2, nrp;
int c[100001], k, X, Y, Xmax;

int main() {
    int i, j;
    fin >> P >> N;
    if (P == 1) {
        fin >> cif1;
        for (i = 2; i <= N; ++i) {
            fin >> cif2;
            if (cif1 + 1 == cif2)
                nrp++;
            cif1 = cif2;
        }
        fout << nrp;
        return 0;
    }
    for (i = 1; i <= N; ++i)
        fin >> c[i];
    for (k = 1; k <= 10; ++k) {
        for (i = 1; i <= N - 2 * k + 1; ++i) {
            X = 0;
            Y = 0;
            for (j = i; j <= i + k - 1; ++j)
                X = X * 10 + c[j];
            for (j = i + k; j <= i + 2 * k - 1; ++j)
                Y = Y * 10 + c[j];
            if (X + 1 == Y)
                if (X > Xmax)
                    Xmax = X;
            if (i < N - 2 * k + 1)
                Y = Y * 10 + c[i + 2 * k];
            if (Y - X == 1)
                if (X > Xmax)
                    Xmax = X;
        }
    }
    fout << Xmax;
    return 0;
}