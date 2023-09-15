#include <iostream>

using namespace std;

int main()
{
    int n, v[101][101];
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> v[i][j];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < n; ++j)
            for (int k = j + 1; k <= n; ++k)
                if (v[i][j] > v[i][k])
                    swap(v[i][j], v[i][k]);
    }
    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i < n; ++i)
            for (int k = i + 1; k <= n; ++k)
                if (v[i][j] > v[k][j])
                    swap(v[i][j], v[k][j]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}
