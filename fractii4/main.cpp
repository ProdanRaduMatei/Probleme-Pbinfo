#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("fractii4.in");
ofstream fout("fractii4.out");

int main()
{
    int p, n, v[100000], i, nu, nr, cnt, d;
    fin >> p >> n;
    if (p == 1) {
        for (i = 1; i <= n; ++i) {
                fout << i << " ";
            cnt = 0;
            fin >> nu >> nr;
            if (nu < nr) {
                for (d = 2; d <= nr / 2; ++d) {
                    if (nu % d == 0 && nr % d == 0)
                        ++cnt;
                }
                if (nu % nr == 0)
                    ++cnt;
                if (cnt == 0) {
                    --cnt;
                    fout << cnt << endl;
                }
                else
                    fout << cnt << endl;
            }
            else {
                for (d = 2; d <= nu / 2; ++d) {
                    if (nu % d == 0 && nr % d == 0)
                        ++cnt;
                }
                if (nr % nu == 0)
                    ++cnt;
            }
            if (cnt == 0) {
                --cnt;
                fout << cnt << endl;
            }
            else
                fout << cnt << endl;
        }
    }
    else if (p == 2) {
        for (i = 1; i <= n; ++i) {
            cnt = 0;
            fin >> nu >> nr;
            if (nu < nr) {
                for (d = 2; d <= nr / 2; ++d) {
                    if (nu % d == 0 && nr % d == 0) {
                        nu = nu / d;
                        nr = nr / d;
                    }
                }
                if (nu % nr == 0) {
                    nu = nu / nr;
                    nr = nr / nr;
                }
            }
            else {
                for (d = 2; d <= nu / 2; ++d) {
                    if (nu % d == 0 && nr % d == 0) {
                        nu = nu / d;
                        nr = nr / d;
                    }
                }
                if (nr % nu == 0) {
                    nr = nr / nu;
                    nu = nu / nu;
                }
            }
            fout << nu << "/" << nr << endl;
        }
    }
    return 0;
}
