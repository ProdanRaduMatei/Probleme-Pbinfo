#include <iostream>

using namespace std;

int main()
{
    int n, s = 0, sm = 100, sM = 0;
    long long m, M, x, c;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        c = x;
        s = 0;
        while (c) {
            s = s + c % 10;
            c = c / 10;
        }
        if (s < sm) {
            m = x;
            sm = s;
        }
        if (s > sM) {
            M = x;
            sM = s;
        }
    }
    cout << m << endl << M;
    return 0;
}
