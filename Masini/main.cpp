#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("masini.in");
ofstream fout("masini.out");

int n, t, m[1001];

int main()
{
    fin >> n >> t;
    for (int i = 1; i <= n; ++i)
        fin >> m[i];
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j)
            if (m[i] > m[j])
                swap(m[i], m[j]);
    }
    int i = 1;
    while (t > 0 && m[i] <= t)
        t = t - m[i++];
    fout << i - 1;
    return 0;
}
