#include <iostream>

using namespace std;

int main()
{
    long long int n, m = 0;
    int u;
    cin >> n;
    while (n > 0) {
        u = n % 10;
        m = m * 10 + u;
        n = n / 10;
    }
    cout << m;
    return 0;
}
