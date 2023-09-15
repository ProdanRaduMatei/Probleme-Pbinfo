#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("platou2.in");
ofstream fout("platou2.out");

int main()
{
    int a, n, k, len, b, i;
    fin >> n >> a;
    len = 1;
    k = 1;
    b = a;
    for (int i = 2; i <= n; ++i) {
        fin >> a;
        if (a > b)
            ++len;
        else {
            if (len > k)
                k = len;
            len = 1;
        }
        b = a;
    }
    if (len > k)
        k = len;
    fout << k;
    return 0;
}
