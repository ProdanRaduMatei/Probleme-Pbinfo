#include <bits/stdc++.h>

#define ll long long

using namespace std;

ifstream fin("pcp.in");
ofstream fout("pcp.out");

ll N, A, B, aux;
int r, frn[10], frx[10];
set<ll> distinctSquares;

int main()
{
    fin >> N;
    aux = N;
    r = N % 9;
    if (r != 0 && r != 4 && r != 1 && r != 7)
    {
        fout << "nu exista";
        return 0;
    }
    while (aux)
    {
        frn[aux % 10]++;
        aux /= 10;
    }
    for (int i = 1; i < 10; ++i)
        if (frn[i])
            for (int j = 1; j <= frn[i]; ++j)
                A = A * 10 + i;
    for (int i = 9; i >= 0; --i)
        if (frn[i])
            for (int j = 1; j <= frn[i]; ++j)
                B = B * 10 + i;
    int As = (int)sqrt(A);
    int Bs = (int)sqrt(B);
    if (r == 0)
    {
        int x = As;
        while (x % 3 && x <= Bs)
            x++;
        while (x <= Bs)
        {
            ll xn = 1LL * x * x;
            ll xnou = xn;
            if (xn % 9 == 0)
            {
                while (xn)
                {
                    frx[xn % 10]++;
                    xn /= 10;
                }
                int ok = 1;
                for (int i = 1; i < 10; ++i)
                {
                    if (frx[i] != frn[i] && i)
                        ok = 0;
                    frx[i] = 0;
                }
                if (ok)
                    distinctSquares.insert(xnou);
            }
            x += 3;
        }
    }
    if (r == 1)
    {
        int x = As;
        while (x % 9 != 1 && x % 9 != 9 && x <= Bs)
        {
            x++;
            if (x % 9 == 1 || x % 9 == 8)
                break;
        }
        while (x <= Bs)
        {
            if (x % 9 == 1 || x % 9 == 8)
            {
                ll xn = 1LL * x * x;
                ll xnou = xn;
                if (xn % 9 == 1)
                {
                    while (xn)
                    {
                        frx[xn % 10]++;
                        xn /= 10;
                    }
                    int ok = 1;
                    for (int i = 0; i < 10; ++i)
                    {
                        if (frx[i] != frn[i] && i)
                            ok = 0;
                        frx[i] = 0;
                    }
                    if (ok == 1)
                        distinctSquares.insert(xnou);
                }
            }
            x++;
        }
    }
    else if (r == 4)
    {
        int x = As;
        while ((x % 9 != 2 && x % 9 != 7) && x <= Bs)
            x++;
        while (x <= Bs)
        {
            if (x % 9 == 2 || x % 9 == 7)
            {
                ll xn = 1LL * x * x;
                ll xnou = xn;
                if (xn % 9 == 4)
                {
                    while (xn)
                    {
                        frx[xn % 10]++;
                        xn /= 10;
                    }
                    int ok = 1;
                    for (int i = 0; i < 10; ++i)
                    {
                        if (frx[i] != frn[i] && i)
                            ok = 0;
                        frx[i] = 0;
                    }
                    if (ok)
                        distinctSquares.insert(xnou);
                }
            }
            x++;
        }
    }
    else if (r==7)
    {
        int x = As;
        while (x <= Bs)
        {
            if (x % 9 == 4 || x % 9 == 5)
            {
                ll xn = 1LL * x * x;
                ll xnou = xn;
                if (xn % 9 == 7)
                {
                    while (xn)
                    {
                        frx[xn % 10]++;
                        xn /= 10;
                    }
                    int ok = 1;
                    for (int i = 0; i < 10; ++i)
                    {
                        if (frx[i] != frn[i] && i)
                            ok = 0;
                        frx[i] = 0;
                    }
                    if (ok)
                        distinctSquares.insert(xnou);
                }
            }
            x++;
        }
    }
    if (distinctSquares.size())
    {
        fout << distinctSquares.size() << '\n';
        for (ll square : distinctSquares)
            fout << square << '\n';
    }
    else
        fout << "nu exista";
    return 0;
}