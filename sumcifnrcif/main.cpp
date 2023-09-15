#include <iostream>

using namespace std;

int main()
{
    long long n, s = 0, c = 0;
    cin >> n;
    while (n) {
        s = s + n % 10;
        n = n / 10;
    }
    while (s) {
        c = c + 1;
        s = s / 10;
    }
    cout << c;
    return 0;
}
