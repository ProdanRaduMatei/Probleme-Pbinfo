#include <iostream>
#include <algorithm>

using namespace std;

long long x;
int n, v[11], s[11];

void afis() {
    for (int i = 1; i <= n; ++i)
        cout << s[i];
    cout << endl;
}

bool valid(int k) {
    for (int i = 1; i < k; ++i)
        if (s[k] == s[i])
            return 0;
    return 1;
}

void bt(int k) {
    for (int i = 1; i <= n; ++i) {
        s[k] = v[i];
        if (valid(k))
            if (k == n)
                afis();
            else
                bt(k + 1);
    }
}

int main()
{
    cin >> x;
    while (x) {
        v[++n] = x % 10;
        x = x / 10;
    }
    sort(v + 1, v + 1 + n);
    bt(1);
    return 0;
}
