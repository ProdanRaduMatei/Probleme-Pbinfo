#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("credite.in");
ofstream fout("credite.out");

struct problema{
    int l, p;
}v[1001], o[1001];

int main()
{
    int n, s = 0;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> v[i].p >> v[i].l;
        if (o[v[i].l].l == 0) {
            ++o[v[i].l].l;
            o[v[i].l].p = v[i].p;
        }
        else
            if (o[v[i].l].p < v[i].p)
                o[v[i].l].p = v[i].p;
    }
    for (int i = 1; i <= n; ++i)
        s = s + o[i].p;
    fout << s;
    return 0;
}
