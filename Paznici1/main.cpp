#include <iostream>

using namespace std;

int main()
{
    long long m, n, p, a, b;
    cin >> n >> m;
    a = n / 2 + n % 2;
    b = m / 2 + m % 2;
    p = a * b;
    cout << p;
    return 0;
}
