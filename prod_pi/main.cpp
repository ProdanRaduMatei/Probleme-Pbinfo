#include <iostream>

using namespace std;

int main()
{
    long long n;
    int m = 10, M = -1, u;
    cin >> n;
    while (n) {
        u = n % 10;
        if (u % 2 == 0) {
            if (u > M)
                M = u;
        }
        else {
            if (u < m)
                m = u;
        }
        n = n / 10;
    }
    cout << m * M;
    return 0;
}
