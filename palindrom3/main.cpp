#include <bits/stdc++.h>
using namespace std;
string nr;
int cf[11],cmax,od=-1,c,nrod;

bool canFormPalindrome(string str) {
    for (int i = 0; str[i]; ++i) {
        ++cf[str[i] - '0'];
        if (str[i] - '0' > cmax)
            cmax = str[i] - '0';
    }
    int odd = 0;
    for (int i = 0; i < 10; ++i) {
        if (cf[i] & 1) {
            ++odd;
            od = i;
        }
        if (odd > 1)
            return false;
    }
    return true;
}

int main() {
    ifstream f("palindrom3.in");
    f >> nr;
    f.close();
    ofstream g("palindrom3.out");
    if (nr.size() == 1) {
        g << nr;
        return 0;
    }
    if (canFormPalindrome(nr)) {
            for (int i = cmax; i >= 0; --i) {
                if (cf[i])
                    for (int j = 1; j <= cf[i] / 2; ++j)
                        g << i;
                if (i != od)
                    cf[i] /= 2;
                else
                    if (od >= 0)
                        cf[i] = cf[i] / 2 + 1;
            }
            if (od >= 0 && cf[od]) {
                g << od;
                --cf[od];
            }
            for (int i = 0; i <= cmax; ++i)
                if (cf[i])
                    for (int j = 1; j <= cf[i]; ++j)
                        g << i;
    }
    else
        g << 0;
    g.close();
    return 0;
}