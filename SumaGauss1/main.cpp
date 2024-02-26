#include <fstream>
#include <string.h>

using namespace std;

ifstream fin("sumagauss1.in");
ofstream fout("sumagauss1.out");

typedef int Nrmare[1005];
void atribmic(Nrmare a, long long int n)
{
    int k = 0;
    if (n == 0)
    {
        a[0] = 1;
        a[1] = 0;
    }
    else
    {
        while (n > 0)
        {
            a[++k] = n % 10;
            n /= 10;
        }
        a[0] = k;
    }
}

void aduna(Nrmare a, Nrmare b)
{
    int t = 0, i;
    while (a[0] < b[0])
        a[++a[0]] = 0;
    while (b[0] < a[0])
        b[++b[0]] = 0;
    for (i = 1; i <= a[0]; ++i)
    {
        t = t + a[i] + b[i];
        a[i] = t % 10;
        t = t / 10;
    }
    if (t)
        a[++a[0]] = t;
}

void scad(Nrmare a, Nrmare b)
{
    int i, j, t;
    while (a[0] < b[0])
        a[++a[0]] = 0;
    while (b[0] < a[0])
        b[++b[0]] = 0;
    t = 0;
    for (i = 1; i <= a[0]; ++i)
    {
        a[i] = t + a[i] - b[i];
        if (a[i] < 0)
        {
            a[i] += 10;
            t = -1;
        }
        else
            t = 0;
    }
    while (a[0] > 0 && a[a[0]] == 0)
        --a[0];
    if (a[0] == 0)
    {
        a[0] = 1;
        a[a[0]] = 0;
    }
}

void Produsmic(Nrmare x, long long int n)
{
    int i;
    long long int t = 0;
    for (i = 1; i <= x[0]; ++i, t /= 10)
    {
        t += (long long int)(x[i] * n);
        x[i] = t % 10;
    }
    for (; t; t /= 10)
        x[++x[0]] = t % 10;
}

void impart(Nrmare a, long long int n)
{
    int i;
    long long int r = 0;
    for (i = a[0]; i >= 1; --i)
    {
        r = r * 10 + a[i];
        a[i] = r / n;
        r = r % n;
    }
    while (a[0] > 0 && a[a[0]] == 0)
        a[0]--;
}

void inmultesc(Nrmare a, Nrmare b)
{
    int t = 0, i, j;
    Nrmare z = {};
    z[0] = a[0] + b[0] - 1;
    for (i = 1; i <= a[0]; ++i)
        for (j = 1; j <= b[0]; ++j)
            z[i + j - 1] = z[i + j - 1] + a[i] * b[j];
    for (i = 1; i <= z[0]; ++i)
    {
        t = t + z[i];
        z[i] = t % 10;
        t = t / 10;
    }
    while (t > 0)
    {
        z[++z[0]] = t % 10;
        t = t / 10;
    }
    for (i = 0; i <= z[0]; ++i)
        a[i] = z[i];
}

void s1(Nrmare s, int n)
{
    atribmic(s, n);
    Produsmic(s, n + 1);
    impart(s, 2);
}

void s2(Nrmare s, int n)
{
    atribmic(s, n);
    Produsmic(s, 2 * n + 1);
    Produsmic(s, n + 1);
    impart(s, 6);
}

void s3(Nrmare s, int n)
{
    s1(s, n);
    inmultesc(s, s);
}

void s4(Nrmare s, int n)
{
    int i;
    Nrmare f, a, b, c, d, aa;
    atribmic(s, n + 1);
    atribmic(f, n + 1);
    for (i = 1; i <= 4; ++i)
        Produsmic(s, n + 1);
    scad(s, f);
    s3(a, n);
    s2(b, n);
    aduna(a, b);
    Produsmic(a, 10);
    scad(s, a);
    s1(aa, n);
    Produsmic(aa, 5);
    scad(s, aa);
    impart(s, 5);
}

int main()
{
    int n, i;
    Nrmare s, t, f;
    fin >> n;
    s4(s, n);
    s2(t, n);
    s3(f, n);
    aduna(s, t);
    aduna(s, f);
    aduna(s, f);
    impart(s, 4);
    for (i = s[0]; i >= 1; --i)
        fout << s[i];
    return 0;
}