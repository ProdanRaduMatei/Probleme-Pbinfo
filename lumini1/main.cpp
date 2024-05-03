#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("lumini.in");
ofstream fout("lumini.out");

int f[65538], n, nd, ndm, nrbec, copil, o;

struct led
{
    int nd;
    char nume[24];
} C[5001];

int nrdiv(int n)
{
    int nd = 1;
    for (int d = 2; d * d <= n; ++d)
    {
        int p = 0;
        while (n % d == 0)
        {
            n /= d;
            ++p;
        }
        if (p != 0)
            nd *= (p + 1);
    }
    if (n != 1)
        nd *= 2;
    return nd;
}

void diviz()
{
    for (int i = 1; i <= 65536; ++i)
    {
        int nd = nrdiv(i);
        if (f[nd] == 0)
            f[nd] = i;
    }
}

int main()
{
    diviz();
    fin >> o >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> C[i].nd >> C[i].nume;
        if (f[(C[i].nd)] > nrbec)
        {
            nrbec = f[(C[i].nd)];
            copil = i;
        }
    }
    if (o == 1)
        fout << nrbec << endl;
    if (o == 2)
        fout << C[copil].nume << endl;
    return 0;
}