#include <bits/stdc++.h>

using namespace std;

ifstream fin("mincols1.in");
ofstream fout("mincols1.out");

int main() {
    long long n, a[30][30], p = 1, mini;
    fin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            fin >> a[i][j];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + j == n - 1) {
                mini = a[i][j];
                int cnt = 0;
                for (int k = 0; k < n; ++k) {
                    if (a[k][j] >= mini)
                    cnt++;
                }
                if (cnt == n)
                p *= mini;
                p = p % 10;
            }
        }
    }
    fout << p % 10;
    return 0;
}
