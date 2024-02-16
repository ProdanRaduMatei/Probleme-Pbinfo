#include <fstream>
#include <limits.h>
#include <cmath>
#include <bitset>
#define N 100000

using namespace std;

ifstream fin("num_sum_div.in");
ofstream fout("num_sum_div.out");

bitset<N> u;
long long int prim[40000], nr_prime;
long long Vmax;

void ciur()
{
    long long int i, j;
    u[0] = 1, u[1] = 1;
    for (i = 4; i <= N; i += 2)
        u[i] = 1;
    for (i = 3; i * i <= N; i += 2)
        if (u[i] == 0)
            for (j = i * i; j <= N; j += 2 * i)
                u[j] = 1;
    nr_prime = 1;
    prim[1] = 2;
    for (i = 3; i <= N; i += 2)
        if (u[i] == 0)
            prim[++nr_prime] = i;
}

long long int Sum_Div(long long int x)
{
    long long int d, k, exp;
    long long nr = 1;
    k = 1;
    d = prim[k];
    while (x > 1)
    {
        exp = 0;
        while (x % d == 0)
        {
            ++exp;
            x /= d;
        }
        if (exp)
            nr *= (pow(d, exp + 1) - 1) / (d - 1);
        ++k;
        if (k <= nr_prime)
        {
            d = prim[k];
            if (x > 1 && d * d > x)
            {
                nr *= (x + 1);
                x = 1;
            }
        }
        else
        {
            nr *= (x + 1);
            x = 1;
        }
    }
    return nr;
}

int main()
{
    int n, i;
    long long x, v[10002] = {}, deficient = 0, abundent = 0, perfect = 0;
    fin >> n;
    for (i = 1; i <= n; ++i)
    {
        fin >> x;
        v[i] = x;
    }
    ciur();
    for (i = 1; i <= n; ++i)
    {
        if (Sum_Div(v[i]) - v[i] < v[i])
            deficient++;
        else if (Sum_Div(v[i]) - v[i] == v[i])
            perfect++;
        else
            abundent++;
    }
    fout << deficient << " " << perfect << " " << abundent;
}