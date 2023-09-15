#include <iostream>

using namespace std;

int main()
{
    int b, n, a, m = 0, d, c;
    cin >> b >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        d = n - i - 1;
        c = 1;
        while (d >  0) {
            c =c * b;
            --d;
        }
        m = m + c * a;
    }
    cout << m;
    return 0;
}
