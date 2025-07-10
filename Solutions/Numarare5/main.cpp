#include <iostream>

using namespace std;

int main()
{
    int n, cnt = 0;
    long long v[201], s[201] = {0};
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        while (v[i]) {
            s[i] = s[i] + v[i] % 10;
            v[i] = v[i] / 10;
        }
    }
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (s[i] == s[j])
                ++cnt;
    cout << cnt;
    return 0;
}
