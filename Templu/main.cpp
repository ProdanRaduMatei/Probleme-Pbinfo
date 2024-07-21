#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

ifstream fin("templu.in");
ofstream fout("templu.out");

int v[1001];
string v2[1001];
char cif[10];

int cmp(string x, string y)
{
    if (x < y)
        return 1;
    else
        return 0;
}

int main()
{
    for (int i = 0; i <= 9; ++i)
        cif[i] = '0' + i;
    int n, k, sfinal = 0;
    fin >> k >> n;
    for (int i = 1; i <= n; ++i)
        v[i] = k - 1;
    int poz = 1, poz1 = n;
    for (int i = 1; i <= n; ++i)
    {
        int s = 0;
        for (int j = 1; j <= n; ++j)
            if (poz <= poz1)
            {
                if (j >= poz && j <= poz1)
                    ++v[j];
            }
            else
            {
                if (j < poz && j > poz1)
                    --v[j];
            }
        ++poz;
        --poz1;
        for (int j = 1; j <= n; ++j)
            s = s + v[j];
        sfinal += s;
        int pal = 0, cnt1 = 0;
        while (s > 0)
        {
            ++cnt1;
            pal = pal * 10 + s % 10;
            s /= 10;
        }
        while (cnt1 > 0)
        {
            v2[i] = v2[i] + cif[pal % 10];
            pal /= 10;
            --cnt1;
        }
    }
    int pal = 0, cnt1 = 0;
    while (sfinal > 0)
    {
        ++cnt1;
        pal = pal * 10 + sfinal % 10;
        sfinal /= 10;
    }
    while (cnt1 > 0)
    {
        v2[n + 1] = v2[n + 1] + cif[pal % 10];
        pal /= 10;
        --cnt1;
    }
    sort(v2 + 1, v2 + n + 2, cmp);
    string s;
    for (int i = 1; i <= n + 1; ++i)
    {
        s = s + v2[i];
        fout << v2[i];
    }
    for (unsigned int i = 0; i < s.size(); ++i)
        v[i] = s[i] - '0';
    int maxim = 0;
    for (unsigned int i = 0; i < s.size() - 1; ++i)
        if (v[i] * 10 + v[i + 1] > maxim)
            maxim = v[i] * 10 + v[i + 1];
    fout << endl;
    fout << maxim;
    return 0;
}