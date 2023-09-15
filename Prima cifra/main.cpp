#include <iostream>

using namespace std;

int main()
{
    int n, s = 0;
    long long x;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        while (x >= 10)
            x = x / 10;
        s = s + x;
    }
    cout << s;
    return 0;
}
