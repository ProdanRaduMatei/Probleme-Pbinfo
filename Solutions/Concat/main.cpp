#include <iostream>

using namespace std;

int concat(long long a, long long b) {
    long long p = 1, c;
    c = b;
    while (c) {
        c = c / 10;
        p = p * 10;
    }
    a = a * p + b;
    return a;
}

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << concat(a, b);
    return 0;
}
