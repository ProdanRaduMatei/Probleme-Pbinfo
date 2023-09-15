#include <iostream>

using namespace std;

int n, m, s[21];

void afis() {
    for (int i = 1; i <= m; ++i)
        cout << s[i] << " ";
    cout << endl;
}

int valid(int k) {
    for (int i = 1; i < k; ++i)
        if (s[k] == s[i])
            return 0;
    if (k > 1)
        if (s[k] % 2 == 0 && s[k - 1] % 2 == 0 || s[k] < s[k - 1])
            return 0;
    return 1;
}

void bt(int k) {
    for (int i = 1; i <= n; ++i) {
        s[k] = i;
        if (valid(k))
            if (k == m)
                afis();
            else
                bt(k + 1);
    }
}

int main()
{
    cin >> n >> m;
    bt(1);
    return 0;
}
