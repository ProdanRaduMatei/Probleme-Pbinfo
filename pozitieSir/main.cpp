#include <iostream>

using namespace std;

int main()
{
    int n, x, a, c = 0, g = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        if (a > x)
            ++c;
        else if (x == a) {
            g = 1;
            ++c;
        }
    }
    if (g == 1)
        cout << c;
    else
        cout << -1;
    return 0;
}
