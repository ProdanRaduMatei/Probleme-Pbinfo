#include <iostream>

using namespace std;

bool prim(int x) {
    if (x % 2 == 0 && x != 2)
        return 0;
    for (int d = 3; d * d <= x; d = d + 2)
        if (x % d == 0)
            return 0;
    return 1;
}

int mod(int x) {
    if (x < 0)
        return -1 * x;
    return x;
}

int main()
{
    int a, b, m = 1000000000, c, X = 0;
    cin >> a >> b;
    for (int x = a; x <= b; ++x) {
        if (x % 2 == 1 || x == 2)
            if (prim(x) == 1) {
                c = mod(b + a - 2 * x);
                if (c < m) {
                    m = c;
                    X = x;
                }
            }
    }
    if (X == 0)
        cout << "NU EXISTA";
    else
        cout << X;
    return 0;
}
