#include <bits/stdc++.h>
using namespace std;
ifstream fin("hercule.in");
ofstream fout("hercule.out");
int n , m , a[11][11] , cnt , b[11][11];
const int di[] = {0 , 0 , 1 , -1};
const int dj[] = {1 , -1 , 0 , 0};
int inside(int i , int j) {
    return i >= 1 && i <= n && j >= 1 && j <= m;
}
void back(int i , int j , int pas) {
    for(int d = 0 ; d < 4 ; d++) {
        int inou = i + di[d];
        int jnou = j + dj[d];
        if(inside(inou , jnou) && b[inou][jnou] == 0 && a[inou][jnou] >= pas) {
            b[inou][jnou] = pas;
            if(inou == n && jnou == m)
                cnt++;
            else
                back(inou , jnou , pas + 1);
            b[inou][jnou] = 0;
        }
    }
}
int main() {
    fin >> n >> m;
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= m ; ++j)
            fin >> a[i][j];
    b[1][1] = 1;
    back(1 , 1 , 2);
    fout << cnt;
    return 0;
}
