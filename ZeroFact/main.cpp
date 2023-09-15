#include <iostream>

using namespace std;

int nz(int n) {
    int z = 0, p = 5;
    while (p <= n) {
        z = z + n / p;
        p = p * 5;
    }
    return z;
}

int main()
{
    int n;
    cin >> n;
    cout << nz(n);
    return 0;
}
