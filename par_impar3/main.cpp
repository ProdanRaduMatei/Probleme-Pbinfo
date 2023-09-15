#include <iostream>

using namespace std;

int main()
{
    long long n;
    int m = 9, M = 0;
    cin >> n;
    while (n) {
        if ((n % 10) % 2) {
            if (n % 10 > M)
                M = n % 10;
        }
        else {
            if (n % 10 < m)
                m = n % 10;
        }
        n = n / 10;
    }
    cout << m + M;
    return 0;
}
