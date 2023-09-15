#include <iostream>

using namespace std;

int main() {
    int n, k, i, ok = 1, d;
    cin >> n >> k;
    for (i = 0; ok == 1; ++i) {
        if (k * i >= n )
            ok = 0;
    }
    if (n - k * (i - 2) <= n - k * (i - 1)) {
        d = k * (i - 2);
    cout << d;
    }
    else {
        d = k * (i - 1);
    cout << d;
    }
    return 0;
}
