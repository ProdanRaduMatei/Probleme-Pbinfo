#include <bits/stdc++.h>

using namespace std;

ifstream fin("extindere.in");
ofstream fout("extindere.out");

int n;

int main()
{
    fin >> n;
    int p = 1;
    while (p * 4 < n)
        p *= 4;
    bool op = 0;
    while (n > 4) {
        if (n > p && n <= 3 * p)
            op ^= 1;
        n = (n - 1) % p + 1;
        p /= 4;
    }
    if (op) {
        if (n == 2 || n == 3)
            fout << "1\n";
        if (n == 1 || n == 4)
            fout << "2\n";
    }
    else {
        if (n == 2 || n == 3)
            fout << "2\n";
        if (n == 1 || n == 4)
            fout << "1\n";
    }
    return 0;
}