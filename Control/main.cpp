#include <iostream>

using namespace std;

int s(long long n) {
    int S = 0;
    if (n < 10)
        return n;
    while (n) {
        S = S + n % 10;
        n = n / 10;
    }
    return s(S);
}

int main()
{
    long long n;
    cin >> n;
    cout << s(n);
    return 0;
}
