#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream fin("smartphone1.in");
ofstream fout("smartphone1.out");

int main() {
    int n, c = 0, x;
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> x;
        int ok = 1;
        while (x > 9 && ok)
        {
            int u = x % 10;
            x = x / 10;
            if (abs(u - x % 10) > 3 || u == x % 10)
                ok = 0;
        }
        if (ok)
            ++c;
    }
    fout << c;
    return 0;
}
