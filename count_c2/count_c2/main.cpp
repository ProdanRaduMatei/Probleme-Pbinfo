#include <iostream>

using namespace std;

int main() {
    int n, x, c = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        if (x < 100 && x > 10)
            ++c;
    }
    cout << c;
    return 0;
}
