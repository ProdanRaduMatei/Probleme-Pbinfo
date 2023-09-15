#include <bits/stdc++.h>
using namespace std;
ifstream fin("pixy.in");
ofstream fout("pixy.out");
const int di[] = {0 , 0 , -1 , 1};
const int dj[] = {-1 , 1 , 0 , 0};
int n , m , a[501][501] , b[501][501] , c[501][501];
char s;
struct poz {
    int i , j;
};
queue <poz> q;
int inside(int i , int j) {
    return i >= 1 && i <= n && j >= 1 && j <= m;
}
void lee() {
    poz r;
    r.i = 1 , r.j = 1;
    q.push(r);
    b[r.i][r.j] = 1;
    c[r.i][r.j] = 1;
    while(!q.empty()) {
        poz r;
        r = q.front();
        for(int i = 0 ; i < 4 ; i++) {
            int inou = r.i + di[i];
            int jnou = r.j + dj[i];
            if(inside(inou , jnou)) {
                if(a[inou][jnou] == a[r.i][r.j]) {
                    if(b[inou][jnou] == 0) {
                        c[inou][jnou] = c[r.i][r.j];
                        b[inou][jnou] = b[r.i][r.j] + 1;
                        q.push({inou , jnou});
                    }
                    else if(c[inou][jnou] > c[r.i][r.j]) {
                        c[inou][jnou] = c[r.i][r.j];
                        b[inou][jnou] = b[r.i][r.j] + 1;
                        q.push({inou , jnou});
                    }
                    else if(c[inou][jnou] == c[r.i][r.j] && b[inou][jnou] > b[r.i][r.j] + 1) {
                        b[inou][jnou] = b[r.i][r.j] + 1;
                        q.push({inou , jnou});
                    }
                }
                else if(c[inou][jnou] > c[r.i][r.j]+1) {
                    c[inou][jnou] = c[r.i][r.j] + 1;
                    b[inou][jnou] = b[r.i][r.j] + 1;
                    q.push({inou , jnou});
                }
                else if(c[inou][jnou] == c[r.i][r.j]+1 && b[inou][jnou] > b[r.i][r.j] + 1) {
                    b[inou][jnou] = b[r.i][r.j] + 1;
                    q.push({inou , jnou});
                }
            }
        }
        q.pop();
    }
}
int verif(int cod , int x) {
    return (cod &(1<<x))!=0);
}
int nr1(int n) {
    int c = 0;
    while (n != 0) {
        c += n % 2;
        n /= 2;
    }
    return c;
}
int main() {
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++) {
            fin >> s;
            a[i][j] = s - 'A';
            c[i][j] = 1000000000;
        }
    lee();
    /*for(int i = 1 ; i <= n ; i++) { for(int j = 1 ; j <= m ; j++) cout << b[i][j] << " "; cout << '\n'; } cout << '\n'; for(int i = 1 ; i <= n ; i++) { for(int j = 1 ; j <= m ; j++) cout << c[i][j] << " "; cout << '\n'; }*/
    fout << c[n][m] - 1 << '\n' << b[n][m] - 1;
}
