#include <iostream>

using namespace std;

int main()
{
    int n, v[101][101], a[101];
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int j = 2; j <= n; j = j + 2)
        for (int i = 1; i <= n; ++i)
            v[i][j] = a[i];
    for (int j = 1; j <= n; j = j + 2)
        for (int i = 1; i <= n; ++i)
            v[i][j] = a[n - i + 1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}
