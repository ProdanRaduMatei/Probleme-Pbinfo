#include <iostream>

using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;
    if (x > y)
        swap(x, y);
    if (2 * x > y)
        cout << (x / (y - x) + 1) * (y - x) - x;
    else {
        long long d = y - x;
        long long minn = d;
        for (int i = 2; i * i <= d; i++)
            if (d % i == 0) {
                if (i >= x and i < minn)
                    minn = i;
                if (d / i >= x and d / i < minn)
                    minn = d / i;
            }
        cout << minn - x;
    }
}