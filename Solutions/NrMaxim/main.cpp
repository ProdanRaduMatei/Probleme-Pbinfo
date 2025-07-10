#include <iostream>

using namespace std;

int nrmaxim(long long n) {
    int cm = 0, cnt = 0, cnm, p = 1, p1, p2, m, c;
    c = n;
    while (c) {
        ++cnt;
        if (c % 10 > cm) {
            cm = c % 10;
            cnm = cnt;
        }
        c = c / 10;
    }
    c = cnm;
    while (c) {
        p = p * 10;
        --c;
    }
    p1 = n % p;
    p2 = (n - p1) / p;
    cm = cnt - cnm;
    p = 1;
    while (cm) {
        p = p * 10;
        cm--;
    }
    m = p * p1 + p2;
    return m;
}

int main()
{
    long long n;
    cin >> n;
    cout << nrmaxim(n);
    return 0;
}
