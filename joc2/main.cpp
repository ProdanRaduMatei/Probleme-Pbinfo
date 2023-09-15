#include <bits/stdc++.h>
using namespace std;
ifstream fin("joc2.in");
ofstream fout("joc2.out");
int n , m , a[105][105] , b[105][105];
int main() {
    fin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++) {
            fin >> a[i][j];
            b[i][j] = a[i][j];
        }
    for(int i = n ; i > 0 ; i--)
        for(int j = 1 ; j <= m ; j++)
            a[i][j] += max(a[i][j - 1] , a[i + 1][j]);
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            b[i][j] += max(b[i - 1][j] , b[i][j - 1]);
    if(b[n][m] > a[1][m])
        fout << "1 " << b[n][m];
    else
        if(b[n][m] < a[1][m])
            fout << "2 " << a[1][m];
        else
            fout << "3 " << a[1][m];
    return 0;
}
