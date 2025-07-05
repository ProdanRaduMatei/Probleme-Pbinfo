#include <bits/stdc++.h>
using namespace std;
ifstream fin("labir.in");
ofstream fout("labir.out");
const int di[] = {0 , 0 , -1 , 1};
const int dj[] = {-1 , 1 , 0 , 0};
int n , m , k , ip , jp , is , js , x , y;
int X[5002] , Y[5002] , C1[5002] , C2[5002];
unsigned short b[5001][5001];
bitset <5002>a[5002];
struct poz { int i , j; };
poz v[50002];
bool inside(int i , int j) {
    return i >= 1 && i <= n && j >= 1 && j <= m;
}
int comprimare(int i , int j) {
}
deque <poz> D;
int lee(poz str) {
    poz p;
    p.i = str.i , p.j = str.j;
    D.push_back(p);
    b[ip][jp] = 1;
    while(! D.empty()) {
        p = D.front();
        D.pop_front();
        for(int i = 0 ; i < 4 ; i ++) {
            int inou = p.i + di[i];
            int jnou = p.j + dj[i];
            if(inside(inou , jnou) && b[inou][jnou] == 0) {
                if(a[inou][jnou] == 1) {
                    b[inou][jnou] = b[p.i][p.j] + 1;
                    D.push_back({inou , jnou});
                }
                else {
                    b[inou][jnou] = b[p.i][p.j];
                    D.push_front({inou , jnou});
                }
            }
        }
    }
    return b[is][js] - 1;
}
int main() {
    fin >> n >> m;
    fin >> ip >> jp >> is >> js;
    fin >> k;
    for(int i = 1 ; i <= k ; i++) {
        fin >> x >> y;
        X[x] = 1;
        Y[y] = 1;
        v[i] = {x , y};
    }
    for(int i = 1 ; i <= n ; i++) {
        if(X[i] == 0 && (X[i-1] == 0 || X[i-1] == -1) && i != ip && i != is) {
            X[i] = -1;
            C1[i] = 1;
        }
    }
    for(int i = 1 ; i <= m ; i++) {
        if(Y[i] == 0 && (Y[i-1] == 0 || Y[i-1] == -1) && i != jp && i != js) {
            Y[i] = -1;
            C2[i] = 1;
        }
    }
    for(int i = 1 ; i <= n ; i++)
        C1[i] = C1[i] + C1[i-1];
    for(int i = 1 ; i <= m ; i++)
        C2[i] = C2[i] + C2[i-1];
    n -= C1[n];
    m -= C2[m];
    ip -= C1[ip];
    is -= C1[is];
    jp -= C2[jp];
    js -= C2[js];
    for(int i = 1 ; i <= k ; i++) {
        a[v[i].i - C1[v[i].i]][v[i].j - C2[v[i].j]] = 1;
    }
    poz str;
    str.i = ip , str.j = jp;
    fout << lee(str);
    }
