#include <bits/stdc++.h>

using namespace std;

ifstream fin("ghiozdan.in");
ofstream fout("ghiozdan.out");

const int NMax = 100002;
int d, k, t, a[NMax];

bool OK(int dim) {
    int drum_ramas = t;
    for (int i = 1; i <= k; ++i)
        if (a[i] - a[i - 1] > dim)
            drum_ramas -= (a[i] - a[i - 1] - dim);
    if (drum_ramas < 0)
        return 0;
    return 1;
}

int cautbin(int lo, int hi) {
    int mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        int ok1 = OK(mid);
        int ok2 = OK(mid - 1);
        if (ok1 == 1 && ok2 == 0)
            return mid;
        else if (ok1 == 1)
            hi = mid - 1;
        else if (ok2 == 0)
            lo = mid + 1;
    }
    return 0;
}

int main() {
    fin >> d >> k >> t;
    a[0] = 0;
    for (int i = 1; i <= k; ++i)
        fin >> a[i];
    a[++k] = d;
    int G = cautbin(0, d);
    fout << G << endl;
    return 0;
}