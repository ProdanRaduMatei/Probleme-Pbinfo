#include <iostream>

using namespace std;

void P(int &n, int c) {
    int m = 0, p = 1;
    while (n) {
        if (n % 10 != c) {
            m = m + p * (n % 10);
            p = p * 10;
        }
        n = n / 10;
    }
    n = m;
}

int main()
{
    int n, c;
    cin >> n >> c;
    P(n, c);
    cout << n;
    return 0;
}
