#include <iostream>

using namespace std;

int main()
{
    long long n;
    int m = 9, M = -1;
    cin >> n;
    while (n) {
        int u = n % 10;
        if (u < m)
            m = u;
        if (u > M)
            M = u;
        n = n / 10;
    }
    cout << M << " " << m << endl;
    cout << M + m;
    return 0;
}
