#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <map>

using namespace std;
#define Inf 0x3f3f3f3f
#define MAX 2000000000000000000LL

ifstream fin("aranjare1.in");
ofstream fout("aranjare1.out");

int n, x, y, m[666013 + 666], newnr, lim, grupe;

int main()
{
    fin >> n >> x >> y;
    m[x] = -1;
    m[y] = -1;
    for (int i = 3; i <= n; ++i)
    {
        newnr = (17 * x + 35 * y) % 666013 + 3;
        m[newnr] = -1;
        x = y;
        y = newnr;
        lim = max(lim, newnr);
    }
    for (int i = 3; i <= lim; ++i)
        if (m[i] == -1)
        {
            grupe++;
            for (int j = i; j <= lim; j += i)
                m[j] = grupe;
        }
    fout << grupe;
    return 0;
}