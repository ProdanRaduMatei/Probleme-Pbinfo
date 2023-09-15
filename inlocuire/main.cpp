#include <iostream>

using namespace std;

int main()
{
    int n, v[201], s = 0, c = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        if (v[i] != 0) {
            s = s + v[i];
            ++c;
        }
    }
    s = s / c;
    for (int i = 1; i <= n; ++i) {
        if (v[i] == 0)
            v[i] = s;
        cout << v[i] << " ";
    }
    return 0;
}
