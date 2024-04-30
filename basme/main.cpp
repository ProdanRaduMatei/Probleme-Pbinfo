#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("basme.in");
ofstream fout("basme.out");

int n, V[200001], F[20000001], E[4001], nrp = 0, P[1000];

int f(int a)
{
    int rez = 0, ind = 1;
    while (a > 1)
        if (P[ind] * P[ind] > a)
        {
            rez = rez ^ a;
            a = 1;
        }
        else
        {
            if (a % P[ind] == 0)
            {
                rez = rez ^ P[ind];
                while (a % P[ind] == 0)
                    a /= P[ind];
            }
            else
                ind++;
        }
    return rez;
}

int main()
{
    for (int i = 1; i <= 4000; ++i)
        E[i] = 1;
    for (int i = 2; i <= 4000; ++i)
        if (E[i] == 1)
            for (int j = i + i; j <= 4000; j += i)
                E[j] = 0;
    for (int i = 2; i <= 4000; ++i)
        if (E[i] == 1)
        {
            ++nrp;
            P[nrp] = i;
        }
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int a;
        fin >> a;
        V[i] = f(a);
    }
    int s = 0;
    F[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        s = s ^ V[i];
        F[s]++;
    }
    long long rez = 0;
    for (int i = 0; i <= 20000000; ++i)
        rez += (long long)F[i] * (F[i] - 1) / 2;
    fout << rez;
    return 0;
}