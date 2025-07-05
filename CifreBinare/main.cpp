#include <iostream>

using namespace std;

int main()
{
    int n, m, cn = 0, cm = 0, ccn, ccm;
    cin >> n >> m;
    ccn = n;
    ccm = m;
    while (n) {
        if (n % 2 == 1)
            ++cn;
        n = n / 2;
    }
    while (m) {
        if (m % 2 == 1)
            ++cm;
        m = m / 2;
    }
    if (cn > cm)
        cout << ccn;
    else if (cn < cm)
        cout << ccm;
    else if (cn == cm) {
        if (ccm < ccn)
            cout << ccm;
        else
            cout << ccn;
    }
    return 0;
}
