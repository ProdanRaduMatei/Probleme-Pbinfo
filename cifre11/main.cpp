#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
ofstream fout("cifre11.out");
ifstream fin("cifre11.in");
struct cifra {
    int nr,s,nrc;
};
cifra S[10001];
int comp(cifra a , cifra b){
    return a.s < b.s || (a.s == b.s && a.nr > b.nr);
}
int cmp(cifra a , cifra b){
    return a.nrc > b.nrc || (a.nrc == b.nrc && a.nr < b.nr);
}
int n , f[10001] , q[10001];
int main() {
    fin >> n;
    for(int i = 1 ; i <= n ; i++) {
        fin >> S[i].nr;
        int g[10001] = {0};
        int aux = S[i].nr , s1 = 0 , ct = 0;
        while(aux)
            s1 += aux % 10 , f[aux%10]++ , g[aux%10]++ , aux /= 10;
        int maxim = -1;
        for(int j = 0 ; j <= 10 ; j++) {
            if(g[j] > 0)
                ct++ , q[j]++;
            else {
                if(ct > maxim)
                    maxim = ct;
                ct = 0;
            }
        }
        S[i].nrc = maxim;
        S[i].s = s1;
    }
    sort(S + 1, S + n + 1 , comp);
    fout << S[1].nr << endl;
    sort(S + 1, S + n + 1, cmp);
    fout << S[1].nr << endl;
    int maxi = -1;
    for(int i = 0 ; i <= 9 ; i++)
        if(q[i] > maxi)
        maxi = q[i];
    for(int i = 0 ; i <= 9 ; i++)
        if(q[i] == maxi)
        fout << i << " ";
}
