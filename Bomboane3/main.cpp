#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

long cmmdc(long a, long b)
{
    while (a != b)
        if (a > b)
            a -= b;
        else
            b -= a;
    return a;
}

int main()
{
    ifstream fin("bomboane3.in");
    ofstream fout("bomboane3.out");
    int n, p, i, k = 0, j, nb;
    long b[10001], c[10001], min, s, r, st, dr;
    fin >> p >> n;
    if (p == 1)
    {
        fin >> b[1];
        min = b[1];
        for (i = 2; i <= n; ++i)
        {
            fin >> b[i];
            if (b[i] < min)
                min = b[i];
        }
        for (i = 1; i <= n; ++i)
            b[i] -= min;
        i = 1;
        while (b[i] == 0)
            ++i;
        k = b[i];
        for (i = 2; i <= n; ++i)
            if (b[i] != 0)
                k = cmmdc(k, b[i]);
        fout << k;
    }
    else
    {
        for (i = 1; i <= n; ++i)
        {
            fin >> b[i];
            c[i] = sqrt(2 * b[i]);
            if (c[i] * (c[1] + 1) > 2 * b[i])
                c[i]--;
            s = 0;
            j = 0;
            do
            {
                j++;
                s += j;
            } while (s <= b[i]);
            if (s == b[i])
                r = j;
            else
            {
                s -= j;
                --j;
                r = j + b[i] - s;
            }
            st = 1;
            dr = j;
            p = 1;
            fout << j << " ";
            while (st <= dr)
            {
                if (p == 1)
                    fout << 1 << " " << r << " ";
                else if (st == dr)
                    fout << st << " ";
                else
                    fout << st << " " << dr << " ";
                st++;
                dr--;
                p++;
            }
            fout << endl;
        }
    }
    return 0;
}