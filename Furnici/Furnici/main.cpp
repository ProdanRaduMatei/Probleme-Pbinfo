#include <bits/stdc++.h>
using namespace std;
ifstream fin("furnici.in");
ofstream fout("furnici.out");
int a[101001];
int nrdivizori(int n) {
    int d = 2 , produs = 1;
    while (n > 1) {
        int p = 0;
        while (n % d == 0) {
            p++;
            n /= d;
        }
        if (p)
            produs *= (p + 1);
        d++;
        if (d * d > n)
            d = n;
    }
    return produs;
}
int main() {
    int n , x , l = 0 , lmax = 0;
    fin >> n;
    for (int i = 1 ; i <= n ; ++i) {
        fin >> x;
        a[i] = nrdivizori(x);
    }
    for (int i = 1 ; i <= n ;++i) {
        if (a[i] < a[i - 1])
            l++;
        else if (a[i] >= a[i - 1]) {
            if (l)
                lmax++;
            l = 0;
        }
    }
    if (l)
        fout << lmax + 1;
    else
        fout << lmax;
    return 0;
}
