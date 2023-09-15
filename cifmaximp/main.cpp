#include <iostream>

using namespace std;

int main()
{
    int n, x, f[10], c = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        for (int j = 0; j <= 9; ++j)
            f[j] = 0;
        if (x == 0)
            f[0] = 1;
        while (x) {
            ++f[x % 10];
            x = x / 10;
        }
        int j = 9;
        while (f[j] == 0 && j > 0)
            --j;
        if (j % 2 == 1)
            ++c;
    }
    cout << c;
    return 0;
}
