#include <iostream>

using namespace std;

int main()
{
    long long n;
    int u = -1;
    cin >> n;
    if (n == 0)
        cout << 0;
    else {
        while (n) {
            if ((n % 10) % 2 == 0)
                u = n % 10;
            n = n / 10;
        }
        cout << u;
    }
    return 0;
}
