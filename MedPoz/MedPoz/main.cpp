#include <bits/stdc++.h>

using namespace std;

ifstream fin("medpoz.in");
ofstream fout("medpoz.out");

int main() {
    long long n, a[201][201], cnt = 0, v[205], ok = 0, s = 0;
    fin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        fin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i > j && a[i][j] > 0) {
                s += a[i][j];
                cnt++;
                ok = 1;
            }
        }
    if (ok != 0) {
        double x = trunc((double)s / cnt * 1000) / 1000.0;
        fout << fixed << setprecision(3) << x;
    }
    else
        fout << "NU EXISTA";
    fin.close();
    fout.close();
    return 0;
}
