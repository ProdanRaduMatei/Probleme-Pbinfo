#include <iostream>

using namespace std;

int n, X[200], a, j;

int prim(int x)
{
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
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        if (prim(a) == 1) {
            X[j] = a;
            ++j;
        }
    }
    for (; j >= 0; --j)
        cout << X[j] << " ";
    return 0;
}
