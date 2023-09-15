#include <iostream>

using namespace std;

int NrDiv(int n) {
    int cnt = 0;
    for (int d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            if (d * d == n)
                ++cnt;
            else
                cnt = cnt + 2;
        }
    }
    return cnt;
}

int NextNrDiv(int n) {
    int cn, m = n;
    bool k = 0;
    cn = NrDiv(n);
    while (k == 0) {
        ++m;
        if (NrDiv(m) == cn)
            k = 1;
    }
    return m;
}

int PrevNrDiv(int n) {
    int cn, m = n;
    bool k = 0;
    cn = NrDiv(n);
    while (k == 0 && m >= 0) {
        --m;
        if (NrDiv(m) == cn)
            k = 1;
    }
    if (k == 1)
        return m;
    else
        return -1;
}

int main()
{
    int n;
    cin >> n;
    cout << NrDiv(n) << endl;
    cout << NextNrDiv(n) << endl;
    cout << PrevNrDiv(n) << endl;
    return 0;
}
