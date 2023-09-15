#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("vapoare.in");
ofstream fout("vapoare.out");

long long x, y, z1, z2, d, i, r, v1, v2;

int main()
{
    fin >> x >> y;
    fin >> z1 >> z2;
    v1 = 2 * x * 7 + z1;
    v2 = 2 * y * 7 + z2;
    d = v1;
    i = v2;
    r = d % i;
    while (r) {
        d = i;
        i = r;
        r = d % i;
    }
    fout << (v1 * v2) / i;
    return 0;
}
