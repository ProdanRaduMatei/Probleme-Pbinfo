#include <bits/stdc++.h>
using namespace std;
ifstream fin("suma6.in");
ofstream fout("suma6.out");
int imp(int n) {
    int aux = n, cnt = 0, p = 0;
    while(n != 0) {
        cnt++;
        p = n % 10;
        n /= 10;
    }
    if(cnt % 2 == 1 && p == aux % 10)
        return 1;
    else
        return 0;
}
int nrcif(int n) {
    int cnt = 0;
    while(n != 0) {
        cnt++;
        n /= 10;
    }
    return cnt;
}
int mij(int n) {
    int cnt = nrcif(n), p = 1;
    for(int i = 1 ; i <= cnt/2 ; ++i)
        p *=10;
    int cmij = (n / p) % 10;
    return cmij;
}
int main() {
    int n, x, s = 0;
    fin >> n;
    for(int i = 0 ; i < n; ++i) {
        fin >>x;
        if(imp(x))
            s+=mij(x);
    }
    fout << s;
    return 0;
}
