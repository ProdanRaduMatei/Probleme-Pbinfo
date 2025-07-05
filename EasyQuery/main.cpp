#include <iostream>
#include <fstream>

using namespace std;

long long int a[1000002], b[1000002];

int main()
{
    long long int n, s = 0, t, op, left, right, v, i;
    ifstream fin("easyquery.in");
    ofstream fout("easyquery.out");
    b[0] = 0;
    fin >> n;
    for (i = 1; i <= n; i++)
    {
        fin >> a[i];
        b[i] = a[i] - s;
        s += b[i];
    }
    fin >> t;
    for (i = 1; i <= t; ++i)
    {
        fin >> op >> left >> right >> v;
        if (op == 2)
            v = -v;
        b[left] += v;
        if (right < n)
            b[right + 1] -= v;
    }
    for (i = 1; i <= n; i++)
    {
        b[i] += b[i - 1];
        fout << b[i] << " ";
    }
    return 0;
}