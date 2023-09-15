#include <iostream>

using namespace std;

int main()
{
    int b, m = 0;
    long long n;
    cin >> n >> b;
    while (n) {
        if (n % b > m)
            m = n % b;
        n = n / b;
    }
    cout << m;
    return 0;
}
