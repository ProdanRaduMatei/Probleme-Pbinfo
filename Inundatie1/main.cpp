#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("inundatie.in");
ofstream fout("inundatie.out");

int a[100001], minn = 20001, maxx, n, s, p, cer;

int cer2 (int p1) {
    int h = a[p1];
    int hfinal = 0;
    for (int i = p1; i >= 1; --i) {
        if (a[i] >= h)
            h = a[i];
        else
            hfinal = hfinal + (h - a[i]);
    }
    return hfinal;
}

int main() {
    fin >> cer;
    fin >> n >> p >> s;
    int x;
    for (int i = 1; i <= n; ++i) {
        fin >> x;
        a[i] = x;
        if (a[i] < minn)
            minn = a[i];
        if (a[i] > maxx)
            maxx = a[i];
    }
    if (cer == 1)
        fout << maxx - minn;
    if (cer == 2)
        fout << cer2(p);
    if (cer == 3) {
        int st = 1, dr = n, timp = 0;
        bool da = 0;
        while (st < dr && !da) {
            int mid = (st + dr) / 2;
            timp = cer2(mid);
            if (timp < s)
                st = mid + 1;
            else {
                if (timp > s)
                    dr = mid - 1;
                else {
                    da = 1;
                    fout << dr;
                }
            }
        }
        if (!da) {
            while (cer2(dr) <= s)
                dr++;
            fout << dr - 1;
        }
    }
    if (cer == 4) {
        int i = p, h = a[i], p1 = 0, pinitial = p, d = 0;
        while (a[i] <= h && i >= 1)
            i--;
        if (a[i] >= h) {
            p = i;
            h = a[i];
        }
        i = p - 1;
        d = 0;
        bool da = 0;
        while (i >= 1) {
            int hant;
            da = 0;
            if (a[i] == h) {
                    int iaux = i;
                    while (a[iaux] <= h && iaux)
                        iaux--;
                    if (i - iaux + 1 >= d && iaux && a[p] != a[p + 1] && a[p] != a[p - 1]) {
                    d = iaux - i + 1;
                    p1 = iaux;
                    da = 1;
                    i = iaux;
                    }
            }
            if (a[i] >= h && !da) {
                if (p - i + 1 >= d && a[p] != a[p + 1] && a[p] != a[p - 1]) {
                    d = p - i + 1;
                    p1 = p;
                }
                h = a[i];
                p = i;                
            }
            --i;
        }
        if (p - i >= d && a[p] != a[p1]) {
            d = p - i;
            p1 = p;
        }
        if (!p1)
            fout << p;
        else
            fout << p1;
    }
}