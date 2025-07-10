#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("bac.in");
ofstream fout("bac.out");

int s, d, n, u, um;

int main()
{
    fin >> s >> d;
    int i, j;
    while (fin >> i >> j)
    {
        ++u;
        int start = max(s, i);
        int finish = min(d, j);
        if (finish - start >= 1)
        {
            ++n;
            um = u;
        }
    }
    fout << n << " " << um;
    fin.close();
    fout.close();
    return 0;
}