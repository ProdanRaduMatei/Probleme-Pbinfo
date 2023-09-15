#include <iostream>

using namespace std;

int main() {
    long long n, c = 0;
    cin >> n;
    while (n > 1)
    {
        n = n / 2;
        ++c;
    }
    cout << c;
    return 0;
}
