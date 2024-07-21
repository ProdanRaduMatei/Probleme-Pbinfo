#include <fstream>

using namespace std;

ifstream fin("exponent.in");
ofstream fout("exponent.out");

int n, a, k, m, ciur[1001], c[1001], p[1001], e[1001], ea[1001], emin;

void CiurEratostene()
{
    int i, j;
    ciur[0] = ciur[1] = 1;
    for (i = 2; i <= 1000; i++)
        if (ciur[i] == 0)
        {
            k++;
            c[k] = i;
            for (j = i * i; j <= a; j = j + i)
                ciur[j] = 1;
        }
}

int exponent(int p)
{
    int exp = 0, f = p;
    do
    {
        exp = exp + n / f;
        f = f * p;
    } while (n / f != 0);
    return exp;
}

int main()
{
    int i, exp;
    fin >> n >> a;
    CiurEratostene();
    i = 1;
    while (a > 1 && i <= k)
    {
        exp = 0;
        while (a % c[i] == 0)
        {
            exp++;
            a = a / c[i];
        }
        if (exp)
        {
            m++;
            p[m] = c[i];
            ea[m] = exp;
        }
        i++;
    }
    for (i = 1; i <= m; i++)
        e[i] = exponent(p[i]);
    emin = e[1] / ea[1];
    for (i = 2; i <= m; i++)
        if (e[i] / ea[i] < emin)
            emin = e[i] / ea[i];
    fout << emin << '\n';
    return 0;
}