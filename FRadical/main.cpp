#include <iostream>
#include <cmath>

using namespace std;

void FRadical(int n, int &x, int &y) {
    int m;
    x = sqrt(n);
    if (x * x == n)
        y = 1;
    else {
        m = x * x;
        while (n % m) {
            --x;
            m = x * x;
            if (n % m == 0)
                y = n / m;
        }
    }
}

int main()
{
    int n, x, y;
    cin >> n;
    FRadical(n, x, y);
    cout << x << " " << y;
    return 0;
}
