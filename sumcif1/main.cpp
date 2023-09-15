#include <iostream>

using namespace std;

int main()
{
    long long n;
    int c = 0, s = 0;
    cin >> n;
    while (n) {
        ++c;
        if (c % 2 == 0)
            s = s + n % 10;
        n = n / 10;
    }
    cout << s;
    return 0;
}
