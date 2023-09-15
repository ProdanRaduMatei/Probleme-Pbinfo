#include <iostream>

using namespace std;

int n, v[20], sum, sm = 20000, s[20];

void sol() {
    sum = 0;
    for (int i = 2; i <= n; i = i + 2)
        sum = sum + s[i - 1] % s[i];
    if (sum < sm)
        sm = sum;
}

int valid(int k) {
    for (int i = 1; i < k; ++i)
        if (s[k] == s[i])
            return 0;
    return 1;
}

void bt(int k) {
    for (int i = 1; i <= n; ++i) {
        s[k] = v[i];
        if (valid(k)) {
            if (k == n)
                sol();
            else
                bt(k + 1);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    bt(1);
    cout << sm;
    return 0;
}
