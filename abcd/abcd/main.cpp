#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, m, n, p, q;
    cin >> a >> b >> c >> d;
    m = (a - 1) / 3;
    n = b / 3;
    p = (c - 1) / 3;
    q = d / 3;
    cout << n - m + q - p;
    return 0;
}
