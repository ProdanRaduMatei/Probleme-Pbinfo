#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("spectacole.in");
ofstream fout("spectacole.out");

int n, aux, k;

struct spectacol {
    int x, y;
}v[105];

bool cmp(spectacol a, spectacol b) {
    return a.y < b.y;
}

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i].x >> v[i].y;
    sort(v + 1, v + n + 1, cmp);
    for (int i = 1; i <= n; ++i)
        if (v[i].x >= aux) {
            ++k;
            aux = v[i].y;
        }
    fout << k;
    return 0;
}
