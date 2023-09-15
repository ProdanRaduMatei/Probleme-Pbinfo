#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("puncte4.in");
ofstream fout("puncte4.out");

int main()
{
    int n, m, x[100001], y[100001], a, M = 10000000;
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> x[i] >> y[i];
    for (int i = 1; i <= m; ++i) {
        fin >> a;
        M = 10000000;
        for (int j = 1; j <= n; ++j) {
            cout << x[j] << " " << a << " " << y[j] << endl;
            int d = (a - x[j]) * (a - x[j]) + y[j] * y[j];
            if (d < M)
                M = d;
        }
        fout << M << endl;
    }
    return 0;
}
