#include <iostream>

using namespace std;

int i_prim(long long n) {
    long long p1, p2;
    bool k1 = 0, k2 = 0, c1;
    if (n % 2 == 0) {
        p1 = n - 1;
        p2 = n + 1;
    }
    else {
        p1 = n;
        p2 = n;
    }
    while (k1 == 0) {
        c1 = 1;
        for (int d = 3; d * d <= p1; d = d + 2)
            if (p1 % d == 0)
            c1 = 0;
        if (c1 == 1)
            k1 = 1;
        else
            p1 = p1 - 2;
    }
    while (k2 == 0) {
        c1 = 1;
        for (int d = 3; d * d <= p1; d = d + 2)
            if (p2 % d == 0)
            c1 = 0;
        if (c1 == 1)
            k2 = 1;
        else
            p2 = p2 + 2;
    }
    return p2 - p1;
}

int main()
{
    long long n;
    cin >> n;
    cout << i_prim(n);
    return 0;
}
