#include <bits/stdc++.h>

using namespace std;

ifstream fin("skyline.in");
ofstream fout("skyline.out");

int n, h, l, x, maxx, mh, uc;
int a, b, v[2000000001][50001];

int main()
{
    fin >> n;
    uc = 1;
    for (int i = 1; i <= n; ++i) {
        fin >> a >> b;
        if (a > mh)
            mh = a;
        for (h = 1; h <= a; ++h)
            for (l = uc; l <= uc + b - 1; ++l)
                ++v[h][l];
    }
    for (int i = 1; i <= mh; ++i) {
        x = get(v, )
    }
    return 0;
}
