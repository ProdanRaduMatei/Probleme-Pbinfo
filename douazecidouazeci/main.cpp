#include <iostream>

using namespace std;

int main()
{
    int n, v[101];
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j)
            if (v[i] * v[j] == 2020) {
                cout << "DA";
                return 0;
            }
    }
    cout << "NU";
    return 0;
}
