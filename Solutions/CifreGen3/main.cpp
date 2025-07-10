#include <iostream>

using namespace std;

int n, m, s[6];

void afis() {
    for (int i = 1; i <= n; ++i)
        cout << s[i];
    cout << endl;
}

int valid(int k) {
    if (k == n)
        if (s[k] != s[1])
            return 0;
    return 1;
}

void bt(int k) {
    for (int i = 0; i < m; ++i) {
        if (k == 1 || k == n) {
            if (i != 0) {
                s[k] = i;
                if (valid(k))
                    if (k == n)
                        afis();
                    else
                        bt(k + 1);
            }
        }
        else {
            s[k] = i;
            bt(k + 1);
        }
    }
}

int main()
{
    cin >> n >> m;
    bt(1);
    return 0;
}
