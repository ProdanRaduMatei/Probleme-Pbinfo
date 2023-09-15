#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("platou3.in");
ofstream fout("platou3.out");

int main()
{
    int n, x, y, k, Max = 1;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> x;
        if (i > 1 && x > 0 && y > 0)
            ++Max;
        else
            Max = 1;
        if (Max > k)
            k = Max;
        y = x;
    }
    fout << k;
    return 0;
}
