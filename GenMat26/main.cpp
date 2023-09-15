#include <iostream>

using namespace std;

int main()
{
    int n, v[21], u;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= n; ++i)
        cout << v[i] << " ";
    cout << endl;
    for (int i = 2; i <= n; ++i) {
        u = v[n];
        for (int j = n; j > 1; --j)
            v[j] = v[j - 1];
        v[1] = u;
        for (int j = 1; j <= n; ++j)
            cout << v[j] << " ";
        cout << endl;
    }
    return 0;
}
