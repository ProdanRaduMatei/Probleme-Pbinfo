#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("alo.in");
ofstream fout("alo.out");

int e, n, nr, d, s, p, u;

int main()
{
    fin >> e >> n;
    s = e;
    for (int i = 1; i <= n; ++i) {
        fin >> nr >> d;
        p = nr / 10000;
        u = n % 10;
        if (p == 1) {
            if (u == 9)
                s = s + 0;
            else
                s = s - 2 * d;
        }
        else {
            if (u == 5)
                s = s + d;
            else
                s = s;
        }
    }
    fout << s;
    return 0;
}
