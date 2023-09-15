#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("aoc2020.in");
ofstream fout("aoc2020.out");

int main()
{
    long long n, v[102], a, b, x, r, y;
    fin >> n;
    fin >> a;
    x = a;
    if (n >= 2) {
        fin >> b;
        x = a;
        y = b;
        while (b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        x = (x * y) / a;
        for (int i = 3; i <= n; ++i) {
            fin >> v[i];
            b = v[i];
            a = x;
            while (b != 0) {
                r = a % b;
                a = b;
                b = r;
            }
            x = (v[i] * x) / a;
        }
    }
    fout << x;
    return 0;
}
