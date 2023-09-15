#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cifre006.in");
ofstream fout("cifre006.out");

int main()
{
    long long n;
    int k, c[11] = {0}, cn = 0, l = 0;
    fin >> n >> k;
    while (n) {
        if (n % 10 == k)
            ++cn;
        else
            c[l++] = n % 10;
        n = n / 10;
    }
    fout << cn << endl;
    for (int i = 1; i <= cn; ++i)
        fout << k;
    for (int i = l - 1; i >= 0; --i)
        fout << c[i];
    return 0;
}
