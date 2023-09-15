#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("paritar.in");
ofstream fout("paritar.out");

int main()
{
    int n, x, p1 = 0, p2 = 0, i1 = 0, i2 = 0, maxp1 = 0, maxp2 = 0, maxi1 = 0, maxi2 = 0, mini1 = 1000000, mini2 = 1000000, minp1 = 1000000, minp2 = 1000000, paritar = 0;
    bool ok;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> x;
        if (x % 2) {
            if (i1 == 0) {
                maxi1 = x;
                i1 = 1;
            }
            else if (x > maxi1)
                maxi1 = x;
        }
        else {
            if (p1 == 0) {
                maxp1 = x;
                p1 = 1;
            }
            else if (x > maxp1)
                maxp1 = x;
        }
    }
    for (int i = 1; i <= n; ++i) {
        fin >> x;
        if (x % 2) {
            if (i2 == 0) {
                mini2 = x;
                i2 = 1;
            }
            else if (x < mini2)
                mini2 = x;
        }
        else {
            if (p2 == 0) {
                minp2 = x;
                p2 = 1;
            }
            else if (x < minp2)
                minp2 = x;
        }
    }
    if (p1 * i1) {
        if (p2 * i2)
            paritar = 1;
        else {
            if (p2) {
                if (maxi1 < minp2)
                    paritar = 1;
            }
            else {
                if (maxp1 < mini2)
                    paritar = 1;
            }
        }
    }
    else {
        if (p1) {
            if (p2)
                paritar = 1;
            else {
                if (maxp1 < mini2)
                    paritar = 1;
            }
        }
        else {
            if (i2)
                paritar = 1;
            else {
                if (maxi1 < maxp2)
                    paritar = 1;
            }
        }
    }
    if (paritar)
        fout << "DA";
    else
        fout << "NU";
    return 0;
}
