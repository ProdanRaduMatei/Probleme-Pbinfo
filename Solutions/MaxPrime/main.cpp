#include <iostream>

using namespace std;

void sub(int n, int &a, int &b) {
    if (n % 2 == 0)
        a = n - 1;
    else
        a = n - 2;
    b = 0;
    bool k = 0;
    while (k == 0) {
        k = 1;
        for (int d = 3; d * d <= a; d = d + 2)
            if (a % d == 0) {
                a = a - 2;
                d = 3;
            }

    }
    k = 0;
    b = a - 2;
    while (k == 0) {
        k = 1;
        for (int d = 3; d * d <= b; d = d + 2)
            if (b % d == 0) {
                b = b - 2;
                d = 3;
            }
    }
    if (a == 3)
        b = 2;
}

int main()
{
    int n, a, b;
    cin >> a;
    sub(n, a, b);
    cout << a << " " << b;
    return 0;
}
