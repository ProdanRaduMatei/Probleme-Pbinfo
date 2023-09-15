#include <bits/stdc++.h>

using namespace std;

ifstream fin("forus.in");
ofstream fout("forus.out");

int n, cer, x, p, cnt, y;
int  put, nrmax, val, nrc;

int nrdiv(int n) {
    int d=2, prod = 1;
    while(n > 1) {
        int p = 0;
        while(n % d == 0)
            n /= d, p++;
        if(p)
            prod *= (p + 1);
        d++;
        if(d * d > n)
            d = n;
    }
    return prod;
}

int p10(int n) {
    int p = 1;
    for(int i = 1 ; i <= n ; ++i)
        p *= 10;
    return p;
}

int main() {
    fin >> cer >> n;
    if(cer == 1) {
        for(int i = 1 ; i <= n ; i++) {
            fin >> x;
            int zero = 0;
            while(x != 0) {
                if(x % 10 == 0)
                    zero++;
                x /= 10;
            }
            if(zero == 0)
                cnt++;
        }
        fout << cnt;
    } else {
        for(int i = 1 ; i <= n ; i++) {
            fin >> x;
            y = log10(x);
            put = p10(y);
            nrmax = nrdiv(x);
            val = x;
            for(int j = 1 ; j <= y; ++j) {
                x = x % put * 10 + x / put;
                if(x / put != 0) {
                    nrc = nrdiv(x);
                    if(nrc < nrmax)
                        nrmax = nrc, val = x;
                    else if(nrc == nrmax && val > x)
                        val = x;
                }
            }
            fout << val << " ";
        }
    }
    return 0;
}
