#include <iostream>

using namespace std;

int main()
{
    long long a, b, c, d, r;
    cin >> a >> b;
    c = a;
    d = b;
    while (d != 0) {
        r = c % d;
        c = d;
        d = r;
    }
    cout << c << " " << a * b / c;

    return 0;
}
