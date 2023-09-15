#include <iostream>

using namespace std;

int sum_div(long long n) {
    int s = 0;
    for (int d = 1; d * d <= n; ++d)
        if (n % d == 0) {
            if (d * d == n)
                s = s + d;
            else
                s = s + d + n / d;
        }
    return s;
}

int main()
{
    long long n;
    cin >> n;
    cout << sum_div(n);
    return 0;
}
