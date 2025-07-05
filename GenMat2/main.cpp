#include <iostream>

using namespace std;

int main()
{
    int n, v[25][25];
    cin >> n;
    for (int j = 1; j <= n; ++j)
        for (int i = 1; i <= n; ++i)
            v[i][j] = n - j + 1;
    for (int i = 1; i <= n; ++i)
        v[i][i] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}
