#include <iostream>

using namespace std;

void dublare1(int &n) {
    int m = n, p, c = 1;
    while (m) {
        p = m % 10;
        m = m / 10;
        c = c * 10;
    }
    n = n + c * p;
}

int main()
{
    int n;
    cin >> n;
    dublare1(n);
    cout << n;
    return 0;
}
