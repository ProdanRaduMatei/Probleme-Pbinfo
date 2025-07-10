#include <iostream>

using namespace std;

int main()
{
    long long n, c0 = 0, c1 = 0;
    cin >> n;
    while (n) {
        if (n % 2 == 0)
            ++c0;
        else
            ++c1;
        n = n / 2;
    }
    cout << c0 << " " << c1;
    return 0;
}
