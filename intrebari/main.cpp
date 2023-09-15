#include <iostream>

using namespace std;

long long sumacif(long long x) {
    int s = 0;
    while (x) {
        s = s + x % 10;
        x = x / 10;
    }
    return s;
}

long long cautmin(long long V[11], int p) {
    long long m = 1000000000;
    for (int i = 1; i <= p; ++i)
        if (V[i] < m)
            m = V[i];
    return m;
}

int nrdiv(long long x) {
    int cnt = 0;
    for (int i = 1; i * i <= x; ++i)
        if (x % i == 0)
            if (i * i == x)
                ++cnt;
            else
                cnt = cnt + 2;
    return cnt;
}

long long cautmax(long long V[11], int p) {
    long long m = 0;
    for (int i = 1; i <= p; ++i)
        if (V[i] > m)
            m = V[i];
    return m;
}

int main()
{
    int n, p, t;
    long long V[11], S = 0;
    cin >> n >> t >> p;
    for (int i = 1; i <= n; ++i) {
        cin >> V[i];
        S = S + V[i];
    }
    if (t == 1)
        cout << sumacif(cautmin(V, p));
    else
        cout << nrdiv(cautmax(V, p));
    cout << endl << S;
    return 0;
}
