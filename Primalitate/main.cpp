#include <iostream>

using namespace std;

int prim(long long n) {
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    for (int d = 3; d * d <= n; d = d + 2)
        if (n % d == 0)
            return 0;
    return 1;
}

int main()
{
    long long n;
    cin >> n;
    cout << prim(n);
    return 0;
}
