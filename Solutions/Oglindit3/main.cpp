#include <iostream>

using namespace std;

int main()
{
    long long n;
    int s = 0, o = 0;
    cin >> n;
    while (n) {
        s = s + n % 10;
        n = n / 10;
    }
    while (s) {
        o = o * 10 + s % 10;
        s = s / 10;
    }
    cout << o;
    return 0;
}
