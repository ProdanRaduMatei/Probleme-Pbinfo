#include <iostream>

using namespace std;

int main()
{
    int n, v[101];
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 2; i < n; ++i) {
        if (v[i - 1] % 2 == 0 && v[i + 1] % 2 == 0 && v[i] % 2 == 0) {
            cout << "DA";
            return 0;
        }
        if (v[i - 1] % 2 == 1 && v[i + 1] % 2 == 1 && v[i] % 2 == 1) {
            cout << "DA";
            return 0;
        }
    }
    cout << "NU";
    return 0;
}
