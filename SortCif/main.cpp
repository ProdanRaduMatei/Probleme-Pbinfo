#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sortcif.in");
ofstream fout("sortcif.out");

int main()
{
    int n, v[101], c[101], s = 0, m;
    fin >> n;
    for (int i = 1; i <= n; ++ i) {
        fin >> v[i];
        m = v[i];
        s = 0;
        while (m) {
            s = s + m % 10;
            m = m / 10;
        }
        c[i] = s;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (c[i] > c[j]) {
                swap (c[i], c[j]);
                swap (v[i], v[j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        fout << v[i] << " ";
    return 0;
}
