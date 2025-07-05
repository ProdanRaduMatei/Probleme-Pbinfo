#include <iostream>

using namespace std;

void Impare(int &n) {
    int m = 0, p = 1;
    while (n) {
        if ((n % 10) % 2 == 1) {
            m = m + (n % 10 - 1) * p;
            p = p * 10;
        }
        else {
            m = m + n % 10 * p;
            p = p * 10;
        }
        n = n / 10;
    }
    n = m;
}

int main()
{
    int n;
    cin >> n;
    Impare(n);
    cout << n;
    return 0;
}
