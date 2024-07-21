#include <iostream>
#include <fstream>
#include <set>

using namespace std;

fstream fin("minge.in");
ofstream fout("minge.out");

int c[10001];
set<int> v;

int main(void)
{
    int p, n, k, i, j, x, y;
    bool valid;
    fin >> p >> n >> k;
    for (i = 0; i < k; i++)
    {
        fin >> x >> y;
        c[x] = y;
        v.insert(x);
        v.insert(y);
    }
    if (p == 1)
        fout << n - v.size() << endl;
    else
    {
        for (j = 1; j <= n; j++)
            if (c[j])
            {
                valid = true;
                for (i = 1; i <= n; i++)
                    if (c[i] == j)
                        valid = false;
                if (valid)
                    break;
            }
        if (!valid)
            fout << 0 << endl;
        else
            do
            {
                fout << j << " ";
                j = c[j];
            } while (j != 0);
        fout << endl;
    }
    return 0;
}