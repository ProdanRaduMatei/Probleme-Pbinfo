#include <iostream>

using namespace std;

int main()
{
    int n;
    double v[52][51];
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> v[i][j];
    for (int i = 1; i <= n; ++i)
        v[0][i] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            v[0][j] = v[0][j] + v[i][j];
    ++n;
    for (int i = n; i > (n - 1) / 2 + 1; --i)
        for (int j = 1; j < n; ++j)
            v[i][j] = v[i - 1][j];
    for (int j = 1; j < n; ++j)
        v[(n - 1) / 2 + 1][j] =(double) v[0][j] / (n - 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < n; ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
