#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("aoc2020.in");
ofstream fout("aoc2020.out");

int main()
{
    int n, x, c;
    long long cmmmc, ccmmmc;
    fin >> n;
    fin >> x;
    cmmmc = x;
    ccmmmc = x;
    for (int i = 2; i <= n; ++i) {
        fin >> x;
        c = x;
        while (ccmmmc != c) {
            if (ccmmmc > c)
                ccmmmc = ccmmmc - c;
            else if (ccmmmc < c)
                c = c - ccmmmc;
        }
        cmmmc = cmmmc * (x / c);
    }
    fout << cmmmc;
    return 0;
}
