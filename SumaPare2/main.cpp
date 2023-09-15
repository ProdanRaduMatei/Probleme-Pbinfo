#include <iostream>

using namespace std;

int main()
{
    int n, m, i, j, s = 0, a;
    cin >> n >> m;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= m; ++j) {
            cin >> a;
            if (a % 2 == 0)
                s = s + a;
        }
    }
    cout << s;
    return 0;
}
