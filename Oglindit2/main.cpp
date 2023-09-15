#include <iostream>

using namespace std;

int oglindit(long long n) {
    long long m = 0;
    while (n) {
        m = m * 10 + n % 10;
        n = n / 10;
    }
    return m;
}

int main()
{
    long long n;
    cin >> n;
    cout << oglindit(n);
    return 0;
}
