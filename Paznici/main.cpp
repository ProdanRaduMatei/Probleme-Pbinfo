#include <bits/stdc++.h>
using namespace std;
ifstream fin("paznici.in");
ofstream fout("paznici.out");
const int di[] = {0 , 0 , -1 , 1};
const int dj[] = {-1 , 1 , 0 , 0};
struct poz {
    int i , j;
};
int n , m , t , x , y , val , cnt , a[201][201] , b[201][201] , c[201][201];
char ma[202][202];
queue <poz>q;
int inside(int i , int j) {
    return i >= 1 && i <= n && j >= 1 && j <= m ;
}
void lee(int x , int y , int val) {
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            a[i][j] = b[i][j];
    a[x][y] = 1;
    poz r;
    r.i = x , r.j = y;
    q.push(r);
    while(!q.empty()) {
        poz nou;
        nou = q.front();
        for(int d = 0 ; d < 4 ; d++) {
            int inou = nou.i + di[d];
            int jnou = nou.j + dj[d];
            if(inside(inou , jnou) && a[inou][jnou] == 0 && a[nou.i][nou.j] <= val) {
                a[inou][jnou] = a[nou.i][nou.j] + 1;
                q.push({inou , jnou});
            }
        }
        q.pop();
    }
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            if(c[i][j] == 0)
                c[i][j] = a[i][j];
}
int main() {
    fin >> n >> m >> t;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++) {
            fin >> ma[i][j];
            if(ma[i][j] == '#')
                a[i][j] = -1 , b[i][j] = -1;
        }
    for(int i = 1 ; i <= t ; i++) {
        fin >> x >> y >> val;
        lee(x , y , val);
    }
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= m ; j++)
            if(c[i][j] == 0)
                cnt++;
    fout << cnt; }
