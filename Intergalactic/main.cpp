#include <bits/stdc++.h>
#define nmax 2000002
using namespace std;

ifstream fin("intergalactic.in");
ofstream fout("intergalactic.out");

bitset<nmax> b;
int n;
int B[nmax], nb; /// se retin numerele neprime
int A[nmax], na; /// se retin numerele prime

void Eratostene(int n) {
    int i, j;
    b[0] = b[1] = 1;
    for (i = 4; i <= n; i += 2)
        b[i] = 1;
    for (i = 3; i * i <= n; i += 2)
        if (b[i] == 0)
            for (j = i * i; j <= n; j += 2 * i)
                b[j] = 1;
}

long long NumaraSume(int suma) {
    if (A[1] + B[1] > suma)
        return 0;
    if (A[na] + B[nb] <= suma)
        return 1LL * na * nb;
    int i, j;
    long long cnt = 0;
    j = na;
    for (i = 1; i <= nb && j >= 1; i++) {
        while (j >= 1 && A[j] + B[i] > suma)
            j--;
        cnt += j;
    }
    return cnt;
}

int main() {
    int i, x, T, k, st, dr, sol, suma;
    long long cnt;
    Eratostene(2000000);
    fin >> n >> T;
    for (i = 1; i <= n; i++) {
        fin >> x;
        if (b[x] == 0)
            A[++na] = x;
        else
            B[++nb] = x;
    }
    sort(A + 1, A + na + 1);
    sort(B + 1, B + nb + 1);
    while (T--) {
        fin >> k;
        st = 0;
        dr = 1e9;
        sol = dr;
        while (st <= dr) {
            suma = (st + dr) / 2;
            cnt = NumaraSume(suma);
            if (cnt >= k) {
                sol = suma;
                dr = suma - 1;
            }
            else
                st = suma + 1;
        }
        fout << sol << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}