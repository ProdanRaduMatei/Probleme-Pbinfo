#include <bits/stdc++.h>
using namespace std;
ifstream fin("acces.in");
ofstream fout("acces.out");
const int di[]={-1 , 0 , 1 , 0};
const int dj[]={0 , 1, 0 , -1};
int n , m , a[1002][1002] , x[1000001] , y[1000001];
int ip , jp , is=1 , js=1;
char v[1002][1002];
bool inside(int i , int j) {
    return i>=1 && i<=n && j>=1 && j<=m;
}
int main() {
    fin >> n >> m;
    for(int i = 1 ; i <= n ; ++i) {
        for(int j = 1 ; j <= m ; ++j) {
            fin >> v[i][j];
            if(v[i][j]=='-')
                a[i][j]=0;
            else if(v[i][j]=='P') {
                ip=i;
                jp=j;
                a[i][j]=0;
            }
            else
                a[i][j]=1;
        }
    }
    int st=1 , dr=1;
    a[ip][jp]=1;
    x[1]=ip;
    y[1]=jp;
    while(st <= dr ) {
        int i = x[st] , j = y[st];
        for(int k = 0 ; k < 4 ; k++) {
            int ii=i+di[k];
            int jj=j+dj[k];
            if(inside(ii , jj) && a[ii][jj]==0) {
                dr++;
                x[dr]=ii , y[dr]=jj , a[ii][jj]=a[i][j]+1;
            }
        }
        st++;
    }
    for(int i = 1 ; i <= n ; ++i) {
        for(int j = 1 ; j <= m ; ++j) {
            if(a[i][j]==1 && (i!=ip || j!=jp))
                fout << -1 << ' ';
            else
                fout << a[i][j]-1 << ' ';
        }
        fout << endl;
    }
    return 0;
}
