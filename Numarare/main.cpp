#include <iostream>

using namespace std;

int main()
{
    int n, cn = 0;
    long long c[101], s[101] = {0}, x;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        x = c[i];
        while (x) {
            s[i] = s[i] + x % 10;
            x = x / 10;
        }
    }
    for (int i = 1; i < n; ++i)
        if (s[i] == s[i + 1])
            ++cn;
    cout << cn;
    return 0;
}
