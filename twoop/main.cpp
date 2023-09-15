#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("twoop.in");
ofstream fout("twoop.out");

int main()
{
    int n, o1, o2, v[100000], st, dr, val, poz, i, j;
    fin >> n >> o1 >> o2;
    for (i = 1; i <= n; ++i)
        fin >> v[i];
    for (i = 0; i < o1; ++i) {
        fin >> st >> dr >> val;
        for (j = st; j <= dr; ++j)
            v[j] = v[j] + val;
    }
    for (i = 0; i < o2; ++i) {
        fin >> poz;
        fout << v[poz] << "\n";
    }
    return 0;
}
