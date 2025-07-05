#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

bool litera(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return 1;
    else
        return 0;
}

char s[256], w[256], ch;
int n, i, j, lcuv, ok, ind, lmax, poz[200], start;

int main()
{
    cin.getline(s, 256);
    n = strlen(s);
    s[n] = ' ';
    ++n;
    s[n] = 0;
    i = 0;
    while (i < n) {
        if (s[i] != ' ') {
            ++lcuv;
            if (litera(s[i]))
                ok = 1;
        }
        else {
            if (ok) {
                if (lcuv > lmax) {
                    lmax = lcuv;
                    start = i - lmax;
                    ind = 1;
                    poz[ind] = start;
                }
                else {
                    if (lcuv == lmax) {
                        ++ind;
                        poz[ind] = i - lmax;
                    }
                }
            }
            lcuv = 0;
            ok = 0;
        }
        ++i;
    }
    i = 0;
    ind = 1;
    j = poz[ind];
    while (i < n) {
        if (i == j) {
            for (int p = i; p < i + lmax; ++p)
                w[p] = s[i + lmax + i - p - 1];
            i = i + lmax - 1;
            ++ind;
            j = poz[ind];
        }
        else
            w[i] = s[i];
        ++i;
    }
    --n;
    w[n] = 0;
    cout << w;
    return 0;
}
