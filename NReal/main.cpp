#include <iostream>

using namespace std;

double nreal(int x, int y) {
    int p = 1, c;
    double a, b;
    a=(double)x;
    c = y;
    while (c) {
        c = c / 10;
        p = p * 10;
    }
    b=(double)((double)y/p);
    return a + b;
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << nreal(x, y);
    return 0;
}
