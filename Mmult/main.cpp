#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("mmult.in");
ofstream fout("mmult.out");

int f[100001];

int main() {
    int n, i, x, m = 0;
    bool valid = true;
    fin >> n;
    for (i = 0; i < n; ++i) {
        fin >> x;
        m = max(m, x);
        f[x]++;
    }
    for (i = 2; i <= m; ++i)
        if (f[i] > f[i - 1]) {
            valid = false;
            break;
        }
    if (valid)
        fout << f[1];
    else
        fout << -1;
}