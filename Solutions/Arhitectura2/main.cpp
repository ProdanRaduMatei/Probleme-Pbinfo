#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("arhitectura2.in");
ofstream fout("arhitectura2.out");

int n, v[500001], m, aux;
int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    sort(v + 1, v + 1 + n);
    for (int i = n; i >= 1; --i)
        fout << v[i] << " ";
    fout << endl << 0 << " ";
    for (int i = n - 1; i >= 2; --i)
        if ((v[i - 1] + v[i + 1]) / 2 == v[i])
            fout << 1 << " ";
        else
            fout << 0 << " ";
    fout << 0;
    return 0;
}
