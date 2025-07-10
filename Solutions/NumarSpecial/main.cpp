#include <bits/stdc++.h>

#define N 1000001

using namespace std;

ifstream fin("numarspecial.in");
ofstream fout("numarspecial.out");

int v[N],n, x, ct, ct1;
bool C[1000005];

void Ciur() {
    int i, j;
    C[2] = 1;
    for (i = 3; i <= 1000001; i += 2)
        C[i] = 1;
    for (i = 3; i * i <= 1000001; i += 2)
        if (C[i] == 1)
            for (j = 3 * i; j <= 1000001; j += 2 * i)
                C[j] = 0;
}

void citire() {
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> v[i];
}

void Cerinta1() {
    for (int i = 1; i <= n; i++)
        if (v[i] % 9 == 0)
            ct++;

    fout << ct << "\n";
}

void Cerinta2() {

    for (int i = 1; i < n; i++)
        if (v[i] % 9 == 0 && C[v[i - 1]]==1 && C[v[i + 1]]==1)
            ct1++;
    fout << ct1 << "\n";
}

void Cerinta3() {
    int rang = 0, M = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] % 9 == 0) {
            int poz1 = i - 1, poz2 = i + 1, rang = 0;
            while (C[v[poz1]] && C[v[poz2]]) {
                poz1--;
                poz2++;
                rang++;
                if (poz1 < 0 || poz2>n)
                    break;
            }
            M = max(rang, M);
        }
    }
    fout << M;
}

int main() {
    citire();
    Ciur();
    Cerinta1();
    Cerinta2();
    Cerinta3();
    return 0;
}