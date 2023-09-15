#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sao1.in");
ofstream fout("sao1.out");

int n, m, v[502][502];
long long fm, f;
int dl[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0 ,-1};

void bt(int x, int y, int fer) {
    int xx, yy;
    f = f + v[x][y];
    v[x][y] = 0;
    for (int i = 0; i < 4; ++i) {
        xx = x + dl[i];
        yy = y + dc[i];
        if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && v[xx][yy] == fer)
            bt(xx, yy, fer);
    }
}

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> v[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (v[i][j]) {
                f = 0;
                bt(i, j, v[i][j]);
                if (f > fm)
                    fm = f;
            }
    fout << fm;
    return 0;
}
