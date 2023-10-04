#include <bits/stdc++.h>

#define M 1000000007
#define S 1000001

using namespace std;

int F[S];

int main() {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    long long int Scnt = 0, sol = 0;
    for (int p2 = 20; p2 >= 0; --p2) {
        long long int Sum = 0, cnt = 0;
        ++F[0];
        for (int i = 1; i <= n; ++i) {
            Sum += a[i];
            cnt += F[Sum % (1 << p2)];
            ++F[Sum % (1 << p2)];
        }
        cnt -= Scnt;
        Scnt += cnt;
        cnt %= M;
        sol += 1LL * (1 << p2) * cnt % M;
        sol %= M;
        Sum = 0;
        F[0] = 0;
        for (int i = 1; i <= n; ++i) {
            Sum += a[i];
            F[Sum % (1 << p2)] = 0;
        }
    }
    cout << sol << '\n';
    return 0;
}