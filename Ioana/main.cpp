#include <iostream>

using namespace std;

int sumcif(int x) {
    int s = 0;
    while (x) {
        s = s + x % 10;
        x = x / 10;
    }
    return s;
}

int main()
{
    int n, x, s = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        s = s + x;
    }
    while (s >= 10)
        s = sumcif(s);
    cout << 50 - s;
    return 0;
}
