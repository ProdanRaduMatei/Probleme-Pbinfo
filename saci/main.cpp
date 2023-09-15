#include <iostream>

using namespace std;

int main()
{
    int n, c = 0, a, b, x;
    bool ok = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        ok = 0;
        b = x % 10;
        x = x / 10;
        while (x > 0 && ok == 0) {
            a = x % 10;
            if (a >= b)
                ok= 1;
            b = a;
            x = x / 10;
        }
        if (ok == 0)
            ++c;
    }
    cout << c;
    return 0;
}
