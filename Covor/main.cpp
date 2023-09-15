#include <bits/stdc++.h>
 
using namespace std;

ifstream fin("covor.in");
ofstream fout("covor.out");

int n, k, r, p, m, c;

int main()
{
    fin >> n >> k >> c;
    r = 1;
    while (2 * (r + 1) * (r + 2) - r <= n)
        ++r;
    if (c == 1)
        fout << r << "\n";
    else {
        if (k > 2 * r * (r + 1) - (r - 1))
            fout << 0 << "\n";
        else {
            p = 1;
            m = 1 + r * (r + 1);
            if (k <= m) {
                while (k > 1 + p * (p + 1))
                    p++;
                fout << p << "\n";
            }
            else {
                p = r;
                while (k > (m + 2 * p - 1)) {
                    m = m + 2 * p - 1;
                    --p;
                }
                fout << p << "\n";
            }
        }
    }
    fout.close();
    fin.close();
    return 0;
}