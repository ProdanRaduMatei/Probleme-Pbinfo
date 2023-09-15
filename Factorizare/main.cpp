#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int d = 2;
    while (n > 1) {
        int p = 0;
        while (n % d == 0) {
            ++p;
            n = n / d;
        }
        if (p != 0)
            cout << d << " " << p << endl;
        ++d;
        if (d * d > n)
            d = n;
    }
    return 0;
}
