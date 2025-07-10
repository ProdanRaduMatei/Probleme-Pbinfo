#include <iostream>

using namespace std;

long long inv(long long x) {
    long long y = 0, c = x;
    while (c) {
        y = y * 10 + c % 10;
        c = c / 10;
    }
    if (x == y)
        return 1;
    else
        return 0;
}

int main()
{
    long long x, i, m = 0;
    int c = 0;
    do {
        cin >> x;
        if (x != 0) {
            if (inv(x) == 1) {
                if (x == m)
                    ++c;
                else if (m < x) {
                    m = x;
                    c = 1;
                }
            }
        }
    } while (x != 0);
    cout << m << " " << c;
    return 0;
}
