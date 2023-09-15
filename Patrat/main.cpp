#include <iostream>

using namespace std;

int main() {
    int n, i, j;
    char a, b;
    cin >> n >> a >> b;
    for (i = 1; i <= n; ++i)
        cout << a;
    cout << endl;
    for (i = 2; i < n; ++i) {
        cout << a;
        for (j = 2; j < n; ++j) {
            cout << b;
        }
        cout << a << endl;
    }
    for (i = 1; i <= n; ++i)
        cout << a;
    cout << endl;
    return 0;
}
