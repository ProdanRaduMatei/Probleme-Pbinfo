#include <iostream>

using namespace std;

int n, m, s[10];

void afis() {
    for (int i = 1; i <= n; ++i)
        cout << s[i];
    cout << endl;
}

int valid(int k) {
    if (k == 1 && s[k] == 0)
        return 0;
    else if (k > 1)
        if (s[k] - s[k - 1] < 2 && s[k] - s[k - 1] > -2)
            return 0;
    return 1;
}

void bt(int k) {
    for (int i = 0; i < m; ++i) {
        s[k] = i;
        if (valid(k))
            if (k == n)
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
