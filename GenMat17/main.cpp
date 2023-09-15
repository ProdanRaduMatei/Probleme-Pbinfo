#include <iostream>

using namespace std;

int main()
{
    long long a[102][102];
    long long n, x = 1, y = 2;
    cin >> n;
    for (int i = 1; i <= 2 * n; ++i) {
        if (i % 2 == 1) {
            for (int j = 1; j <= 2 * n; ++j) {
                a[i][j] = x;
                x = x + 2;
            }
        }
        else {
            for (int j = 2 * n; j >= 1; --j) {
                a[i][j] = y;
                y = y + 2;
            }
        }
    }
    for (int i = 1; i <= n * 2; ++i) {
        for (int j = 1; j <= n * 2; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}
