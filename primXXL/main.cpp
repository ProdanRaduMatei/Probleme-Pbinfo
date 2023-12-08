#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <fstream>

using namespace std;

ifstream fin("primxxl.in");
ofstream fout("primxxl.out");

int f[1000005], prim[1000005];
int n, k, cnt;

void ciur_desc() {
    int N = k;
    prim[1] = 1;
    for (int i = 2; i <= N; ++i)
        if (prim[i] == 0) {
            int val = i, p = 0;
            while (val <= k) {
                p += k / val;
                if (val > k / i)
                    break;
                val *= i;
            }
            f[i] = p;
            for (int j = 2 * i; j <= N; j += i)
                prim[j] = 1;
        }
}

bool eDivizor(int x) {
    int d = 2, p = 0;
    while (x % d == 0) {
        p++;
        x /= d;
    }
    if (p > f[d])
        return false;
    d++;
    if (d * d > x && x != 1)
        return true;
    while (x != 1) {
        if (d > k)
            return false;
        p = 0;
        while (x % d == 0) {
            p++;
            x /= d;
        }
        if (p > f[d])
            return false;
        d += 2;
        if (d * d > x && x != 1)
            d = x;
    }
    return true;
}

int main() {
    fin >> n >> k;
    ciur_desc();
    for (int i = 1; i <= n; ++i) {
        int x;
        fin >> x;
        if (x <= k)
            ++cnt;
        else
            if (eDivizor(x))
                cnt++;
    }
    fout << cnt << endl;
    return 0;
}