#include <iostream>

using namespace std;

int n, v[5] = {0, 2, 3, 5, 7}, s[8];

void afis() {
    for (int i = 1; i <= n; ++i)
        cout << s[i];
    cout << endl;
}

void bt(int k) {
    for (int i = 1; i <= 4; ++i) {
        s[k] = v[i];
        if (k == n)
            afis();
        else
            bt(k + 1);
    }
}

int main()
{
    cin >> n;
    bt(1);
    return 0;
}
