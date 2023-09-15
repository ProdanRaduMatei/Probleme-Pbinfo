#include <iostream>

using namespace std;

int main()
{
    int n, x, y, val, v, i;
    cin >> n >> x >> y >> val;
    cout << (x - 1) * n + y;
    i = val / n;
    if (val % n == 0)
        cout << " " << i << " " << n;
    else
        cout << " " << i + 1 << " " << val % n;
    return 0;
}
