#include <iostream>

using namespace std;

int main()
{
    int n, i, j, cnt;
    cin >> n;
    for (i = 1; i <= n; ++i) {
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
    return 0;
}
