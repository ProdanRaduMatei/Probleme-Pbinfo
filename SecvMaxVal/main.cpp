#include <bits/stdc++.h>
using namespace std;

ifstream fin("secvmaxval.in");
ofstream fout("secvmaxval.out");

long long int a[200001], is = 1, lmax, s;

int main() {
    long long int n, k;
    fin >> n >> k;
    for(int i = 1 ; i <= n; ++i)
        fin >> a[i];
    for(int i = 1 ; i <= n; ++i) {
        s += a[i];
        if(s > k) {
            if(i - is + 1 > lmax)
                lmax = i - is + 1;
            s-=a[is];
            is++;
        }
    }
    if(n - is + 1 > lmax)
        lmax = n - is + 1;
    if(n - is + 1 == lmax)
        lmax++;
    fout << lmax - 1;
    return 0;
}
