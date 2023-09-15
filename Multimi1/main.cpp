#include <iostream>

using namespace std;

int main()
{
    int n, m, v[100000], w[100000], i, j;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    cin >> m;
    for (int j = 1; j <= m; ++j)
        cin >> w[j];
    i = 1;
    j = 1;
    while (i <= n && j <= m) {
        if (v[i] < w[j]) {
            cout << v[i] << " ";
            ++i;
        }
        else if (v[i] > w[j]) {
            cout << w[j] << " ";
            ++j;
        }
        else if (v[i] == w[j]) {
            cout << v[i] << " ";
            ++i;
            ++j;
        }
    }
    while (i <= n) {
        cout << v[i] << " ";
        ++i;
    }
    while (j <= m) {
        cout << w[j] << " ";
        ++j;
    }
    cout << endl;
    i = 1;
    j = 1;
    while (i <= n && j <= m) {
        if (v[i] < w[j])
            ++i;
        else if (v[i] > w[j])
            ++j;
        else if (v[i] == w[j]) {
            cout << v[i] << " ";
            ++i;
            ++j;
        }
    }
    return 0;
}
