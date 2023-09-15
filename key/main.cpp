#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("key.in");
ofstream fout("key.out");

int main()
{
    int p, n, pr, s = 0, cn = 0;
    char u[4], c[4];
    fin >> p >> u >> n;
    for (int i = 0; i < n; ++i) {
        fin >> c >> pr;
        cn = 0;
        for (int j = 0; j < 4; ++j)
            if (c[j] != u[j])
                ++cn;
        if (p == 1)
            fout << cn << " ";
        else {
            if (cn == 3)
                s = s + pr;
            else if (cn == 2)
                s = s + pr / 3 * 2;
            else if (cn == 1)
                s = s + pr / 3;
        }
    }
    if (p == 2) {
        if (s == 0)
            fout << "GRATIS";
        else
            fout << s;
    }
    return 0;
}
