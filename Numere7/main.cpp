#include <bits/stdc++.h>
using namespace std;
ifstream fin("numere7.in");
ofstream fout("numere7.out");
int main() {
    int n , m;
    fin >> n >> m;
    int v[30];
    int cnt=0;
    int p = 0;
    if(n==0)
        cnt++;
    if(m==0)
        cnt++;
    while(n) {
        if(n%10==0)
            cnt++;
        else
            v[p]=n%10 , p++; n/=10;
    }
    while(m) {
        if(m%10==0)
            cnt++;
        else
            v[p]=m%10 , p++;
        m/=10;
    }
    if(p==0)
        fout << 0;
    sort(v , v+p);
    for(int i = 0 ; i < p ; ++i) {
        fout << v[i];
        if(i==0) {
            for(int j = 0 ; j < cnt ; ++j)
                fout << 0;
        }
    }
    return 0;
}
