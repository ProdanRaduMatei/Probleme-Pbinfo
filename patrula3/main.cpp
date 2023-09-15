#include <iostream>

using namespace std;

int main()
{
    int n, x, y, z, a, b, c;
    cin >> n;
    x = n - 1;
    y = n - 3;
    z = n - 5;
    a = x;
    b = y;
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    c = x * y / a;
    a = c;
    b = z;
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    c = c * z / a;
    cout << c / x << " " << c / y << " " << c / z;
    return 0;
}
