#include <iostream>

using namespace std;

int main() {
    long long n, s = 0;
    cin >> n;
    while (n)
    {
        if (n % 10 >= 3 && n % 10 <= 7)
            s = s + n % 10;
        n = n / 10;
    }
    cout << s;
    return 0;
}
