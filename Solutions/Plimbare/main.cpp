#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("plimbare.in");
ofstream fout("plimbare.out");
int main()
{
    int n, cnt = 0, a, i, c, b, u;
    fin >> n;
    for (i = 1; i <= n; ++i) {
        fin >> a;
        if (a < 10)
            ++cnt;
        else {
            c = a;
            b = 0;
            while (c) {
                u = c % 10;
                b = b * 10 + u;
                c = c / 10;
            }
            if (a == b)
                ++cnt;
        }
    }
    fout << cnt;
    return 0;
}
