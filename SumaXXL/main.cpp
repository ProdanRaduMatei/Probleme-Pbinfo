#include<fstream>

using namespace std;

ifstream fin("sumaxxl.in");
ofstream fout("sumaxxl.out");

int a[101], b[101];

int main() {
    int n, m, t = 0;
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    for (int i = 1; i <= n / 2; ++i)
        swap(a[i], a[n - i + 1]);
    fin >> m;
    for (int j = 1; j <= m; ++j)
        fin >> b[j];
    for (int i = 1; i <= m / 2; ++i)
        swap(b[i], b[m - i + 1]);
    if (m > n)
        n = m;
    for (int i = 1; i <= n; i++) {
        int c = a[i] + b[i] + t;
        a[i] = c % 10;
        t = c / 10;
    }
    if (t > 0)
        a[++n] = t;
    for (int i = n; i >= 1; i--)
        fout << a[i];
    return 0;
}