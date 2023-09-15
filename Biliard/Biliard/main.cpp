#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int n = a, m = b;
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    cout << n / a + m / a - 2;
    return 0;
}
