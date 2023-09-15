#include <iostream>

using namespace std;

bool prim(int x) {
    if (x < 2)
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

int sumcif(int x) {
    int s = 0;
    while (x) {
        s = s + x % 10;
        x = x / 10;
    }
    return s;
}

int main()
{
    int n, c = 0;
    int x;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (prim(x) == 1 && prim(sumcif(x)) == 1)
            ++c;
    }
    cout << c;
    return 0;
}
