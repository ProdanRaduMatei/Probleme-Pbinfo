#include <iostream>

using namespace std;

int main()
{
    int c, n, i, j, cnt;
    cin >> c >> n;
    if (c == 1) {
        for (i = 1; i <= n; ++i) {
            for (j = 1; j <= n; ++j) {
                cout << i;
            }
            cout << endl;
        }
    }
    if (c == 3) {
        for (i = 1; i <= n; ++i) {
            for (j = 1; j <= 2 * n; ++j) {
                cout << i;
            }
            cout << endl;
        }
    }
    if (c == 2) {
        for(i = 1; i <= n; ++i) {
            for (j = 1; j <= n; ++j) {
                if (j >= n - i + 1)
                    cout << i;
                else
                    cout << " ";
            }
            for (cnt = 1; cnt < i; ++cnt)
                cout << i;
            cout << endl;
        }
    }
    if (c == 4) {
        for(i = 1; i <= n; ++i) {
            for (j = 1; j <= n; ++j) {
                if (j >= n - i + 1)
                    cout << i;
                else
                    cout << " ";
            }
            for (cnt = 1; cnt < i; ++cnt)
                cout << i;
            cout << endl;
        }
        for (i = n - 1; i >= 1; --i) {
            for (j = 1; j <= n; ++j) {
                if (j >= n - i + 1)
                    cout << i;
                else
                    cout << " ";
            }
            for (cnt = 1; cnt < i; ++cnt)
                cout << i;
            cout << endl;
        }
    }
    return 0;
}
