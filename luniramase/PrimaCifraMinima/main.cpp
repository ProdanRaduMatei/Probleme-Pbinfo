#include <iostream>

using namespace std;

int main()
{
    int n, a, M = 9, x, c, u;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        if (a == 0) {
            M = 0;
            x = 0;
        }
        c = a;
        while (c) {
            u = c % 10;
            c = c / 10;
        }
        if (u == M)
            if (x < a)
                x = a;
        if (u < M) {
            M = u;
            x = a;
        }
    }
    cout << x;
    return 0;
}
