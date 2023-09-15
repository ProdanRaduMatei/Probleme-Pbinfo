#include <iostream>

using namespace std;

int main() {
    long long n, c, M = 0;
    int m = 10, p = 1, l = 0, v[100];
    cin >> n;
    c = n;
    while (c)
    {
        if (c % 10 < m)
            m = c % 10;
        v[++l] = c % 10;
        c = c / 10;
    }
    for (int i = 1; i <= l; ++i)
    {
        c = 0;
        for (int j = l; j >= 1; --j)
        {
            if (j != i)
                c = c * 10 + v[j];
        }
        if (c > M)
            M = c;
    }
    cout << M;
    return 0;
}
