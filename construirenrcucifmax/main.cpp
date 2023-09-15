#include <iostream>

using namespace std;

int main()
{
    int n, m = 0;
    long long s = 0, x;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        m = 0;
        while (x) {
            if (x % 10 > m)
                m = x % 10;
            x = x / 10;
        }
        s = s * 10 + m;
    }
    cout << s * s;
    return 0;
}
