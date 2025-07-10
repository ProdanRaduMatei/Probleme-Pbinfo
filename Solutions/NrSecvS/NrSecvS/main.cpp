#include <iostream>

using namespace std;

long long NrSecvS(long long a[], long long n, long long s)
{
    long long S[10000000] = {0}, c = 0;
    for (long long i = 1; i <= n; ++i)
        S[i] = S[i - 1] + a[i];
    for (long long k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            if (i + k <= n && S[i + k] - S[i - 1] > s)
                ++c;
    return c;
}

int main() {
    long long a[10000001], n, s = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> s;
    cout << NrSecvS(a, n, s);
    return 0;
}
