#include <iostream>

using namespace std;

int main()
{
    int n, d, u;
    cin >> n;
    d = n(n - 3)/2;
    if (n > 3)
        u = 360;
    else
        u = 180;
    cout << d << endl << u;
    return 0;
}
