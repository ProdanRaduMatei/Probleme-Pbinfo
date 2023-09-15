#include <iostream>

using namespace std;

int prim(int x) {
    if (x <= 1)
        return 0;
    if (x == 2)
        return 1;
    if (x % 2 == 0)
        return 0;
    for (int d = 3; d * d <= x; d = d + 2)
        if (x % d == 0)
            return 0;
    return 1;
}

int main()
{
    int n, x, c = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (prim(x))
            ++c;
    }
    cout << c;
    return 0;
}
