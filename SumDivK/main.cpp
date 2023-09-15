#include <iostream>

using namespace std;

int main()
{
    int n, k, s = 0, sc = 0, x, c;
    cin >> k >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        c = x;
        sc = 0;
        while (c) {
            sc = sc + c % 10;
            c = c / 10;
        }
        if (sc % k == 0)
            s = s + x;
    }
    cout << s;
    return 0;
}
