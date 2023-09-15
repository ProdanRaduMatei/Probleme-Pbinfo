#include <iostream>

using namespace std;

int main() {
    long long n, c, r;
    cin >> n >> c >> r;
    if (n % c == r)
        cout << n + c;
    else
        cout << (n / c + 1) * c + r;
    return 0;
}
