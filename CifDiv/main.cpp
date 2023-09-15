#include <iostream>

using namespace std;

int main() {
    int n, m, cnt = 0, uc;
    cin >> n >> m;
    while (n != 0) {
        uc = n % 10;
        if (uc != 0)
            if (m % uc == 0)
                ++cnt;
        n = n / 10;
    }
    cout << cnt;
    return 0;
}
