#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("triunghiul.in");
ofstream fout("triunghiul.out");

long long v[21][21], n;

int main()
{
    fin >> n;
    v[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n + 1; ++j)
            v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
    }
    for (int j = 1; j <= n + 1; ++j)
        fout << v[n][j] << " ";
    return 0;
}
