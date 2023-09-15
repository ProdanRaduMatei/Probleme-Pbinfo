#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, cnt = 0, m = 0, d;
    cin >> a;
    do {
        cin >> b;
        if (b != 0) {
            d = __gcd(a, b);
            if (d == 1) {
                ++cnt;
                if (cnt > m)
                    m = cnt;
            }
            else if (d != 1)
                cnt = 0;
            swap(a, b);
        }
    } while (b != 0);
    cout << m;
    return 0;
}
