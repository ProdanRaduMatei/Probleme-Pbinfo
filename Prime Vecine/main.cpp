#include <iostream>

using namespace std;

void sub(int n, int &a, int &b) {
    if (n % 2 == 0) {
        a = n - 1;
        b = n + 1;
    }
    else {
        a = n - 2;
        b = n + 2;
    }
    int k = 0;
    while (k == 0) {
        k = 1;
        for (int d = 3; d * d <= a; d = d + 2)
            if (a % d == 0) {
                a = a - 2;
                d = 1;
            }
    }
    k = 0;
    while (k == 0) {
        k = 1;
        for (int d = 3; d * d <= b; d = d + 2)
            if (b % d == 0) {
                b = b + 2;
                d = 1;
            }
    }
    if (n == 3)
        a = 2;
}

int main()
{
    int n, a, b;
    cin >> n;
    sub(n, a, b);
    cout << a << " " << b;
    return 0;
}
