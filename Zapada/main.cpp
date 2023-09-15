#include <bits/stdc++.h>
using namespace std;
ifstream cin("zapada.in");
ofstream cout("zapada.out");
int n , m , T[101] , t , cnt , x , y , c , k;
struct poz {
    int i , j , c;
    }E[1001];
poz A[101];
void leaga(int a , int b) {
    T[a] = T[b];
}
int radacina(int a) {
    if(a == T[a])
        return a;
    else
        return T[a] = radacina(T[a]);
}
void kruskal() {
    int r1 , r2;
    for(int i = 1 ; i <= m ; i++) {
        r1 = radacina(E[i].i);
        r2 = radacina(E[i].j);
        if(r1 != r2) {
            t += E[i].c;
            A[++cnt] = E[i];
            leaga(r1 , r2);
        }
    }
}
int comp(poz a , poz b) {
    if(a.c < b.c)
        return 1;
    else if(a.c == b.c && a.i < b.i)
        return 1;
    else if(a.c == b.c && a.i == b.i && a.j < b.j)
        return 1;
    else
        return 0;
}
int main() {
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        T[i] = i;
    for(int i = 1 ; i <= m ; i++) {
        cin >> x >> y >> c;
        E[i].i = x;
        E[i].j = y;
        E[i].c = c;
        }
    cin >> k;
    for(int i = 1 ; i <= k ; i++) {
        cin >> x;
        A[++cnt] = E[x];
        t += E[x].c;
        int r1 = radacina(E[x].i);
        int r2 = radacina(E[x].j);
        leaga(r1 , r2);
    }
    sort(E + 1 , E + m + 1 , comp);
    kruskal();
    cout << t << '\n';
}
