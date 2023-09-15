#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("zone.in");
ofstream fout("zone.out");

int main()
{
    int n, v[301], pp = -1, ui = -1;
    fin >> n;
    for (int i = 1; i <= 3 * n; ++i) {
        fin >> v[i];
        if (i <= n)
            if (v[i] % 2 == 0 && pp == -1)
                pp = i;
        if (i > 2 * n)
            if (v[i] % 2 == 1)
                ui = i;
    }
    if (pp != -1 && ui != -1) {
        swap(v[pp], v[ui]);
    }
    for (int i = 1; i <= 3 * n; ++i)
        fout << v[i] << " ";
    return 0;
}
