#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("pinguin.in");
ofstream fout("pinguin.out");
int main()
{
    int n, c, i, a, cnt = 0, u, m = 0;
    fin >> c >> n;
    if (c == 1) {
        for (i = 1; i <= n; ++i) {
            fin >> a;
            if (a == 2)
                ++cnt;
        }
        fout << cnt;
    }
    if (c == 2) {
        fin >> a;
        if (a == 2)
            ++cnt;
        u = a;
        for (i = 2; i <= n; ++i) {
            fin >> a;
            if (a == 2 && u == 1)
                ++cnt;
            u = a;
        }
        fout << cnt;
    }
    if (c == 3) {
        for (i = 1; i <= n; ++i) {
            fin >> a;
            if (a == 1)
                cnt = 0;
            if (a == 2) {
                ++cnt;
                if (cnt > m)
                    m = cnt;
            }
        }
        fout << m;
    }
    return 0;
}
