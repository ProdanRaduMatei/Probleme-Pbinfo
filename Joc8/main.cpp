#include <bits/stdc++.h>
using namespace std;
ifstream fin("joc8.in");
ofstream fout("joc8.out");
int special(int n) {
    int v[100];
    bool perf=true;
    int p = 0;
    while(n) {
        v[p]=n%10;
        p++;
        n/=10;
    }
    if(p%2==1) {
        p--;
        for(int i = 1 ; i < p ; ++i) {
            if((v[i]<v[i-1] && v[i+1] > v[i])||(v[i]>v[i-1] && v[i+1]<v[i])) {

            } else
                perf=false;
        }
    } else
        perf=false;
    if(perf)
        return 1;
    else
        return 0;
}

int main() {
    int n;
    fin >> n;
    int cnt=0;
    int x;
    for(int i = 0 ; i < n ; ++i) {
        fin >> x;
        if(special(x))
            cnt++;
    }
    fout << cnt;
    return 0;
}
