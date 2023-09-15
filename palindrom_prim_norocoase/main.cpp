#include <iostream>
using namespace std;
int palindrom (long int x) {
    long int z = 0, y;
    y = x;
    while (x != 0) {
        z = z * 10 + x % 10;
        x = x / 10;
    }
    if (z == y)
        return 1;
    else
        return 0;
    }
int prim (int n) {
    if (n == 0 || n == 1)
        return 0;
    else if (n % 2 == 0 && n != 2)
        return 0;
    else
        for (int d = 3; d * d <= n; d = d + 2)
            if (n % d == 0)
                return 0;
    return 1;
}
int norocos (int x) {
    if (x % 2)
        return 1;
    else
        return 0;
}
int main() {
    int n, x, nr = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
    if (palindrom(x) && prim(x) && norocos(x))
        nr++;
    }
    cout << nr;
    return 0;
}
