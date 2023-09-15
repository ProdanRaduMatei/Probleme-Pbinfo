#include <bits/stdc++.h>
using namespace std;
ifstream fin("cerc3.in");
ofstream fout("cerc3.out");
struct elem {
    int i , j;
}v[501];
int comp(elem a , elem b) {
    return a.j < b.j || a.j == b.j && a.i < b.i;
}
int main() {
    int n , cnt = 0 , a , b , inceput = -200;
    fin >> n;
    for(int i = 1 ; i <= n ; i++) {
        fin >> a >> b;
        v[i].i = a - b; v[i].j = a + b;
    }
    sort(v + 1 , v + n + 1 , comp);
    for(int i = 1 ; i <= n ; i++)
        if(v[i].i > inceput) {
            inceput = v[i].j; cnt++;
    }
    fout << cnt;
    return 0;
}
