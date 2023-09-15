#include <fstream>
#include <iostream>

int n, m, xi, yi, H[25][25], i, j, kmax, A[25][25];
int dl[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

using namespace std;

bool sol(int x, int y)
{
    if(x == 1 || x == n || y == 1 || y == m)
        return 1;
    return 0;
}

void backplan(int x, int y, int k)
{
    int i, j, xx, yy;
    if(sol(x, y))
    {
        kmax = max(kmax, k - 1);
        return;
    }
    else
        for(i = 0; i < 4; ++i)
        {
            xx = x + dl[i];
            yy = y + dc[i];
            if(!A[xx][yy] && H[xx][yy] < H[x][y])
            {
                A[xx][yy] = k;
                backplan(xx, yy, k + 1);
                A[xx][yy] = 0;
            }
        }
}
int main()
{

    ifstream fin("bila.in");
    ofstream fout("bila.out");
    fin >> n >> m;
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= m; ++j)
            fin >> H[i][j];
    fin >> xi >> yi;
    for(i = 0; i <= n + 1; ++i)
        A[i][0] = A[i][m + 1] = -1;
    for(i = 0; i <= m + 1; ++i)
        A[0][i] = A[n + 1][i] = -1;
    A[xi][yi] = 1;
    backplan(xi, yi, 2);
    fout << kmax;
    return 0;
}
