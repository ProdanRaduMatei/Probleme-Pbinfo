#include <iostream>

using namespace std;

int main()
{
    int n, v[201], y[201], s = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        s = s + v[i];
    }
    for (int i = 1; i <= n; ++i) {
        y[i] = s - v[i];
        cout << y[i] << " ";
    }
    return 0;
}
