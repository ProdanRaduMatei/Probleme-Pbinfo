#include <iostream>

using namespace std;

int main()
{
    int n, v[101], cn = 0, a, b, c;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= n - 2; ++i) {
        a = v[i];
        for (int j = i + 1; j < n; ++j) {
            b = v[j];
            for (int k = j + 1; k <= n; ++k) {
                c = v[k];
                if (a + b > c && a + c > b && b + c > a)
                    ++cn;
            }
        }
    }
    cout << cn;
    return 0;
}
