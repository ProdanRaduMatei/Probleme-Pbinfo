#include <iostream>

using namespace std;

int main()
{
    int n, a, b, v[25][25];
    cin >> n >> b >> a;
    for (int i = 1; i <= n; ++i)
        v[i][a] = 0;
    for (int j = 1; j <= n; ++j)
        v[b][j] = 0;
    for (int i = 1; i < b; ++i)
        for (int j = 1; j < a; ++j)
            v[i][j] = 1;
    for (int i = 1; i < b; ++i)
        for (int j = a + 1; j <= n; ++j)
            v[i][j] = 2;
    for (int i = b + 1; i <= n; ++i)
        for (int j = 1; j < a; ++j)
        v[i][j] = 3;
    for (int i = b + 1; i <= n; ++i)
        for (int j = a + 1; j <= n; ++j)
            v[i][j] = 4;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}
