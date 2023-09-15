#include <iostream>

using namespace std;

int main()
{
    long long n, m = 0, p = 1;
    int c;
    cin >> n >> c;
    while (n) {
        if (n % 10 != c) {
            m = m + n % 10 * p;
            p = p * 10;
        }
        n = n / 10;
    }
    cout << m;
    return 0;
}
