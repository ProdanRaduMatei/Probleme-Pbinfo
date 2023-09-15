#include <iostream>

using namespace std;

int main()
{
    long long n;
    int a, b;
    cin >> n;
    while (n) {
        a = b;
        b = n % 10;
        n = n / 10;
    }
    cout << a * b;
    return 0;
}
