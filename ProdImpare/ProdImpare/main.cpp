#include <iostream>

using namespace std;

int main() {
    long long n, p = 1, x = 1;
    cin >> n;
    while (n)
    {
        p = p * x;
        x = x + 2;
        --n;
    }
    cout << p;
    return 0;
}
