#include <bits/stdc++.h>

using namespace std;

ifstream fin("2genc.in");
ofstream fout("2genc.out");

int n, m, x[11];

void backtrack(int k) {
    for (int i = 1; i <= n; ++i) {
        x[k] = x[k] * 10 + i;
        if (x[k] < 111)
            backtrack(k);
        else
            if (k > 1 && )
    }
}

int main()
{
    cin >> n >> m;
    backtrack(1);
    return 0;
}
