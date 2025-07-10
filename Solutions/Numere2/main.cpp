#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("numere2.in");
ofstream fout("numere2.out");

int main()
{
    int n, v[25001], z = 0, x[101] = {0}, a, m = 0, M = 100, j = 1;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> v[i];
        a = v[i];
        ++x[a];
        if (a > m)
            m = a;
        if (a < M)
            M = a;
    }
    v[25001] = {0};
    for (int i = M; i <= m; ++i) {
        if (x[i] % 2 == 0)
            z = z + x[i] / 2;
        else {
            v[j] = i;
            ++j;
        }
    }
    fout << z << "\n";
    for (int k = 1; k < j; ++k)
        fout << v[k] << " ";
    return 0;
}
