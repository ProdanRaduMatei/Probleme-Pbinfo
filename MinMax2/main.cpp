#include <iostream>

using namespace std;

int main() {
    int a, b, Ma = 0, ma = 9, Mb = 0, mb = 9, uc, n, m, ka = 0, kb = 0;
    cin >> a >> b;
    while (a > 0) {
        uc = a % 10;
        if (uc > Ma) {
                Ma  = uc;
                if (Ma < ma)
                    ma = Ma;
        }
        else if (uc < ma) {
            if (uc != 0)
                ma = uc;
            else
                ka = 1;
        }
        a = a / 10;
        }
    while (b > 0) {
        uc = b % 10;
        if (uc > Mb) {
            Mb  = uc;
            if (Mb < mb)
                mb = Mb;
        }
        else if (uc < mb) {
            if (uc != 0)
                mb = uc;
            else
                kb =1;
        }
        b = b / 10;
    }
    if (Ma > Mb)
        n = Ma * 10 + Mb;
    else
        n = Mb * 10 + Ma;
    if (ma < mb) {
        if (kb == 1)
            m = ma * 10;
        else
            m = ma * 10 + mb;
    }
    else {
        if (ka == 1)
            m = mb * 10;
        else
            m = mb * 10 + ma;
    }
    cout << n << " " << m;
return 0;
}
