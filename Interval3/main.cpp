#include <iostream>

using namespace std;

int main()
{
    int n, i, m, M, v[1000];
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> v[i];
    if (v[1] > v[n]) {
        m = v[n];
        M = v[1];
    }
    else {
        m = v[1];
        M = v[n];
    }
    for (i = 1; i <= n; ++i) {
        if (v[i] > M || v[i] < m) {
            cout << "NU";
            return 0;
        }
    }
    cout << "DA";
    return 0;
}
