#include <iostream>

using namespace std;

int main() {
    int n, x, para = 0, impara = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (x == 0)
            ++para;
        while (x) {
            if ((x % 10) % 2 == 0)
                ++para;
            else
                ++impara;
            x = x / 10;
        }
    }
    cout << para << " " << impara;
    return 0;
}