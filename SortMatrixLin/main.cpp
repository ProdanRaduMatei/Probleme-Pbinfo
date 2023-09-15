#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, v[10201];
    char c;
    cin >> n >> m >> c;
    for (int i = 1; i <= n * m; ++i)
        cin >> v[i];
    sort(v + 1, v + 1 + n * m);
    if (c == '+') {
        for (int i = 1; i <= n * m; ++i) {
            cout << v[i] << " ";
            if (i % m == 0)
                cout << endl;
        }
    }
    else {
        for (int i = n * m; i >= 1; --i) {
            cout << v[i] << " ";
            if (((n * m) - i + 1) % m == 0)
                cout << endl;
        }
    }
    return 0;
}
