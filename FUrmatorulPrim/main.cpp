#include <iostream>

using namespace std;

int nr_prim(int n) {
    int m;
    if (n <= 1)
        return 2;
    if (n % 2 == 0)
        m = n + 1;
    else
        m = n + 2;
    bool k = 0;
    while (k == 0) {
        k = 1;
        for (int d = 3; d * d <= m; d = d + 2)
            if (m % d == 0)
                k = 0;
        ++m;
    }
    return m - 1;
}

int main()
{
    int n;
    cin >> n;
    cout << nr_prim(n);
    return 0;
}
