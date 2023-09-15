#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    for (int d = 2; d * d <= n; ++d)
        while (n % d == 0) {
            cout << d << " ";
            n = n / d;
        }
    if (n != 1)
        cout << n;
    return 0;
}
