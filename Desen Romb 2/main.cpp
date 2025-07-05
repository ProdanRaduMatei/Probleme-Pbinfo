#include <iostream>

using namespace std;

int main()
{
    int n, i, j, m, cnt, o;
    cin >> n;
    m = 2 * n - 1;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= n; ++j) {
            if (j >= n - i + 1)
                cout << "*";
            else
                cout << "#";
        }
        for (cnt = 1; cnt < i; ++cnt)
            cout << "*";
        o = cnt - 1 + j - 1;
        for (cnt = o; cnt < m; ++cnt)
            cout << "#";
        cout << endl;
    }
    for (i = n - 1; i >= 1; --i) {
        for (j = 1; j <= n; ++j) {
            if (j >= n - i + 1)
                cout << "*";
            else
                cout << "#";
        }
        for (cnt = 1; cnt < i; ++cnt)
            cout << "*";
        o = cnt - 1 + j - 1;
        for (cnt = o; cnt < m; ++cnt)
            cout << "#";
        cout << endl;
    }
    return 0;
}
