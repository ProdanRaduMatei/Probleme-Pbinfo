#include <iostream>

using namespace std;

int main()
{
    int n, a[102][102] = {0}, c = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            a[i][0] = a[i][0] + a[i][j];
            a[0][j] = a[0][j] + a[i][j];
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (a[i][0] == a[0][j])
                ++c;
    cout << c;
    return 0;
}
