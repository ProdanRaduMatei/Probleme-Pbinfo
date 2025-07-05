#include <iostream>

using namespace std;

void prefix(int n, int k, int &x) {
    int m = n, c = 0, d;
    while (m) {
        m = m / 10;
        ++c;
    }
    d = c - k;
    while (d) {
        n = n / 10;
        --d;
    }
    x = n;
}

int main()
{
    int n, k, x;
    cin >> n >> k;
    prefix(n, k, x);
    cout << x;
    return 0;
}
