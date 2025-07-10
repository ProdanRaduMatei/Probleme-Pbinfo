#include <bits/stdc++.h>
using namespace std;
ifstream fin("palat.in");
ofstream fout("palat.out");
#define Inf 100000001
#define Max 1006
struct poz {
    int i , j;
};
const int di[] = {-1 , 1 , 0 , 0};
const int dj[] = {0 , 0 , -1 , 1};
int n , m , d[Max][Max];
bool a[Max][Max];
queue < pair<int, poz> >Q;
vector< pair<int, int> > fat;
poz ileana;
int inside(int i , int j) {
    return i >= 1 && i <= n && j >= 1 && j <=m;
}
void lee(int i , int j) {
    poz x;
    x.i = i;
    x.j = j;
    a[i][j] = 1;
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
}
int main() {
    char c;
    fin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++) {
            fin >> c;
            if (c == '_')
                a[i][j] = 0;
            else if (c == 'Z')
                a[i][j] = 1;
            else if (c == 'F')
                fat.push_back(make_pair(i, j));
            else
                ileana.i = i, ileana.j = j;
        }
    lee(ileana.i , ileana.j);
    int mindist = Inf;
    poz rez;
    sort(fat.begin(), fat.end());
    for (int i = fat.size() - 1; i >= 0; -- i)
        if (d[fat[i].first][fat[i].second] < mindist && d[fat[i].first][fat[i].second] != 0) {
            mindist = d[fat[i].first][fat[i].second];
            rez.i = fat[i].first;
            rez.j = fat[i].second;
        }
    fout << rez.i << ' ' << rez.j;
}
