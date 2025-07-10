#include <bits/stdc++.h>
using namespace std;
ifstream fin("acces1.in");
ofstream fout("acces1.out");
const int di[]={-1 , 0 , 1 , 0};
const int dj[]={0 , 1 , 0 , -1};
int n , m ;
int a[1002][1002], numar;
bool prt[1001][1001];
struct poz{
    int i , j;
};
poz q[1000000];
bool inside(int i , int j){
    return i>=1 && i<=n && j>=1 && j<=m;
}
void lee(int dr) {
    int st=1;
    while(st<=dr) {
        int i = q[st].i;
        int j = q[st].j;
        //if (i == n)break;
        for(int d = 0 ; d < 4 ; d++) {
            int inou=i+di[d];
            int jnou=j+dj[d];
            if(inside(inou,jnou) && a[inou][jnou]==0 ) {
                q[++dr].i=inou;
                q[dr].j=jnou;
                a[inou][jnou]=a[i][j]+1;
            }
        }
        st++;
    }
    //return a[q[st].i][q[st].j];
}
int main() {
    char ch;
    int dr = 0;
    fin >> n >> m;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) {
            fin >> ch;
            if (ch == 'P') {
                poz start;
                start.i = i;
                start.j = j;
                a[i][j] = 1;
                q[++ dr] = start;
                prt[i][j] = 1;
            }
            else if (ch == '#')
                a[i][j] = -1;
            //else if (ch == '-')a[i][j] = 1;
        }
    lee(dr);
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j)
            if (a[i][j] == -1)
                fout << "# ";
            else if (a[i][j] == 0 && prt[i][j] == 0)
                fout << "- ";
            else
                fout << a[i][j] - 1 << ' ';
        fout << '\n';
    }
    return 0;
}
