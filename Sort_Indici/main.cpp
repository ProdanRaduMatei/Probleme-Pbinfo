#include <iostream>

using namespace std;

int main()
{
    int n, v[101], c[101];
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        c[i] = i;
    }
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j) {
            if (v[i] > v[j]) {
                swap (v[i], v[j]);
                swap (c[i], c[j]);
            }
            else if (v[i] == v[j] && c[i] > c[j])
                swap (c[i], c[j]);
        }
    for (int i = 1; i <= n; ++i)
        cout << v[i] << " " << c[i] << " ";
    return 0;
}
