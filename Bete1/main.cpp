#include <bits/stdc++.h>

using namespace std;

ifstream fin("bete1.in");
ofstream fout("bete1.out");

int a[1001], b[1001], N, L, P, K;

int main()
{
    fin >> N;
    unsigned long long int S = 0;
    for (int i = 0; i < N; ++i) {
        fin >> a[i];
        S = S + a[i];
    }
    for (int i = 0; i < N; ++i) {
        fin >> b[i];
        S = S + b[i];
    }
    L = S / N;
    sort(a, a + N, greater<int>());
    sort(b, b + N, greater<int>());
    K = a[0] + b[0];
    for (int i = 0; i < N; ++i) {
        if (a[i] + b[i] != K)
            break;
        else
            ++P;
    }
    fout << L << endl << K << endl << P;
    return 0;
}
