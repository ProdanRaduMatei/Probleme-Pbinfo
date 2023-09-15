#include <bits/stdc++.h>
using namespace std;
ifstream fin("sumperm.in");
ofstream fout("sumperm.out");
int main() {
    long long n , a[1001] , s = 0;
    fin >> n;
    for(int i = 1 ; i <= n ; i++)
        fin >> a[i];
    for(int j = 1 ; j <= n ; j++) {
        int aux = a[1] , nr = 0;
        for(int i = 1 ; i < n ; i++)
            a[i] = a[i+1];
        a[n] = aux;
        for(int i = 1 ;i <= n ; i++)
            nr = nr*10+a[i];
        s+=nr;
    }
    fout << s;
return 0;
}
