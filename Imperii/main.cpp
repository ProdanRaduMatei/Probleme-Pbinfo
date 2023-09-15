#include <bits/stdc++.h>
using namespace std;
ifstream fin("imperii.in");
ofstream fout("imperii.out");
#define Inf 100000001
#define Max 1001
struct poz {
    int i , j;
};
const int di[] = {-1 , 1 , 0 , 0};
const int dj[] = {0 , 0 , -1 , 1};
queue< pair<int, poz> > Q;
int n , m;
int d1[Max][Max], d2[Max][Max], d3[Max][Max], d4[Max][Max];
bool a[Max][Max];
int inside(int i , int j) {
    return i >= 1 && i <= n && j >= 1 && j <=m;
}
void Lee(int i , int j, int d[][Max]) {
    poz x;
    x.i = i;
    x.j = j;
    Q.push(make_pair(0, x));
    while(!Q.empty()) {
        x = Q.front().second;
        if (Q.front().first < d[x.i][x.j])
            continue;
        for(int i = 0 ; i < 4 ; i++) {
            int inou = x.i + di[i];
            int jnou = x.j + dj[i];
            if(inside(inou , jnou) && (d[inou][jnou] > d[x.i][x.j] + 1 || d[inou][jnou] == 0) && a[inou][jnou] != 1) {
                poz y;
                y.i = inou;
                y.j = jnou;
                d[inou][jnou] = d[x.i][x.j] + 1;
                Q.push(make_pair(d[inou][jnou], y));
            }
        }
        Q.pop();
    }
    d[i][j] = 0;
}
int main() {
    char c, c1, c2, c3, c4;
    fin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            fin >> c;
            if (c == '#')
                a[i][j] = 1;
            if (i == 1 && j == 1)
                c1 = c;
            if (i == 1 && j == m)
                c2 = c;
            if (i == n && j == 1)
                c3 = c;
            if (i == n && j == m)
                c4 = c;
        }
    Lee(1, 1, d1);
    Lee(1, m, d2);
    Lee(n, 1, d3);
    Lee(n, m, d4);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (a[i][j])
                fout <<'#';
            else if (d1[i][j] < d2[i][j] && d1[i][j] < d3[i][j] && d1[i][j] < d4[i][j])
                fout << c1;
            else if (d2[i][j] < d1[i][j] && d2[i][j] < d3[i][j] && d2[i][j] < d4[i][j])
                fout << c2;
            else if (d3[i][j] < d2[i][j] && d3[i][j] < d1[i][j] && d3[i][j] < d4[i][j])
                fout << c3;
            else if (d4[i][j] < d2[i][j] && d4[i][j] < d1[i][j] && d4[i][j] < d3[i][j])
                fout << c4;
            else
                fout << '-';
        }
    fout << '\n';
    }
}
