#include <bits/stdc++.h>

using namespace std;

ifstream fin("roy-floyd.in");
ofstream fout("roy-floyd.out");

const int Inf = 0x3f3f3f3f;
int n , m , x , y , w , c[101][101];

void Floyd_Warshall()
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (i != j && c[i][j] > c[i][k] + c[k][j])
                    c[i][j] = c[i][k] + c[k][j];
}

int main()
{
    fin >> n >> m;

    for (int i = 1 ; i <= n ; ++i)
        for (int j = 1 ; j <= n ; ++j)
            if (i != j) c[i][j] = Inf;

    for(int i = 1 ; i <= m ; i++)
    {
        fin >> x >> y >> w;
        c[x][y] = w;
    }

    Floyd_Warshall();

    for (int i = 1 ; i <= n ; ++i)
    {
       for (int j = 1 ; j <= n ; ++j)
            if(c[i][j] != Inf)
                fout << c[i][j] << ' ';
            else
            fout << "-1 ";
        fout << '\n';
    }
}
