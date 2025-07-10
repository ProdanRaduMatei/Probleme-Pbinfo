#include <iostream>

using namespace std;

int main()
{
    int n, v[17], p;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= n; ++i)
        cout << v[i] << " ";
    cout << "\n";
    for (int k = 1; k < n; ++k) {
        p = v[1];
        for (int j = 1; j < n; ++j)
            v[j] = v[j + 1];
        v[n] = p;
        for (int i = 1; i <= n; ++i)
            cout << v[i] << " ";
        cout << "\n";
    }
    return 0;
}
