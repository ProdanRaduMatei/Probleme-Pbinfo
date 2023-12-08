//simple c++ program to print hello world
#include <iostream>

using namespace std;

bool prim(int x)
{
    if (x < 2) 
        return false;
    if (x == 2)
        return true;
    if (x % 2 == 0)
        return false;
    for (int d = 3; d * d <= x; d += 2)
        if (x % d == 0)
            return false;
    return true;
}

int main()
{
    int n, x, d, dmin = 1000000001, minn = 1000000001, y;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> y;
        if (prim(y)) {
            d = abs(x - y);
            if (d <= dmin) {
                if (d < dmin) {
                    dmin = d;
                    minn = y;
                }
                else if (y < minn)
                    minn = y;
            }
        }
    }
    cout << minn;
    return 0;
}