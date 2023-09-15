#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("divizori4.in");
ofstream fout("divizori4.out");

int nrdiv(int x) {
    int nr = 0;
    for (int i = 1; i * i <= x; ++i)
        if (x % i == 0) {
            if (i * i == x)
                ++nr;
            else
                nr = nr + 2;
        }
    return nr;
}

int main()
{
    int n, c, v[50001], p;
    fin >> n >> c;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
    fin >> p;
    if (c == 1)
        fout << nrdiv(v[p]);
    else {
        int N = nrdiv(v[p]);
        sort(v + 1, v + 1 + n);
        for (int i = n; i >= 1; --i)
            if (nrdiv(v[i]) == N)
                fout << v[i] << " ";
    }
    return 0;
}
