#include <iostream>

using namespace std;

void perm(int &n) {
    int p, m = n, c = 1;
    while (m) {
        c = c * 10;
        p = m % 10;
        m = m / 10;
    }
    n = n - p * c / 10;
    n = n * 10 + p;
}

int main()
{
    int n;
    cin >> n;
    perm(n);
    cout << n;
    return 0;
}
