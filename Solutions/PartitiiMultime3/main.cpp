#include <bits/stdc++.h>
using namespace std;

ifstream fin("partitiimultime3.in");
ofstream fout("partitiimultime3.out");

int n, m, Max[21], mat[21][21], c2, cnt[21];
char rasp[81];
inline void afisare()
{
    if(Max[n]==n/m)
    {
        c2 = -1;
        for(int i = 1; i <= Max[n]; ++i, rasp[++c2] = '*')
            for(int j = 1; j <= cnt[i] && cnt[i]==m; ++j)
                if(mat[i][j] < 10)
                    rasp[++c2] = mat[i][j] + '0';
                else
                    rasp[++c2] = mat[i][j] / 10 + '0', rasp[++c2] = mat[i][j] % 10 + '0';
        rasp[++c2] = '\0';
        if(rasp[0]!='*' && rasp[strlen(rasp)-2]!='*')
            fout << rasp << '\n';
    }
}

inline void back(int const& k)
{
    Max[k] = Max[k - 1];
    for (int i = 1; i <= Max[k - 1] + 1; ++i)
    {
        mat[i][++cnt[i]] = k;
        if (i > Max[k])
            Max[k] = i;
        if(k == n)
            afisare();
        else
            back(k + 1);
        mat[i][--cnt[i]];
    }
}

int main()
{
    fin >> n>>m;
    if(n%m)
    {
        fout<<"IMPOSIBIL";
        return 0;
    }
    back(1);
    return 0;
}