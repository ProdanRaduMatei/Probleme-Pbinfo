#include <bits/stdc++.h>
using namespace std;
ifstream fin("acces2.in");
ofstream fout("acces2.out");
int n , m , a[1001][1001] , cnt , nrp , nrc , sum , pazi , pomp , ind;
char s;
const int di[] = { 0 , 0 , -1 , 1};
const int dj[] = {-1 , 1 , 0 , 0};
struct poz {
    int i , j;
};
int inside(int i , int j) {
    return i >= 1 && i <= n && j >= 1 && j <= m;
}
poz c[1001];
queue <poz> q;
void lee(int i , int j) {
    poz r;
    r.i = i , r.j = j;
    a[r.i][r.j] = ind;
    q.push(r);
    while(!q.empty()) {
        poz r;
        r = q.front();
        for(int i = 0 ; i < 4 ; i++) {
            int inou = r.i + di[i];
            int jnou = r.j + dj[i];
            if(a[inou][jnou] == -2)
                nrp++;
            if(inside(inou , jnou) && (a[inou][jnou] == 0 || a[inou][jnou] == -2)) {
                a[inou][jnou] = ind;
                q.push({inou , jnou});
            }
        }
        q.pop();
    }
}
int main() {
    fin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++) {
            fin >> s;
            if(s == '#')
                a[i][j] = -1;
            else if(s == '_')
                a[i][j] = 0;
            else if(s == 'P')
                a[i][j] = -2;
        }
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            if(a[i][j] == 0) {
                ind++;
                nrp = 0;
                lee(i , j);
                if(nrp > 0)
                    pomp += (nrp - 1);
                else
                    nrc++;
            }
    if(pomp >= nrc)
        sum = pomp - nrc;
    else
        sum += (2 * (nrc - pomp)) + pomp;
    fout << sum;
}
