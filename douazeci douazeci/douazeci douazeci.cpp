#include <iostream>

using namespace std;

int main() {
    int n, x, s = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (2020 % x == 0)
            s = s * x;
    }
    if (s % 2020 == 0)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
