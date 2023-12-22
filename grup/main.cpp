#include <algorithm>
#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

int a[50000], f[10], p[50000];

static int first_digit(int n) {
    while (n > 9)
        n /= 10;
    return n;
}

int main() {
    int n, c, pmax = 0, ind = 0, minim = INT_MAX, i, j;
    ifstream fin("grup.in");
    ofstream fout("grup.out");
    fin >> n >> c;
    if (c == 1) {
        for (i = 0; i < n; i++) {
            fin >> a[i];
            f[first_digit(a[i])]++;
        }
        for (i = 0; i <= 9; i++)
            if (f[i] > pmax)
                pmax = f[i], ind = i;
        for (i = 0; i < n; i++)
            if (first_digit(a[i]) == ind && a[i] <minim)
                minim = a[i];
        fout << minim;
    }
    else {
        int l = 1, lmax = 1;
        for (i = 0; i < n; i++) {
            fin >> a[i];
            int x = a[i], d[10] = {0}, prod = 0;
            while (x != 0) {
                d[x % 10]++;
                x /= 10;
            }
            for (j = 1; j <= 9; j++)
                if (d[j])
                    prod = prod * 10 + j;
            if (d[0])
                prod *= 10;
            p[i] = prod;
        }
        sort(p, p + n);
        for (i = 0; i < n; i++) {
            if (p[i] == p[i + 1]) {
                l++;
                if (l > lmax)
                    lmax = l;
            }
            else
                l = 1;
        }
        fout << lmax;
    }
    return 0;
}